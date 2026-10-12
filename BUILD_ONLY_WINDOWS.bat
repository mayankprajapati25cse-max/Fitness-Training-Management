@echo off
setlocal
cd /d "%~dp0"
if not exist output mkdir output
where g++ >nul 2>nul
if errorlevel 1 (
  echo ERROR: g++ not found in PATH.
  pause
  exit /b 1
)
g++ -std=c++17 -Wall -Wextra main.cpp Person.cpp Member.cpp Trainer.cpp WorkoutPlan.cpp Session.cpp FileManager.cpp FitnessCenter.cpp -o output\main.exe
if errorlevel 1 (
  echo BUILD FAILED.
) else (
  echo BUILD SUCCESSFUL: output\main.exe
)
pause
