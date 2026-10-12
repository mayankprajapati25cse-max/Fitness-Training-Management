#ifndef TRAINER_H
#define TRAINER_H
#include "Person.h"

class Trainer : public Person {
private:
    string specialization;
public:
    Trainer();
    Trainer(int trainerId, const string& name, const string& specialization);
    ~Trainer() override;
    string getSpecialization() const;
    void setSpecialization(const string& specialization);
    void display() const override;
    string serialize() const;
};

#endif
