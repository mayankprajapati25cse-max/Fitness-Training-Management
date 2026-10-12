#include "Session.h"
#include <iostream>
using namespace std;
Session::Session() : sessionId(0), memberId(0), trainerId(0), date(""), status("Booked") {}
Session::Session(int sessionId, int memberId, int trainerId, const string& date, const string& status) : sessionId(sessionId), memberId(memberId), trainerId(trainerId), date(date), status(status) {}
Session::~Session() {}
int Session::getSessionId() const { return sessionId; }
int Session::getMemberId() const { return memberId; }
int Session::getTrainerId() const { return trainerId; }
string Session::getDate() const { return date; }
string Session::getStatus() const { return status; }
void Session::book() { status = "Booked"; }
void Session::cancel() { status = "Cancelled"; }
void Session::display() const { cout << "Session ID: " << sessionId << " | Member ID: " << memberId << " | Trainer ID: " << trainerId << " | Date: " << date << " | Status: " << status << '\n'; }
string Session::serialize() const { return to_string(sessionId) + "|" + to_string(memberId) + "|" + to_string(trainerId) + "|" + date + "|" + status; }
