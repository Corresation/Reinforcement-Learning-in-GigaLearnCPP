@echo off
setlocal

:: python setup
set "PY_HOME=C:\Users\<username>\path\to\Python<ver>"
set "PYTHONHOME=%PY_HOME%"
set "PYTHONPATH=%PY_HOME%\Lib;%PY_HOME%\DLLs"
set "PATH=%PY_HOME%;%PATH%"
set "PYTHON_CMD=%PY_HOME%\python.exe"

:: paths
set "BOT_DIR=C:\Users\<username>\path\to\build\"
set "BOT_EXE=GigaLearnBot.exe"

set "VIS_DIR=C:\Users\<username>\path\to\RocketSimVis-main\src"
set "VIS_SCRIPT=main.py"

:loop
cls
echo [STARTING VISUALISER] Press Ctrl+C to stop.
echo.

:: start visualizer if not already running
tasklist /FI "IMAGENAME eq python.exe" 2>NUL | find /I "%VIS_SCRIPT%" >NUL
if errorlevel 1 (
    echo Launching visualizer...
    start "" /D "%VIS_DIR%" "%PYTHON_CMD%" "%VIS_SCRIPT%"
    timeout /t 2 >nul
)

:: run bot
cd /d "%BOT_DIR%"
echo Launching %BOT_EXE%...
"%BOT_EXE%" --render --autorestart --2v2

echo.
echo Bot closed. Restarting...
timeout /t 2 >nul
goto loop

