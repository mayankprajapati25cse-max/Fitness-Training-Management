#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
public:
    Person();
    Person(int id, const string& name);
    virtual ~Person();
    int getId() const;
    string getName() const;
    void setName(const string& name);
    virtual void display() const = 0;
};

#endif
