#include <iostream>
#include <vector>


using namespace std;

template<class T>
class Queue {

private:
  T data_;
  vector<T> container_;
  size_t capacity_;
  size_t size_;
  size_t front_;
  size_t rear_;

public:
  Queue(size_t capacity):capacity_(capacity), size_(0),front_(0), rear_(capacity - 1)
  {
    container_.resize(capacity_);
  }

  void Enqueue(T data) 
  {
    if (IsFull())
      throw "Queue Full";

    rear_ = (rear_ + 1) % capacity_;
    container_[rear_] = data;
    size_++;
  }

  T Dequeue()
  {
    if(IsEmpty())
      throw "Queue Empty";

    T data = container_[front_];
    front_ = (front_ + 1) % capacity_;
    size_--;
    return data;
  }

  bool IsFull()
  {
    if (size_ == capacity_)
      return true;
    else
      return false;
  }

  bool IsEmpty()
  {
    if (size_ == 0)
      return true;
    else
      return false;
  }

  size_t Size()
  {
    return size_;
  }

};


int main()
{
  Queue<int> q(100);
  q.Enqueue(10);
  q.Enqueue(20);
  q.Enqueue(30);
  q.Enqueue(40);
  int val = q.Dequeue();
  cout << val << endl;
  q.Enqueue(50);
  q.Enqueue(60);
  q.Enqueue(70);
  q.Enqueue(80);
  while (q.Size() != 0)
  {
  int val = q.Dequeue();
  cout << val << endl;
  }
  return 0;
}
