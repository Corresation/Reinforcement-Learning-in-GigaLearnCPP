#pragma once
#include "Reward.h"
#include "../Math.h"

namespace RLGC {

class GoalReward : public Reward {
public:
    float concedeScale;
    explicit GoalReward(float concedeScale = -1.f) : concedeScale(concedeScale) {}

    float GetReward(const Player& player, const GameState& state, bool isFinal) const override {
        if (!state.goalScored) return 0.f;
        bool scored = (player.team != RS_TEAM_FROM_Y(state.ball.pos.y));
        return scored ? 1.f : concedeScale;
    }
};

class TouchBallReward : public Reward {
public:
    float GetReward(const Player& player, const GameState& state, bool isFinal) const override {
        return player.ballTouchedStep;
    }
};

class FaceBallReward : public Reward {
public:
    float GetReward(const Player& player, const GameState& state, bool isFinal) const override {
        Vec dirToBall = (state.ball.pos - player.pos).Normalized();
        return player.rotMat.forward.Dot(dirToBall);
    }
};

class AirReward : public Reward {
public:
    float GetReward(const Player& player, const GameState& state, bool isFinal) const override {
        return !player.isOnGround;
    }
};

class VelocityPlayerToBallReward : public Reward {
public:
    float GetReward(const Player& player, const GameState& state, bool isFinal) const override {
        Vec dirToBall = (state.ball.pos - player.pos).Normalized();
        Vec normVel = player.vel / CommonValues::CAR_MAX_SPEED;
        return dirToBall.Dot(normVel);
    }
};

class VelocityBallToGoalReward : public Reward {
public:
    bool ownGoal;
    explicit VelocityBallToGoalReward(bool ownGoal = false) : ownGoal(ownGoal) {}

    float GetReward(const Player& player, const GameState& state, bool isFinal) const override {
        bool targetOrangeGoal = (player.team == Team::BLUE);
        if (ownGoal) targetOrangeGoal = !targetOrangeGoal;

        const Vec& targetPos = targetOrangeGoal ? CommonValues::ORANGE_GOAL_BACK
                                                : CommonValues::BLUE_GOAL_BACK;
        Vec ballDirToGoal = (targetPos - state.ball.pos).Normalized();
        return ballDirToGoal.Dot(state.ball.vel / CommonValues::BALL_MAX_SPEED);
    }
};

class KickoffProximityReward : public Reward {
public:
    float GetReward(const Player& player, const GameState& state, bool isFinal) const override {
        if (std::abs(state.ball.pos.x) > 1.f || std::abs(state.ball.pos.y) > 1.f) return 0.f;

        float playerDist = (player.pos - state.ball.pos).Length();
        float closestOpponent = FLT_MAX;
        bool found = false;

        for (const Player& opp : state.players) {
            if (opp.team == player.team || opp.carId == player.carId) continue;
            found = true;
            closestOpponent = std::min(closestOpponent, (opp.pos - state.ball.pos).Length());
        }

        if (!found) return 0.f;
        return (playerDist < closestOpponent) ? 1.f : -1.f;
    }
};

class JumpTouchReward : public Reward {
public:
    float minHeight, maxHeight, range;
    JumpTouchReward(float minH = 92.75f, float maxH = 204.f)
        : minHeight(minH), maxHeight(maxH), range(maxH - minH) {}

    float GetReward(const Player& player, const GameState& state, bool isFinal) const override {
        if (player.ballTouchedStep && !player.isOnGround && state.ball.pos.z >= minHeight)
            return (state.ball.pos.z - minHeight) / range;
        return 0.f;
    }
};

class DribbleReward : public Reward {
public:
    float minBallHeight, maxBallHeight, maxDistance, coeff;
    DribbleReward(float minH = 109.f, float maxH = 180.f, float maxD = 197.f, float c = 2.f)
        : minBallHeight(minH), maxBallHeight(maxH), maxDistance(maxD), coeff(c) {}

    float GetReward(const Player& player, const GameState& state, bool isFinal) const override {
        if (!player.isOnGround) return 0.f;
        if (state.ball.pos.z < minBallHeight || state.ball.pos.z > maxBallHeight) return 0.f;
        if ((player.pos - state.ball.pos).Length() >= maxDistance) return 0.f;

        float playerSpeed = player.vel.Length();
        float ballSpeed = state.ball.vel.Length();
        float playerSpeedNorm = playerSpeed / CommonValues::CAR_MAX_SPEED;
        float inverseDiff = 1.f - std::abs(playerSpeed - ballSpeed);
        float twoSum = playerSpeed + ballSpeed;

        if (twoSum == 0.f) return 0.f;
        float speedReward = playerSpeedNorm + coeff * (inverseDiff / twoSum);
        return speedReward;
    }
};

class FlickReward : public Reward {
public:
    float minFlickSpeed, maxFlickHeight;
    FlickReward(float minSpeed = 800.f, float maxHeight = 300.f)
        : minFlickSpeed(minSpeed), maxFlickHeight(maxHeight) {}

    float GetReward(const Player& player, const GameState& state, bool isFinal) const override {
        if (!state.prev || !player.ballTouchedStep) return 0.f;

        bool ballWasLow = state.prev->ball.pos.z < maxFlickHeight;
        bool ballNowFast = state.ball.vel.Length() > minFlickSpeed;
        bool ballGoingUp = state.ball.vel.z > 200.f;
        bool playerWasClose = (player.pos - state.prev->ball.pos).Length() < 200.f;

        if (ballWasLow && ballNowFast && ballGoingUp && playerWasClose) {
            float speedRatio = RS_MIN(1.f, state.ball.vel.Length() / 2000.f);
            return speedRatio;
        }
        return 0.f;
    }
};

class SaveBoostReward : public Reward {
public:
    float exponent;
    explicit SaveBoostReward(float exp = 0.5f) : exponent(exp) {}

    float GetReward(const Player& player, const GameState& state, bool isFinal) const override {
        return RS_CLAMP(powf(player.boost / 100.f, exponent), 0.f, 1.f);
    }
};

class PickupBoostReward : public Reward {
public:
    float GetReward(const Player& player, const GameState& state, bool isFinal) const override {
        if (!player.prev) return 0.f;
        if (player.boost > player.prev->boost)
            return sqrtf(player.boost / 100.f) - sqrtf(player.prev->boost / 100.f);
        return 0.f;
    }
};

class TeamSpacingReward : public Reward {
public:
    float minSpacing;
    explicit TeamSpacingReward(float min = 1500.f) : minSpacing(min) {}

    float GetReward(const Player& player, const GameState& state, bool isFinal) const override {
        float total = 0.f;
        int teammates = 0;

        for (const Player& mate : state.players) {
            if (mate.carId == player.carId || mate.team != player.team) continue;
            teammates++;

            float distance = (player.pos - mate.pos).Length();
            total += (distance >= minSpacing) ? 1.f : (distance / minSpacing);
        }

        return teammates > 0 ? total / teammates : 0.f;
    }
};

template<bool PlayerEventState::*VAR, bool NEGATIVE>
class PlayerDataEventReward : public Reward {
public:
    float GetReward(const Player& player, const GameState& state, bool isFinal) const override {
        bool val = player.eventState.*VAR;
        return NEGATIVE ? -(float)val : (float)val;
    }
};

using PlayerGoalReward = PlayerDataEventReward<&PlayerEventState::goal, false>;
using AssistReward = PlayerDataEventReward<&PlayerEventState::assist, false>;
using ShotReward = PlayerDataEventReward<&PlayerEventState::shot, false>;
using ShotPassReward = PlayerDataEventReward<&PlayerEventState::shotPass, false>;
using SaveReward = PlayerDataEventReward<&PlayerEventState::save, false>;
using BumpReward = PlayerDataEventReward<&PlayerEventState::bump, false>;
using BumpedPenalty = PlayerDataEventReward<&PlayerEventState::bumped, true>;
using DemoReward = PlayerDataEventReward<&PlayerEventState::demo, false>;
using DemoedPenalty = PlayerDataEventReward<&PlayerEventState::demoed, true>;

}
