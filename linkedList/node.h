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
        Node(Employee *info);
        ~Node();

        void setInfo(Employee *info);
        Employee *getInfo();

        void setNext(Node *nextNode);
        Node *getNext();
};

Node::Node(Employee *info) {
    this->info = info;
    this->nextNode = nullptr;
}
Node::~Node() {
    delete info;
    delete nextNode;
}

void Node::setInfo(Employee *info) {
    this->info = info;
}
Employee* Node::getInfo() {
    return info;
}

void Node::setNext(Node *nextNode) {
    this->nextNode = nextNode;
}
Node* Node::getNext() {
    return nextNode;
}


#endif