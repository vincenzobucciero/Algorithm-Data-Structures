/**
 * It shows polymorphism in action with a Person class
 * and two derived classes Student and Professor each
 * of which responds differently to the same method of print.
*/

#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
        Person(string s) : nome(s) { }
        virtual void Print() { cout << "il mio nome è:  " << nome << endl; }
    protected:
        string nome;
};

class Student : public Person {
    private:
        float media;
    public: 
        Student(string s, float g) : Person(s), media(g) { }
        void Print() { cout << "il mio nome è:  " << nome << " e la mia media è: " << media << endl; } 
};

class Teacher : public Person {
    private: 
        int articles;
    public:
        Teacher(string s, int n) : Person(s), articles(n) { }
        void Print() { cout << "il mio nome è:  " << nome << " e le mie pubblicazioni sono: " << articles << endl; }
};

int main() {
    Person *p;
    p = new Person("Vincenzo");
    p->Print();
    p = new Student("Giovanni", 28.755);
    p->Print();
    p = new Teacher("Maurizio", 125);
    p->Print();

    return 0;
}