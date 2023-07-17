/*
    A manager is an employee who is paid a bonus in addition to salary.
*/

#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include "employee.h"

using namespace std;

class Manager : public Employee {
  private:
    double bonus;
  public:
    Manager(string name, double salary, double bonus) : Employee(name, salary), bonus(bonus) {  }
    double getSalary() { return this->Employee::getSalary() + bonus; }
    void printInfo();
};

void Manager::printInfo() {
  cout << "Manager:  \n" <<  endl;
  cout << "\tName: " << this->getName() << endl;
  cout << "\tSalary: " << this->getSalary() << "$" <<  endl;
  cout << "\tBonus: " << this->bonus << endl;
  cout << endl;
}

#endif