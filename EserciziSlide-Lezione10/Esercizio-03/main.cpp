/**
 * Dato un array di n elementi, trovare il massimo numero di elementi distinti dopo aver rimosso k elementi (k<=n)
 *      Es.: {5,4,4,3,4,6,2,1,2}, per k=2 maxnum=5(5,3,6,2,1), per k=3 maxnum=6(5,4,3,6,2,1)
*/

#include<iostream>
#include<map>
#include<vector>
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/EserciziSlide-Lezione10/PriorityQueue/Max-Priority-Queue/maxPriorityQueue.h"
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/EserciziSlide-Lezione10/PriorityQueue/Min-priority-Queue/minPriorityQueue.h"

using namespace std;

int main(){

    vector<int> sequenza{5,4,4,3,4,6,2,1,2};
    MaxPriorityQueue <int> albero = MaxPriorityQueue<int>();
    map<int,int> occorrenze;
    map<int,int>::iterator it;
    vector<int>::iterator jt;
    int num,k=2;

    for (int i = 0; i < sequenza.size(); i++)    
    {
        num = sequenza.at(i);

        it = occorrenze.find(num);

        if (it == occorrenze.end())
        {
            occorrenze.insert(make_pair(num,1));    //inserisce correttamente il numero (numero,occorrenza)
        }
        else{
            occorrenze.at(num)++;
        }
        
    }

    for (it = occorrenze.begin(); it != occorrenze.end(); it++){

        cout<< (*it).first << " ---> " << (*it).second <<endl;  //first() indica il numero mentre second l'occorrenze()
    }
    
    for (it = occorrenze.begin();it != occorrenze.end(); it++){

        albero.queueInsert((*it).second);    
    }
    
    albero.printingTree();

    for (int i = 0; i < k; i++)
    {
        int max = albero.queueMaximum();
        it = occorrenze.begin();

        jt = sequenza.begin();

        while ((*it).second != max)
        {
            it++;
        }

        while ((*jt) != (*it).first )
        {
            jt++;
        }
        
        sequenza.erase(jt);
        albero.queueDecreaseKey(0,max-1);
        
        cout<<"Decremento l'occorrenza..."<<endl;
        albero.printingTree();
        cout<<endl;

    }
    
        cout<<"Ecco gli elementi più distinti:"<<endl;
        for (int i = 0; i < sequenza.size(); i++){
            cout<<" "<<sequenza.at(i);
        }
        cout<<endl;
    return 0;
}