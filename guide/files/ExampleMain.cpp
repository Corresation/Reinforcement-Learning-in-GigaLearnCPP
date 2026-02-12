#include <GigaLearnCPP/Learner.h>
#include <RLGymCPP/Rewards/CommonRewards.h>
#include <RLGymCPP/Rewards/ZeroSumReward.h>
#include <RLGymCPP/TerminalConditions/NoTouchCondition.h>
#include <RLGymCPP/TerminalConditions/GoalScoreCondition.h>
#include <RLGymCPP/ActionParsers/DefaultAction.h>
#include <RLGymCPP/OBSBuilders/DefaultObs.h>
#include <RLGymCPP/OBSBuilders/DefaultObsPadded.h>
#include <RLGymCPP/OBSBuilders/AdvancedObs.h>
#include <RLGymCPP/StateSetters/CombinedState.h>
#include <RLGymCPP/StateSetters/RandomState.h>
#include <RLGymCPP/StateSetters/KickoffState.h>
#include <RLGymCPP/StateSetters/FuzzedKickoffState.h>

using namespace GGL;
using namespace RLGC;

EnvCreateResult EnvCreateFunc(int index)
{
    std::vector<WeightedReward> rewards = {
        { new VelocityPlayerToBallReward(), 1.f },
        { new FaceBallReward(), 0.1f },
        { new TouchBallReward(), 5.f },
        { new AirReward(), 0.085f }
    };

    std::vector<TerminalCondition*> terminalConditions = {
        new NoTouchCondition(10),
        new GoalScoreCondition()
    };

    constexpr int playersPerTeam = 1;
    auto arena = Arena::Create(GameMode::SOCCAR);

    for (int i = 0; i < playersPerTeam; ++i)
    {
        arena->AddCar(Team::BLUE);
        arena->AddCar(Team::ORANGE);
    }

    EnvCreateResult result{};
    result.actionParser = new DefaultAction();
    result.obsBuilder = new AdvancedObs();
    result.stateSetter = new KickoffState();
    result.terminalConditions = terminalConditions;
    result.rewards = rewards;
    result.arena = arena;

    return result;
}

void StepCallback(Learner* learner, const std::vector<GameState>& states, Report& report)
{
    const bool doExpensiveMetrics = (std::rand() % 4) == 0;

    for (const auto& state : states)
    {
        if (doExpensiveMetrics)
        {
            for (const auto& player : state.players)
            {
                report.AddAvg("Player/In Air Ratio", !player.isOnGround);
                report.AddAvg("Player/Ball Touch Ratio", player.ballTouchedStep);
                report.AddAvg("Player/Demoed Ratio", player.isDemoed);
                report.AddAvg("Player/Speed", player.vel.Length());

                const Vec dirToBall = (state.ball.pos - player.pos).Normalized();
                report.AddAvg("Player/Speed Towards Ball", RS_MAX(0, player.vel.Dot(dirToBall)));
                report.AddAvg("Player/Boost", player.boost);

                if (player.ballTouchedStep)
                    report.AddAvg("Player/Touch Height", state.ball.pos.z);
            }
        }

        if (state.goalScored)
            report.AddAvg("Game/Goal Speed", state.ball.vel.Length());
    }
}

int main(int argc, char* argv[])
{
    RocketSim::Init("C:/Users/<username>/path/to/collision_meshes");

    LearnerConfig cfg{};
    cfg.deviceType = LearnerDeviceType::GPU_CUDA;
    cfg.tickSkip = 8;
    cfg.actionDelay = cfg.tickSkip - 1;
    cfg.numGames = 256;

    cfg.ppo.tsPerItr = 50000;
    cfg.ppo.batchSize = 50000;
    cfg.ppo.miniBatchSize = 50000;
    cfg.ppo.epochs = 1;
    cfg.ppo.entropyScale = 0.045f;
    cfg.ppo.gaeGamma = 0.99f;
    cfg.ppo.policyLR = 2e-4f;
    cfg.ppo.criticLR = 2e-4f;

    cfg.ppo.sharedHead.layerSizes = { 512, 512, 512 };
    cfg.ppo.policy.layerSizes = { 512, 512, 512 };
    cfg.ppo.critic.layerSizes = { 512, 512, 512 };

    cfg.ppo.sharedHead.optimType = ModelOptimType::ADAM;
    cfg.ppo.policy.optimType = ModelOptimType::ADAM;
    cfg.ppo.critic.optimType = ModelOptimType::ADAM;

    cfg.ppo.sharedHead.activationType = ModelActivationType::LEAKY_RELU;
    cfg.ppo.policy.activationType = ModelActivationType::LEAKY_RELU;
    cfg.ppo.critic.activationType = ModelActivationType::LEAKY_RELU;

    cfg.ppo.sharedHead.addLayerNorm = true;
    cfg.ppo.policy.addLayerNorm = true;
    cfg.ppo.critic.addLayerNorm = true;

    cfg.trainAgainstOldVersions = false;
    cfg.trainAgainstOldChance = 0.15f;

    cfg.skillTracker.enabled = true;
    cfg.skillTracker.numArenas = 16;
    cfg.skillTracker.simTime = 45;
    cfg.skillTracker.updateInterval = 16;
    cfg.skillTracker.ratingInc = 5;
    cfg.skillTracker.initialRating = 0;

    cfg.sendMetrics = true;
    cfg.renderMode = false;

    for (int i = 1; i < argc; ++i)
    {
        const std::string arg = argv[i];
        if (arg == "--render")
        {
            cfg.renderMode = true;
            cfg.renderTimeScale = 1.5f;
            cfg.sendMetrics = false;
            cfg.ppo.miniBatchSize = 0;
            cfg.numGames = 1;
            cfg.ppo.deterministic = false;
            break;
        }
    }

    auto learner = std::make_unique<Learner>(EnvCreateFunc, cfg, StepCallback);
    learner->Start();

    return EXIT_SUCCESS;
}
