#ifndef MEMBER_H
#define MEMBER_H
#include "Person.h"

class Member : public Person {
private:
    int age;
    string goal;
public:
    Member();
    Member(int memberId, const string& name, int age, const string& goal);
    ~Member() override;
    int getAge() const;
    string getGoal() const;
    void setAge(int age);
    void setGoal(const string& goal);
    void display() const override;
    string serialize() const;
};

#endif
