/**
 * La blockchain è una struttura dati composta da una lista di
 * blocchi all'interno dei quali è memorizzato un insieme di
 * transazioni.
*/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include "node.h"
#include "transaction.h"

template <typename T>
class List {
    private:
        Node<T> *head;
        Node<T> *tail;
    public:
        List();
        ~List();

        void setHead(Node<T> *head);
        Node<T> *getHead();

        void setTail(Node<T> *tail);
        Node<T> *getTail();

        void insNode(T *info);

        bool isEmpty();
};

template <typename T>
List<T>::List(){
    head =  nullptr;
    tail = nullptr;
}

template <typename T>
List<T>::~List(){
    while(this->head != nullptr){
        Node<T> *tmp = head;
        head = head->getNext();
        delete tmp;
    }
}

template <typename T>
void List<T>::setHead(Node<T> *head){
    this->head= head;
}

template <typename T>
Node<T> *List<T>::getHead(){
    return head;
}

template <typename T>
void List<T>::setTail(Node<T> *tail){
    this->tail= tail;
}

template <typename T>
Node<T> *List<T>::getTail(){
    return tail;
}

template <typename T>
void List<T>::insNode(T *info){
    Node<T> *ins = new Node<T>(info);
    if(!this->isEmpty()){
        tail->setNext(info);
        tail = ins;
    } else {
        head = tail = ins;
    }
}

template <typename T>
bool List<T>::isEmpty(){
    if(this->head == nullptr){
        return true;
    }
    return false;
}



#endif