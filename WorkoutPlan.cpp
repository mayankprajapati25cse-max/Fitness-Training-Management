#include "WorkoutPlan.h"
#include <iostream>
using namespace std;
WorkoutPlan::WorkoutPlan() : planId(0), memberId(0), exercises(""), duration(0) {}
WorkoutPlan::WorkoutPlan(int planId, int memberId, const string& exercises, int duration) : planId(planId), memberId(memberId), exercises(exercises), duration(duration) {}
WorkoutPlan::~WorkoutPlan() {}
int WorkoutPlan::getPlanId() const { return planId; }
int WorkoutPlan::getMemberId() const { return memberId; }
string WorkoutPlan::getExercises() const { return exercises; }
int WorkoutPlan::getDuration() const { return duration; }
void WorkoutPlan::addExercise(const string& exercise) { if (!exercises.empty()) exercises += ", "; exercises += exercise; }
void WorkoutPlan::display() const { cout << "Plan ID: " << planId << " | Member ID: " << memberId << " | Exercises: " << exercises << " | Duration: " << duration << " min\n"; }
string WorkoutPlan::serialize() const { return to_string(planId) + "|" + to_string(memberId) + "|" + exercises + "|" + to_string(duration); }
