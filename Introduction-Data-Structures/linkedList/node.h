//class node for linked list

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "employee.h"

using namespace std;

class Node {
  private:
    Employee *info;
    Node *nextNode;
  public:
    Node(Employee *info) { this->info = info; this->nextNode = nullptr; }
    ~Node() { delete info; delete nextNode; }
    
    void setInfo(Employee *info) { this->info = info; }
    Employee *getInfo() { return this->info; }
    
    void setNext(Node *nextNode) { this->nextNode = nextNode; }
    Node *getNext() { return this->nextNode; }
};


#endif