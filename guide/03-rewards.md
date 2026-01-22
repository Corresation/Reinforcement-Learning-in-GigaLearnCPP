# 03: Rewards

## What are rewards?
Rewards tell your bot what's good and bad. Positive = good action. Negative = bad action. Zero = neutral.

The bot tries to maximize total reward over time. The higher the weight, the more important.

## Timesteps teach the bot more than you think!
**Biggest beginner mistake:** rewarding everything.

The bot literally learns naturally through experience (timesteps):
- Defense
- Rotations
- Wall play
- Accuracy
- Boost management
- Recovery

To put it short, it is highly NOT recommended to reward for any of this.

## Examples of Rewards in CommonRewards.h
- `GoalReward` – Scoring
- `TouchBallReward` – Touching ball
- `VelocityPlayerToBallReward` – Moving toward ball
- `VelocityBallToGoalReward` – Ball moving toward goal
- `PickupBoostReward` – Grabbing boost
- `SaveBoostReward` – Having boost
- `FaceBallReward` – Facing ball
- `AirReward` – Being airborne

## Zero-Sum Rewards
Zero-summing rewards makes training competitive. Your reward = opponent's penalty.
```cpp
{ new ZeroSumReward(new VelocityBallToGoalReward(), 0, 1), 5.0f }
```

**Parameters:**
- `0` = teamSpirit (0 = no sharing, 1 = split with teammates)
- `1` = opponentScale (1 = full zero-sum, 0 = not competitive)
- `5.0f` = weight (importance)

## Instance of Basic Reward Usage
```cpp
{ new VelocityPlayerToBallReward(), 1.f },
{ new FaceBallReward(), .1f },
{ new TouchBallReward(), 5.f },
{ new AirReward(), .1f },
```

## Key Points & Ideas
- Rewards shape behaviour
- Timesteps handle most learning
- Don't over-reward
- ZeroSumReward enables competition
