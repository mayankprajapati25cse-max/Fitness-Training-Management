#include "Trainer.h"
#include <iostream>
using namespace std;
Trainer::Trainer() : Person(), specialization("") {}
Trainer::Trainer(int trainerId, const string& name, const string& specialization) : Person(trainerId, name), specialization(specialization) {}
Trainer::~Trainer() {}
string Trainer::getSpecialization() const { return specialization; }
void Trainer::setSpecialization(const string& specialization) { this->specialization = specialization; }
void Trainer::display() const { cout << "ID: " << id << " | Trainer: " << name << " | Specialization: " << specialization << '\n'; }
string Trainer::serialize() const { return to_string(id) + "|" + name + "|" + specialization; }
