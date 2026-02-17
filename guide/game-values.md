# Game Values

A reference for constant values used in Rocket League and GigaLearnCPP. All spatial measurements are in Unreal Units (uu), where 1 uu ≈ 1 centimeter.

---

## Field Dimensions

| Name | Value | Description |
|------|-------|-------------|
| `SIDE_WALL_X` | ±4096 | Distance from field center to side wall |
| `BACK_WALL_Y` | ±5120 | Distance from field center to back wall |
| `CEILING_Z` | 2044 | Height of arena ceiling from ground |
| `BACK_NET_Y` | ±6000 | Distance from field center to back of net |

## Goal Dimensions

| Name | Value | Description |
|------|-------|-------------|
| `GOAL_HEIGHT` | 642.775 | Height of goal opening |
| `GOAL_WIDTH_FROM_CENTER` | 892.755 | Width from center to goal post |
| `ORANGE_GOAL_CENTER` | (0, 5120, 321.3875) | Orange goal center position |
| `BLUE_GOAL_CENTER` | (0, -5120, 321.3875) | Blue goal center position |
| `ORANGE_GOAL_BACK` | (0, 6000, 321.3875) | Orange goal back position |
| `BLUE_GOAL_BACK` | (0, -6000, 321.3875) | Blue goal back position |

## Time Values

| Name | Value | Description |
|------|-------|-------------|
| `TICK_TIME` | 1/120 (~0.00833s) | Time per physics tick |

## Physics Values

| Name | Value | Description |
|------|-------|-------------|
| `GRAVITY_Z` | -650.0 | Downward acceleration |
| `BALL_RADIUS` | 92.75 | Radius of the ball |
| `BOOST_CONSUMED_PER_SECOND` | ~33.33 | Boost consumed per second |

## Speed Limits

| Name | Value | Description |
|------|-------|-------------|
| `BALL_MAX_SPEED` | 6000 | Maximum attainable ball velocity |
| `CAR_MAX_SPEED` | 2300 | Maximum attainable car velocity |
| `SUPERSONIC_THRESHOLD` | 2200 | Velocity threshold for supersonic state |
| `CAR_MAX_ANG_VEL` | 5.5 | Maximum car angular velocity (rad/s) |

## Teams

| Name | Value | Description |
|------|-------|-------------|
| `BLUE_TEAM` | 0 | Blue team identifier |
| `ORANGE_TEAM` | 1 | Orange team identifier |

## Car Controls

| Input | Range | Type |
|-------|-------|------|
| Throttle | [-1, 1] | Continuous |
| Steer | [-1, 1] | Continuous |
| Yaw | [-1, 1] | Continuous |
| Pitch | [-1, 1] | Continuous |
| Roll | [-1, 1] | Continuous |
| Jump | {0, 1} | Discrete |
| Boost | {0, 1} | Discrete |
| Handbrake | {0, 1} | Discrete |

> `NUM_ACTIONS` = 8

## Boost Pad Locations

34 boost pads total. Coordinates are (X, Y, Z) in Unreal Units.

| # | X | Y | Z |
|---|---|---|---|
| 1 | 0 | -4240 | 70 |
| 2 | -1792 | -4184 | 70 |
| 3 | 1792 | -4184 | 70 |
| 4 | -3072 | -4096 | 73 |
| 5 | 3072 | -4096 | 73 |
| 6 | -940 | -3308 | 70 |
| 7 | 940 | -3308 | 70 |
| 8 | 0 | -2816 | 70 |
| 9 | -3584 | -2484 | 70 |
| 10 | 3584 | -2484 | 70 |
| 11 | -1788 | -2300 | 70 |
| 12 | 1788 | -2300 | 70 |
| 13 | -2048 | -1036 | 70 |
| 14 | 0 | -1024 | 70 |
| 15 | 2048 | -1036 | 70 |
| 16 | -3584 | 0 | 73 |
| 17 | -1024 | 0 | 70 |
| 18 | 1024 | 0 | 70 |
| 19 | 3584 | 0 | 73 |
| 20 | -2048 | 1036 | 70 |
| 21 | 0 | 1024 | 70 |
| 22 | 2048 | 1036 | 70 |
| 23 | -1788 | 2300 | 70 |
| 24 | 1788 | 2300 | 70 |
| 25 | -3584 | 2484 | 70 |
| 26 | 3584 | 2484 | 70 |
| 27 | 0 | 2816 | 70 |
| 28 | -940 | 3310 | 70 |
| 29 | 940 | 3308 | 70 |
| 30 | -3072 | 4096 | 73 |
| 31 | 3072 | 4096 | 73 |
| 32 | -1792 | 4184 | 70 |
| 33 | 1792 | 4184 | 70 |
| 34 | 0 | 4240 | 70 |
