#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <vector>
#include <string>
#include "Member.h"
#include "Trainer.h"
#include "WorkoutPlan.h"
#include "Session.h"
using namespace std;

class FileManager {
public:
    static bool saveMembers(const vector<Member>& data, const string& file);
    static bool loadMembers(vector<Member>& data, const string& file);
    static bool saveTrainers(const vector<Trainer>& data, const string& file);
    static bool loadTrainers(vector<Trainer>& data, const string& file);
    static bool savePlans(const vector<WorkoutPlan>& data, const string& file);
    static bool loadPlans(vector<WorkoutPlan>& data, const string& file);
    static bool saveSessions(const vector<Session>& data, const string& file);
    static bool loadSessions(vector<Session>& data, const string& file);
};
#endif
