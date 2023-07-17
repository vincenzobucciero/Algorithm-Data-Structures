//Linked list

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "employee.h"
#include "node.h"

class List {
    private:
        Node *head;
        Node *tail;
    public:
        List();
        ~List();

        void setHead(Node *head) { this->head = head; }
        Node* getHead() { return head; }

        void setTail(Node *tail) { this->tail = tail; }
        Node* getTail() { return tail; }

        void printList();

        void insList(Employee *info);

        bool isEmpty();
};

List::List() {
    head = nullptr;
    tail = nullptr;
}

List::~List() {
    while(this->head != nullptr) {
        Node *tmp = head;
        head = head->getNext();
        delete tmp; //delete the node from memory and free up its space in heap
    }
}

void List::printList() {
    Node *node = head;
    while(node != nullptr) {
        node->getInfo()->printInfo();
        node = node->getNext();
        cout << endl;
    }
}

bool List::isEmpty() {
    if(this->head == nullptr) {
        return true;
    }
    return false;
}

void List::insList(Employee *info) {
    Node *insNode = new Node(info);
    if(!isEmpty()) {
        tail->setNext(insNode);
        tail = insNode;
    } else {
        tail = head = insNode;
    }
}

#endif