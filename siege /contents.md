<div style="font-family: 'Consolas', 'Courier New', monospace; background-color:#0d0d0d; color:#e0e0e0; padding:40px; border-radius:10px;">

  <div align="center" style="margin-bottom:40px;">
    <h1 style="font-size:42px; font-weight:900; letter-spacing:1px; margin-bottom:5px; color:#76c7ff;">SIEGE</h1>
    <p style="font-size:16px; color:#b0b0b0; margin-top:0;">
      Development with <b style="color:#fff;">GigaLearnCPP</b>
    </p>
    <hr style="width:70%; border:1px solid #333; margin-top:20px;">
  </div>

  <h2 style="color:#6bd26b;">Overview</h2>
  <p style="line-height:1.6;">
    Siege is my personal (and experimental) Rocket League bot built using the GigaLearnCPP.<br>
    It is my project focusing on Machine Learning in 1v1s, 2v2s and 3v3s. The end goal is to make a bot that can beat Grand Champions in all modes!
  </p>

  <hr style="border:0; border-top:1px solid #2d2d2d; margin:30px 0;">

  <h2 style="color:#6bd26b;">What is the purpose of Siege?</h2>
  <p style="line-height:1.6;">
    The purpose of Siege is to experiment with my first genuine Rocket League bot using this framework.<br>
    It acts as a control agent — a base for future testing and experimentation.<br>
    No imitation learning — Siege learns purely through experience and speed!
  </p>

  <p style="line-height:1.6;">
    Over time, Siege will be used to test new ideas for environment design, state variety, and reward shaping in GigaLearnCPP.<br>
    It’s meant to answer one question clearly:<br>
    <span style="display:block; margin-top:10px; font-style:italic; color:#76c7ff;">
      “How far can a baseline agent go through self-play and careful tuning alone?”
    </span>
  </p>

  <hr style="border:0; border-top:1px solid #2d2d2d; margin:30px 0;">

  <h2 style="color:#6bd26b;">Development Plans & Intentions</h2>
  <p style="line-height:1.6;">
    Training began with sheer control logic using PPO inside GigaLearnCPP.<br>
    Siege has ~3 million parameters total, and is being taught to learn ground play as best as possible.<br>
    Early stages focus on team ability and consistency with fundementals.<br>
    The design is intentionally minimal to observe each improvement as it happens.
  </p>

  <p style="line-height:1.6;">
    Siege will eventually become my reference bot for comparing new reward structures, network setups, and multi-agent training scenarios.
  </p>

  <hr style="border:0; border-top:1px solid #2d2d2d; margin:30px 0;">

  <h2 style="color:#6bd26b;">Will this be used and expanded upon?</h2>
  <p style="line-height:1.6;">
    Yes, absolutely!<br>
    The initial version of Siege is purely experimental, and attempts to maximize its ability by using the basics as best as possible.<br>
    Once the base version is done, I will transfer learn this onto bigger parameters to learn more, and will continue to aim higher.
  </p>

  <hr style="width:80%; border:1px solid #333; margin:40px auto;">

  <p align="center" style="color:#777;">
    Created and developed by <b style="color:#fff;">Corresation</b><br>
    Built using <b style="color:#fff;">GigaLearnCPP</b> and <b style="color:#fff;">RLGymCPP</b>
  </p>

</div>
