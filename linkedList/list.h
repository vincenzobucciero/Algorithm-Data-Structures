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
    List() { this->head = nullptr; this->tail = nullptr; }
    ~List() {
      while (this->head != nullptr) {
            Node *tmp = head;
            head = head->getNext();
              delete tmp;
      }
    }
    
    void setHead(Node *head) { this->head = head; }
    Node *getHead() { return this->head; }
    
    void setTail(Node *tail) { this->tail = tail; }
    Node *getTail() { return this->tail; }
    
    void printList() {
      Node *node = head;
      while(node != nullptr) {
        node->getInfo()->printInfo();
        node = node->getNext();
        cout << endl;
      }
    }
    
    void insList(Employee *info) {
      Node *insNode = new Node(info);
      if(!isEmpty()) {
        tail ->setNext(insNode);
        tail = insNode;
      } else {
        tail = head = insNode;
      }
    }
    
    bool isEmpty() {
      if(this->head == nullptr)
        return true;
      else
        return false;
    }
    
    void TotSalary() {
      Node *node = head;
      Employee sum("", 0.00);
      
      while(node !=nullptr) {
        Employee tmp("", node->getInfo()->getSalary());
        sum = sum + tmp;
        node = node->getNext();
      }
      cout << "Employee salary tot:  " << sum.getSalary() << "$" << endl;
    }
};

#endif