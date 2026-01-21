<div style="font-family: 'Consolas', 'Courier New', monospace; background-color:#0d0d0d; color:#e0e0e0; padding:40px; border-radius:10px;">

  <div align="center" style="margin-bottom:40px;">
    <h1 style="font-size:42px; font-weight:900; letter-spacing:1px; margin-bottom:5px; color:#76c7ff;">GGL Guide</h1>
    <hr style="width:70%; border:1px solid #333; margin-top:20px;">
  </div>

  <div style="margin-bottom:30px;">
    <h2 style="color:#ff6b6b; font-size:28px; margin-bottom:15px;">DISCLAIMERS</h2>
    <p style="line-height:1.8; color:#c0c0c0;">
      This tutorial follows through how to install GigaLearnCPP from scratch.<br>
      If you do not have or use the following, it <b>may</b> be tricky to follow this guide:
    </p>
    <ul style="line-height:2; color:#b0b0b0; margin-left:20px;">
      <li><b style="color:#76c7ff;">VS2022</b> (recommended)</li>
      <li><b style="color:#76c7ff;">CUDA 12.8 / 12.9</b> (recommended). Other CUDA 12.x versions (12.6 / 12.9) may work with the correct LibTorch build.</li>
      <li><b style="color:#76c7ff;">Windows OS</b> (preferably)</li>
      <li><b style="color:#76c7ff;">Python 3.11</b></li>
      <li><b style="color:#76c7ff;">Git and PyTorch (C++)</b></li>
    </ul>
  </div>

  <hr style="border:1px solid #333; margin:40px 0;">

  <div style="margin-bottom:30px;">
    <h2 style="color:#76c7ff; font-size:26px; margin-bottom:15px;">Step 1 - Clone the Repository</h2>
    <p style="line-height:1.8; color:#c0c0c0; margin-bottom:15px;">
      Open a command prompt and run:
    </p>
    <pre style="background-color:#1a1a1a; padding:15px; border-radius:5px; overflow-x:auto; border-left:3px solid #76c7ff;"><code style="color:#50fa7b;">cd %USERPROFILE%\Downloads
git clone https://github.com/ZealanL/GigaLearnCPP-Leak --recurse-submodules</code></pre>
    <blockquote style="border-left:3px solid #555; padding-left:15px; color:#888; font-style:italic; margin-top:15px;">
      <b>Note:</b> Git must be installed and available in PATH.<br>
      Download: <a href="https://git-scm.com/download/win" style="color:#76c7ff;">Git for Windows</a>
    </blockquote>
  </div>

  <hr style="border:1px solid #333; margin:40px 0;">

  <div style="margin-bottom:30px;">
    <h2 style="color:#76c7ff; font-size:26px; margin-bottom:15px;">Step 2 - Install CUDA</h2>
    <p style="line-height:1.8; color:#c0c0c0;">
      If you have an NVIDIA GPU:
    </p>
    <ol style="line-height:2; color:#b0b0b0; margin-left:20px;">
      <li>Download CUDA 12.8 (or another 12.x version if compatible):<br>
      <a href="https://developer.nvidia.com/cuda-12-8-0-download-archive" style="color:#76c7ff;">CUDA 12.8 Download</a></li>
      <li>Select:<br>
      <b style="color:#fff;">Windows → x64 → Your OS version → exe (local) → Download</b></li>
    </ol>
  </div>

  <hr style="border:1px solid #333; margin:40px 0;">

  <div style="margin-bottom:30px;">
    <h2 style="color:#76c7ff; font-size:26px; margin-bottom:15px;">Step 3 - Install LibTorch</h2>
    <ol style="line-height:2; color:#b0b0b0; margin-left:20px;">
      <li>Go to: <a href="https://pytorch.org/get-started/locally/" style="color:#76c7ff;">PyTorch Local Build</a></li>
      <li>Select:
        <ul style="margin-top:10px;">
          <li><b style="color:#fff;">Build:</b> Stable</li>
          <li><b style="color:#fff;">OS:</b> Windows</li>
          <li><b style="color:#fff;">Package:</b> LibTorch</li>
          <li><b style="color:#fff;">Language:</b> C++</li>
          <li><b style="color:#fff;">Compute Platform:</b> CUDA 12.8 (or CPU if no GPU)</li>
        </ul>
      </li>
    </ol>
    <blockquote style="border-left:3px solid #555; padding-left:15px; color:#888; font-style:italic; margin-top:15px;">
      <b>Note:</b> Do not download the Nightly version.
    </blockquote>
  </div>

  <hr style="border:1px solid #333; margin:40px 0;">

  <div style="margin-bottom:30px;">
    <h2 style="color:#76c7ff; font-size:26px; margin-bottom:15px;">Step 4 - Place the LibTorch Folder into "GigaLearnCPP"</h2>
    <p style="line-height:1.8; color:#c0c0c0; margin-bottom:15px;">
      Extract all, unindent the folder, and put the <code style="background-color:#1a1a1a; padding:2px 6px; border-radius:3px; color:#50fa7b;">libtorch</code> folder into:
    </p>
    <pre style="background-color:#1a1a1a; padding:15px; border-radius:5px; border-left:3px solid #76c7ff;"><code style="color:#50fa7b;">GigaLearnCPP-Leak\GigaLearnCPP</code></pre>
  </div>

  <hr style="border:1px solid #333; margin:40px 0;">

  <div style="margin-bottom:30px;">
    <h2 style="color:#76c7ff; font-size:26px; margin-bottom:15px;">Step 5 - Open VS2022</h2>
    <ol style="line-height:2; color:#b0b0b0; margin-left:20px;">
      <li>Ensure VS2022 is installed with <b style="color:#fff;">C++ Desktop Development Kit</b></li>
      <li>Open VS2022 → <b style="color:#fff;">Open a local folder</b> → Select <code style="background-color:#1a1a1a; padding:2px 6px; border-radius:3px; color:#50fa7b;">GigaLearnCPP-Leak</code></li>
    </ol>
  </div>

  <hr style="border:1px solid #333; margin:40px 0;">

  <div style="margin-bottom:30px;">
    <h2 style="color:#76c7ff; font-size:26px; margin-bottom:15px;">Step 6 - Configure the Build</h2>
    <ol style="line-height:2; color:#b0b0b0; margin-left:20px;">
      <li>Click the dropdown at the top (usually <code style="background-color:#1a1a1a; padding:2px 6px; border-radius:3px; color:#50fa7b;">x64-Debug</code>) → <b style="color:#fff;">Manage Configurations</b></li>
      <li>Click the green <code style="background-color:#1a1a1a; padding:2px 6px; border-radius:3px; color:#50fa7b;">+</code> → select <b style="color:#fff;">x64-Debug</b> as base. This creates <b style="color:#fff;">x64-Debug (2)</b></li>
      <li>Rename that duplicate configuration to: <b style="color:#fff;">x64-RelWithDebInfo</b></li>
      <li>Set <b style="color:#fff;">Configuration type:</b> <code style="background-color:#1a1a1a; padding:2px 6px; border-radius:3px; color:#50fa7b;">RelWithDebInfo</code></li>
      <li>Close <code style="background-color:#1a1a1a; padding:2px 6px; border-radius:3px; color:#50fa7b;">CMakeSettings.json</code> → click <b style="color:#fff;">Save</b></li>
      <li>Switch the top dropdown to <b style="color:#fff;">x64-RelWithDebInfo</b>. CMake will rebuild; this is normal.</li>
    </ol>
    <div align="center" style="margin-top:20px;">
      <img src="readmeres/1222(1).gif" alt="Description" style="max-width:100%; border-radius:5px; border:2px solid #333;">
    </div>
    <blockquote style="border-left:3px solid #555; padding-left:15px; color:#888; font-style:italic; margin-top:15px;">
      <b>Tip:</b> You can also use <b>Release</b> if you feel it benefits you.
    </blockquote>
  </div>

  <hr style="border:1px solid #333; margin:40px 0;">

  <div style="margin-bottom:30px;">
    <h2 style="color:#76c7ff; font-size:26px; margin-bottom:15px;">Step 7 - Locate the Build Output</h2>
    <p style="line-height:1.8; color:#c0c0c0; margin-bottom:15px;">
      Example build output path:
    </p>
    <pre style="background-color:#1a1a1a; padding:15px; border-radius:5px; border-left:3px solid #76c7ff;"><code style="color:#50fa7b;">C:\Users\user\Downloads\GigaLearnCPP-Leak\out\build\x64-RelWithDebInfo\</code></pre>
    <p style="line-height:1.8; color:#c0c0c0; margin-bottom:15px;">
      Make sure the following exist in this folder (recommended):
    </p>
    <ul style="line-height:2; color:#b0b0b0; margin-left:20px;">
      <li><code style="background-color:#1a1a1a; padding:2px 6px; border-radius:3px; color:#50fa7b;">collision_meshes</code> <b style="color:#ff6b6b;">(MANDATORY)</b></li>
      <li><code style="background-color:#1a1a1a; padding:2px 6px; border-radius:3px; color:#50fa7b;">RocketSimVis</code> (any form of visualiser)</li>
      <li><code style="background-color:#1a1a1a; padding:2px 6px; border-radius:3px; color:#50fa7b;">Lib/DLL</code> folder <b style="color:#ff6b6b;">(if you receive errors)</b></li>
    </ul>
    <p style="line-height:1.8; color:#c0c0c0; margin-top:15px;">
      You should now be ready to launch and test.
    </p>
  </div>

  <hr style="border:1px solid #333; margin:40px 0;">

  <div style="margin-bottom:30px;">
    <h2 style="color:#ffd700; font-size:26px; margin-bottom:15px;">TIPS</h2>
    <ul style="line-height:2; color:#b0b0b0; margin-left:20px;">
      <li>Reconfigure CMake anytime: <code style="background-color:#1a1a1a; padding:2px 6px; border-radius:3px; color:#50fa7b;">Project → Configure Cache</code> in VS2022</li>
      <li>If CMake breaks: delete the <code style="background-color:#1a1a1a; padding:2px 6px; border-radius:3px; color:#50fa7b;">.vs</code> folder and VS2022 will regenerate all files</li>
    </ul>
  </div>

</div>
