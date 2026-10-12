#include "Member.h"
#include <iostream>
using namespace std;
Member::Member() : Person(), age(0), goal("") {}
Member::Member(int memberId, const string& name, int age, const string& goal) : Person(memberId, name), age(age), goal(goal) {}
Member::~Member() {}
int Member::getAge() const { return age; }
string Member::getGoal() const { return goal; }
void Member::setAge(int age) { this->age = age; }
void Member::setGoal(const string& goal) { this->goal = goal; }
void Member::display() const { cout << "ID: " << id << " | Name: " << name << " | Age: " << age << " | Goal: " << goal << '\n'; }
string Member::serialize() const { return to_string(id) + "|" + name + "|" + to_string(age) + "|" + goal; }
