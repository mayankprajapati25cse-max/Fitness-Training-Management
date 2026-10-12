# Fitness Training Management

**Enrollment:** IU2541230107  
**Student:** Mayank Prajapati  
**Subject:** CPP69 - C++ Guided Project  
**Semester:** 3

## Project
A console-based C++ OOP application for managing members, trainers, workout plans and training sessions.

## Classes
- Person (base class)
- Member
- Trainer
- WorkoutPlan
- Session
- FitnessCenter
- FileManager

## Features
- Add, display, search, update and delete member records
- Add trainers
- Create workout plans
- Book training sessions
- Generate a report
- Save/load records using text files
- Inheritance and runtime polymorphism
- Dynamic memory and exception handling

## Run on Windows
This project is intended to be compiled on the student's Windows PC using MinGW/G++.

1. Make sure `g++` works in Command Prompt/PowerShell.
2. Double-click `BUILD_WINDOWS.bat`.
3. It creates `output\main.exe` and runs the application.

Or compile manually:

```text
g++ -std=c++17 -Wall -Wextra main.cpp Person.cpp Member.cpp Trainer.cpp WorkoutPlan.cpp Session.cpp FileManager.cpp FitnessCenter.cpp -o output\main.exe
```

Then run:

```text
output\main.exe
```

Run from the `PROJECT SOURCE CODE` folder so the `Data` folder is used correctly.
