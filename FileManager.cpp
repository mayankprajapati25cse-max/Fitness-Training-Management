#include "FileManager.h"
#include <fstream>
#include <sstream>
using namespace std;
static vector<string> split(const string& s) { vector<string> v; string x; stringstream ss(s); while(getline(ss,x,'|')) v.push_back(x); return v; }
bool FileManager::saveMembers(const vector<Member>& d,const string& f){ofstream o(f); if(!o)return false; for(auto&x:d)o<<x.serialize()<<'\n'; return true;}
bool FileManager::loadMembers(vector<Member>& d,const string& f){ifstream in(f); if(!in)return false; d.clear(); string l; while(getline(in,l)){auto v=split(l); if(v.size()==4)d.emplace_back(stoi(v[0]),v[1],stoi(v[2]),v[3]);} return true;}
bool FileManager::saveTrainers(const vector<Trainer>& d,const string& f){ofstream o(f); if(!o)return false; for(auto&x:d)o<<x.serialize()<<'\n'; return true;}
bool FileManager::loadTrainers(vector<Trainer>& d,const string& f){ifstream in(f); if(!in)return false; d.clear(); string l; while(getline(in,l)){auto v=split(l); if(v.size()==3)d.emplace_back(stoi(v[0]),v[1],v[2]);} return true;}
bool FileManager::savePlans(const vector<WorkoutPlan>& d,const string& f){ofstream o(f); if(!o)return false; for(auto&x:d)o<<x.serialize()<<'\n'; return true;}
bool FileManager::loadPlans(vector<WorkoutPlan>& d,const string& f){ifstream in(f); if(!in)return false; d.clear(); string l; while(getline(in,l)){auto v=split(l); if(v.size()==4)d.emplace_back(stoi(v[0]),stoi(v[1]),v[2],stoi(v[3]));} return true;}
bool FileManager::saveSessions(const vector<Session>& d,const string& f){ofstream o(f); if(!o)return false; for(auto&x:d)o<<x.serialize()<<'\n'; return true;}
bool FileManager::loadSessions(vector<Session>& d,const string& f){ifstream in(f); if(!in)return false; d.clear(); string l; while(getline(in,l)){auto v=split(l); if(v.size()==5)d.emplace_back(stoi(v[0]),stoi(v[1]),stoi(v[2]),v[3],v[4]);} return true;}
