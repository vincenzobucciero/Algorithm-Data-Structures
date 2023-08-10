/**
    • Data una sequenza di interi (rappresentata da un array),
      trovare il k-esimo elemento più grande per ogni i=0..N-1.
        • seq=[10, 3, 21, 1, -1, 45, 8, 12, 78]
        • k=2
        • i=1 k-max=3
        • i=2 k-max=10
        • i=3 k-max=10
        • ...
*/

#include <iostream>
#include <vector>
#include "/home/vincenzo/Desktop/asd/Algorithm-Data-Structures/EserciziSlide-Lezione10/PriorityQueue/Min-priority-Queue/minPriorityQueue.h"

int main(){

  vector<int> seq = {10, 3, 21, 1, -1, 45, 8, 12, 78};
  vector<int>* vec = new vector<int>;
  const int k = 9;

  for (int i=0; i<k; i++)
    vec->push_back(seq.at(i));

  cout << "K=" << k << endl;

  MinPriorityQueue<int>* minQueue = new MinPriorityQueue<int>(vec);
  int min = minQueue->queueMinimum();
  cout << "i=" << k-1 << " k-max=" << min << endl;

  for (int i=k; i<seq.size(); i++){ // n-k * log n
    
    if (seq.at(i) > minQueue->queueMinimum()){
      minQueue->queueExtractMin();
      minQueue->queueInsert(seq.at(i));
    }
    
    cout << "i=" << i << " k-max=" << minQueue->queueMinimum() << endl;
  }

  return 0;
}