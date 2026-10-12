#ifndef WORKOUTPLAN_H
#define WORKOUTPLAN_H
#include <string>
using namespace std;

class WorkoutPlan {
private:
    int planId;
    int memberId;
    string exercises;
    int duration;
public:
    WorkoutPlan();
    WorkoutPlan(int planId, int memberId, const string& exercises, int duration);
    ~WorkoutPlan();
    int getPlanId() const;
    int getMemberId() const;
    string getExercises() const;
    int getDuration() const;
    void addExercise(const string& exercise);
    void display() const;
    string serialize() const;
};

#endif
