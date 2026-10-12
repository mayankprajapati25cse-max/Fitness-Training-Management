#ifndef FITNESSCENTER_H
#define FITNESSCENTER_H
#include <vector>
#include <string>
#include "Member.h"
#include "Trainer.h"
#include "WorkoutPlan.h"
#include "Session.h"

class FitnessCenter {
private:
    std::vector<Member> members;
    std::vector<Trainer> trainers;
    std::vector<WorkoutPlan> plans;
    std::vector<Session> sessions;
    const std::string memberFile = "Data/members.dat";
    const std::string trainerFile = "Data/trainers.dat";
    const std::string planFile = "Data/plans.dat";
    const std::string sessionFile = "Data/sessions.dat";
    bool existsMember(int id) const;
    bool existsTrainer(int id) const;
public:
    FitnessCenter();
    ~FitnessCenter();
    void loadData();
    void saveData() const;
    void addMember();
    void addTrainer();
    void createPlan();
    void bookSession();
    void displayRecords() const;
    void searchRecord() const;
    void updateMember();
    void deleteMember();
    void report() const;
    void demonstratePolymorphism() const;
    void menu();
};
#endif
