# Introduction

## What is GigaLearnCPP exactly?
GigaLearnCPP is a PPO-based training framework for Rocket League bots. It runs on RocketSim and trains agents through reward-driven learning.

## How does PPO work here?
PPO (Proximal Policy Optimization) allows the bot to observe states, take actions, receive rewards, and update its policy. Over millions/billions of steps, it learns which actions maximize reward.

## What's the pattern with it?
To put it short and simple:
1. Bot reads game state
2. Bot selects action
3. Environment returns reward (if successful)
4. Policy updates
5. Repeat

## What am I, the coder, able to control?
The only things that people often control are:
- Reward functions
- Observations (Obs)
- Hyperparameters
- StateSetters

That's kind of it. Unless you're going for a full framework rework... (Hi Claude!)

## How good is this framework in terms of speed?
C++ implementation with RocketSim physics enables high throughput step collection. It is ~400x faster than RLGymPPO. This speeds up training by miles compared to Python-based alternatives.
