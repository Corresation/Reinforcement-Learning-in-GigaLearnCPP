# 04: ExampleMain.cpp

## What is ExampleMain.cpp?

`ExampleMain.cpp` is the most important file in your entire training setup.

This file includes all features that you will need to create a bot.

There are more features (for later) which are located in:

- GigaLearnCPP/src/public/GigaLearnCPP/LearnerConfig.h
- GigaLearnCPP/src/public/GigaLearnCPP/PPO/PPOLearnerConfig.h

## Where is my ExampleMain.cpp located?

You should find it at:
```
GigaLearnCPP-Leak-main/src/ExampleMain.cpp
```

## What's inside the file?

The file has two main parts:

### 1. EnvCreateFunc
This function creates the training environment. It defines:
- **Rewards** – What behaviours get rewarded
- **Terminal conditions** – When a game should reset (goal scored, 10 seconds no touch, etc.)
- **ActionParser** – How the bot's actions are interpreted
- **ObsBuilder** – What observations the bot sees
- **StateSetter** – How games start (kickoff, random state, etc.)
- **Arena Configuration** – Number of players per team, game mode

### 2. main()
This is where you:
- Point to your RocketSim collision meshes file
- Set learning config (learning rate, batch size, epochs, etc.)
- Choose device (GPU or CPU)
- Set tick skip and action delay
- Enable/disable WandB

## Key Points & Ideas

- ExampleMain.cpp is where all training starts
- It controls rewards, observations, game rules, and learning settings
- Found at `GigaLearnCPP-Leak-main/src/ExampleMain.cpp`
