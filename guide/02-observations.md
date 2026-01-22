# 02: Observations

## What are observations?
Observations (Obs) are the game state your bot sees every frame. 

Your bot watches with numbers and you watch with your eyes.

**Critical rule:** Obs structure must stay constant throughout training. No mid-training changes.

## What's in an observation?
Every observation is a vector (list of numbers). For instance, AdvancedObs includes:
- Ball position
- Car position, rotation, boost amount
- Boost pad states
- Previous actions

...and everything required to make a good bot.

All values are **normalized** (scaled down) for more efficient learning.

## Observation Builders
An **ObsBuilder** generates these numbers. Built-in options:
- **DefaultObs**: Basic coverage of what's around it
- **AdvancedObs**: Includes local ball position (relative to car)
- **AdvancedObsPadder**: AdvancedObs + allows all modes simultaneously (does not come with GigaLearnCPP)

Set in `ExampleMain.cpp`:
```cpp
result.obsBuilder = new AdvancedObs();
```

## Key Points
- Obs = numbers describing game state
- Bot only learns from what it sees
- Missing info = harder learning
- Too much info = slower training

That's all.
