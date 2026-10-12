#ifndef SESSION_H
#define SESSION_H
#include <string>
using namespace std;

class Session {
private:
    int sessionId;
    int memberId;
    int trainerId;
    string date;
    string status;
public:
    Session();
    Session(int sessionId, int memberId, int trainerId, const string& date, const string& status = "Booked");
    ~Session();
    int getSessionId() const;
    int getMemberId() const;
    int getTrainerId() const;
    string getDate() const;
    string getStatus() const;
    void book();
    void cancel();
    void display() const;
    string serialize() const;
};

#endif
