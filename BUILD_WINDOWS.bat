@echo off
setlocal
cd /d "%~dp0"
if not exist output mkdir output
if not exist Data mkdir Data
where g++ >nul 2>nul
if errorlevel 1 (
  echo.
  echo ERROR: g++ was not found in PATH.
  echo Install MinGW/G++ or use the C++ compiler already configured in VS Code.
  echo.
  pause
  exit /b 1
)
echo Building Fitness Training Management...
g++ -std=c++17 -Wall -Wextra main.cpp Person.cpp Member.cpp Trainer.cpp WorkoutPlan.cpp Session.cpp FileManager.cpp FitnessCenter.cpp -o output\main.exe
if errorlevel 1 (
  echo.
  echo BUILD FAILED. Read the compiler errors above.
  pause
  exit /b 1
)
echo.
echo BUILD SUCCESSFUL.
echo Starting the program...
echo.
output\main.exe
pause
