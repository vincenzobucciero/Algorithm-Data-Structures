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
    Employee(string name, double salary) { this->name = name; this->salary = salary; }
    void setName(string name) { this->name = name; }
    string getName() { return this->name; }
    void setSalary(double salary) { this->salary = salary; }
    double getSalary() { return this->salary; }
    
    virtual void printInfo();
    
    Employee operator+ (Employee a) {
      Employee tmp("", 0.00);
      tmp.setSalary(this->getSalary() + a.getSalary());
      
      return tmp;
    }
};

void Employee::printInfo() {
  cout << "Employee:  \n" << endl;
  cout << "\tName: " << this->getName() << endl;
  cout << "\tSalary: " << this->getSalary() << "$" <<  endl;
  cout << endl;
}

#endif