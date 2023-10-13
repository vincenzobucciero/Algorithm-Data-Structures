#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class hashElement {
public:
    char key;
    int value;
    hashElement(char k, int v) : key(k), value(v) { }
};


class hashTable {
private:
    vector<list<hashElement>> table;
    int size;
    int hash(char key) {return static_cast<int>(key) % size;}
public:
    hashTable(int s) : size(s) {table.resize(size);}

    void insert(char key, int value) {
        int index = hash(key);
        table[index].emplace_back(key, value);
    }

    void increment(char key) {
        int index = hash(key);
        for(auto& element : table[index]) {
            if(element.key == key) {
                element.value++;
                return;
            }
        }
        insert(key, 1);
    }

    void printToFile(const string& filename) {
        ofstream outputFile(filename);
        for(const auto& bucket : table) {
            for(const auto& element : bucket) {
                outputFile << "Carattere -> [ " << element.key << " ] => Occorrenza -> [ " << element.value << " ]" << endl;
            }
        }
    }

    int searchCharacter(char keyToFind) {  
        int index = hash(keyToFind);
        for(const auto& element : table[index]) {
            if(element.key == keyToFind)  
                return element.value;  
        }
    }

    void removeCharacter(char keyToRemove) {
        int index = hash(keyToRemove);
        auto& bucket = table[index];
        for(auto it = bucket.begin(); it != bucket.end(); ++it) {
            if(it->key == keyToRemove)
                bucket.erase(it);
                return;
        }
    }

    vector<list<hashElement>> getTable() {
        return table;
    }
};

int main() {
    hashTable myHash(256);
    ifstream inputFile("fileInput.txt");

    char ch;
    while(inputFile.get(ch)) {
        myHash.increment(ch);
    }
    inputFile.close();

    myHash.printToFile("fileOutput.txt");

    return 0;
}

