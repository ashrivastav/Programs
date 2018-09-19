/* Implementation of MaxHeap */

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class MaxHeap {
  vector<int> arr_;
  int size_;
  
  int Parent(int index)
  {
    return (index/2);
  }
  
  int LeftChild(int index)
  {
    return (index * 2);
  }
  
  int RightChild(int index)
  {
    return ((index * 2) + 1);
  }
  
  /* Used in Pop */
  void PercolateDown(int index)
  {
    int left = LeftChild(index);
    int right = RightChild(index);
    
    int largest = index;
    
    if ( left < size() && arr_[left] > arr_[index])
      largest = left;
    
    if ( right < size() && arr_[right] > arr_[largest])
      largest = right;
    
    if (largest != index)
    {
      swap(arr_[largest], arr_[index]);
      PercolateDown(largest);
    }  
  }
  
  /* Used in Push */
  void PercolateUp(int index)
  {
    int parent = Parent(index);
    
    if (parent > 1 && arr_[parent] < arr_[index])
    {
      swap(arr_[parent], arr_[index]);
      PercolateUp(parent);
    }
    
  }
  
public:
  int size() {
    return arr_.size() -1 ;
  }
  
  int empty() {
    return (size() == 0);
  }
  

  MaxHeap()
  {
    arr_.push_back(INT_MIN); //Index starts from 1
  }
  
  void push(int key)
  {
    arr_.push_back(key);
    PercolateUp(size());
  }
  
  
  int top()
  {
    if (size() == 0)
      throw "Heap Empty";
    
    return (arr_[1]);
  }
  
  void pop()
  {
    arr_[1] = arr_[size()];
    arr_.pop_back();
    PercolateDown(1);
    
  }
};
int main() {
 
  MaxHeap maxHeap;
  maxHeap.push(10);
  maxHeap.push(6);
  maxHeap.push(2);
  maxHeap.push(1);
  maxHeap.push(7);
  maxHeap.push(9);
  maxHeap.push(8);
  
  while (maxHeap.empty() == false)
  {
    cout << maxHeap.top() << endl;
    maxHeap.pop();
  }
  return 0;
}
