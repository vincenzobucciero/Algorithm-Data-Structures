/**
 * Progettare ed implementare una lista (linked list) di
 * impiegati di un'azienda. Un impiegato ha un nome ed un
 * salario. Un manager è un impiegato cui viene corrisposto
 * un bonus oltre al salario.
 *      1. Creare una lista di impiegati e stamparla a video
 *          sfruttando il principio del polimorfismo
 *      2. Implementare l'overload dell'operatore + in modo da
 *          sommare i salari di tutti gli impiegati.
*/

#include <iostream>
#include "employee.h"
#include "manager.h"
#include "list.h"

using namespace std;

int main() {
  List *testList = new List();
  testList->insList(new Employee("Vincenzo", 1500.00));
  testList->insList(new Manager("Sebastian", 3000.00, 1000.00));
  testList->insList(new Employee("Camilla", 1300.00));
  testList->insList(new Employee("Carmine", 800.00));
  testList->insList(new Manager("Antonio", 1500.00, 1000.00));
  
  testList->printList();
  
 testList->TotSalary();
  
  return 0;
}

