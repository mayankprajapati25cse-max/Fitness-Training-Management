#include "FitnessCenter.h"
#include "FileManager.h"
#include <iostream>
#include <limits>
#include <stdexcept>
using namespace std;

static void clearInput(){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(),'\n'); }
static int readInt(const string& prompt){ int x; while(true){ cout<<prompt; if(cin>>x){clearInput(); return x;} cout<<"Invalid input. Enter a number.\n"; clearInput(); } }
static string readLine(const string& prompt){ string s; cout<<prompt; getline(cin,s); return s; }

FitnessCenter::FitnessCenter(){ loadData(); }
FitnessCenter::~FitnessCenter(){ saveData(); }
bool FitnessCenter::existsMember(int id) const { for(const auto&m:members) if(m.getId()==id)return true; return false; }
bool FitnessCenter::existsTrainer(int id) const { for(const auto&t:trainers) if(t.getId()==id)return true; return false; }
void FitnessCenter::loadData(){ FileManager::loadMembers(members,memberFile); FileManager::loadTrainers(trainers,trainerFile); FileManager::loadPlans(plans,planFile); FileManager::loadSessions(sessions,sessionFile); }
void FitnessCenter::saveData() const { FileManager::saveMembers(members,memberFile); FileManager::saveTrainers(trainers,trainerFile); FileManager::savePlans(plans,planFile); FileManager::saveSessions(sessions,sessionFile); }

void FitnessCenter::addMember(){
    int id=readInt("Enter member ID: "); if(id<=0||existsMember(id)) throw runtime_error("Member ID must be positive and unique.");
    string name=readLine("Enter member name: "); int age=readInt("Enter age: "); if(age<10||age>100) throw runtime_error("Age must be between 10 and 100.");
    string goal=readLine("Enter fitness goal: "); members.emplace_back(id,name,age,goal); cout<<"Member added successfully.\n";
}
void FitnessCenter::addTrainer(){
    int id=readInt("Enter trainer ID: "); if(id<=0||existsTrainer(id)) throw runtime_error("Trainer ID must be positive and unique.");
    string name=readLine("Enter trainer name: "); string sp=readLine("Enter specialization: "); trainers.emplace_back(id,name,sp); cout<<"Trainer added successfully.\n";
}
void FitnessCenter::createPlan(){
    int pid=readInt("Enter plan ID: "); int mid=readInt("Enter member ID: "); if(!existsMember(mid)) throw runtime_error("Member not found.");
    string ex=readLine("Enter exercises (e.g. Running, Squats): "); int dur=readInt("Enter duration in minutes: "); if(dur<=0) throw runtime_error("Duration must be positive.");
    plans.emplace_back(pid,mid,ex,dur); cout<<"Workout plan created.\n";
}
void FitnessCenter::bookSession(){
    int sid=readInt("Enter session ID: "); int mid=readInt("Enter member ID: "); int tid=readInt("Enter trainer ID: ");
    if(!existsMember(mid)) throw runtime_error("Member not found."); if(!existsTrainer(tid)) throw runtime_error("Trainer not found.");
    string date=readLine("Enter session date (DD-MM-YYYY): "); sessions.emplace_back(sid,mid,tid,date); cout<<"Training session booked successfully.\n";
}
void FitnessCenter::displayRecords() const{
    cout<<"\n--- MEMBERS ---\n"; if(members.empty())cout<<"No members.\n"; for(const auto&m:members)m.display();
    cout<<"\n--- TRAINERS ---\n"; if(trainers.empty())cout<<"No trainers.\n"; for(const auto&t:trainers)t.display();
    cout<<"\n--- WORKOUT PLANS ---\n"; if(plans.empty())cout<<"No plans.\n"; for(const auto&p:plans)p.display();
    cout<<"\n--- SESSIONS ---\n"; if(sessions.empty())cout<<"No sessions.\n"; for(const auto&s:sessions)s.display();
}
void FitnessCenter::searchRecord() const{
    int id=readInt("Enter member ID to search: "); for(const auto&m:members)if(m.getId()==id){cout<<"Record found:\n";m.display();return;} cout<<"Member not found.\n";
}
void FitnessCenter::updateMember(){
    int id=readInt("Enter member ID to update: "); for(auto&m:members) if(m.getId()==id){
        string name=readLine("Enter new name: "); int age=readInt("Enter new age: "); string goal=readLine("Enter new goal: ");
        if(age<10||age>100)throw runtime_error("Invalid age."); m.setName(name);m.setAge(age);m.setGoal(goal);cout<<"Member updated.\n";return; }
    cout<<"Member not found.\n";
}
void FitnessCenter::deleteMember(){
    int id=readInt("Enter member ID to delete: "); for(auto it=members.begin();it!=members.end();++it)if(it->getId()==id){members.erase(it);cout<<"Member deleted.\n";return;} cout<<"Member not found.\n";
}
void FitnessCenter::report() const{
    cout<<"\n========== FITNESS REPORT ==========\n";
    cout<<"Total Members : "<<members.size()<<"\nTotal Trainers: "<<trainers.size()<<"\nTotal Plans   : "<<plans.size()<<"\nTotal Sessions: "<<sessions.size()<<"\n";
    int booked=0;for(const auto&s:sessions)if(s.getStatus()=="Booked")booked++; cout<<"Booked Sessions: "<<booked<<"\n=====================================\n";
}
void FitnessCenter::demonstratePolymorphism() const{
    cout<<"\n--- Runtime Polymorphism Demo ---\n";
    Person* p = new Member(999,"Demo Member",20,"General Fitness");
    p->display();
    delete p;
    cout<<"Base Person pointer called overridden Member::display(). Dynamic memory released using delete.\n";
}
void FitnessCenter::menu(){
    int choice;
    do{
        cout<<"\n========================================\n     FITNESS TRAINING MANAGEMENT\n========================================\n1. Add Record\n2. Display Records\n3. Search Record\n4. Update Record\n5. Delete Record\n6. Main Transaction / Process\n7. Report\n8. Save / Load\n9. Exit\n";
        choice=readInt("Enter choice: ");
        try{
            switch(choice){
                case 1:{cout<<"\n1. Add Member\n2. Add Trainer\n";int x=readInt("Choose: ");if(x==1)addMember();else if(x==2)addTrainer();else cout<<"Invalid choice.\n";break;}
                case 2: displayRecords(); break;
                case 3: searchRecord(); break;
                case 4: updateMember(); break;
                case 5: deleteMember(); break;
                case 6:{cout<<"\n1. Create Workout Plan\n2. Book Training Session\n";int x=readInt("Choose: ");if(x==1)createPlan();else if(x==2)bookSession();else cout<<"Invalid choice.\n";break;}
                case 7: report(); demonstratePolymorphism(); break;
                case 8: saveData(); cout<<"Data saved successfully. Restart the program to verify loading.\n"; break;
                case 9: saveData(); cout<<"Thank you. Data saved.\n"; break;
                default: cout<<"Invalid menu choice.\n";
            }
        }catch(const exception& e){cout<<"Error: "<<e.what()<<"\n";}
    }while(choice!=9);
}
