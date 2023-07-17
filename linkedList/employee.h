//employee class to fill linked list

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee {
    private:
        string name;
        double salary;
    public:
        Employee(string name, double salary);
        //~Employee();
        void setName(string name);
        void setSalary(double salary);
        string getName();
        double getSalary();
        virtual void printInfo();
};

Employee::Employee(string name, double salary) {
    this->name = name;
    this->salary = salary;
}

void Employee::setName(string name) {
    this->name = name;
}
string Employee::getName() {
    return name;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}
double Employee::getSalary() {
    return salary;
}

void Employee::printInfo() {
    cout << "Employee: " << endl;
    cout << "\tName: " << this->getName() << endl;
    cout << "\tSalary: " << this->getSalary() << "$" << endl;
}

#endif