#include <iostream>
#include <thread>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <functional>
#include <sstream>


using namespace std;

template<typename T>
class Queue_ts {
  private:
    queue<T> queue_;
    atomic<long long> size_; 
    mutex qmutex_;
    condition_variable cv_;

  public:
    Queue_ts(): size_(0) {}

    void pop( T& value) {
      unique_lock<mutex> hold(qmutex_);

      cv_.wait(hold,[this] {return !queue_.empty();}); // sleep if queue is empty, otherwise if queue is not empty 
                                                       // move forward
      value =  queue_.front();
      queue_.pop();
      size_--;
    }

    void push( T& value) {
      lock_guard<mutex> hold(qmutex_);
      queue_.push(value);
      size_++;
      cv_.notify_all();
      }

    /* Can be useful to wait for queue object */
    bool empty() const {
      if (size_ == 0)
        return true;

    return false;
    }

  };

template<typename T>
class Worker {
  public:
    void producers()
    {
      thread::id tid = this_thread::get_id(); 
      stringstream stream;
      //stream << "\nStarting Producer" << tid << endl;
      //cout << stream.str();
      stream.str("");

      for (T i =0; i <= 10000000; i++){
        queue_.push(i); 
     // stream << "\nProduce ->" << i << " \n";
        cout << stream.str();
        stream.str("");
      }
    }

    void consumers()
    {
      thread::id tid = this_thread::get_id(); 
      stringstream stream;
     // stream << "\nStarting consumer" << tid << endl;
     // cout << stream.str();
      T data;
      while (data < 10000000) {
       queue_.pop(data); // pop it will sleep/block if queue is empty, and return data as soon as it is available
       stream.str("");
   //  stream << "\nConsumer: " <<data << "\n ";
       cout << stream.str();
      }
    }

  private:
    Queue_ts<T> queue_;
};

int main(){
  cout.sync_with_stdio(true);
  Worker<long long> ws;
  vector<thread> thread_vec;
  const int num_threads = thread::hardware_concurrency(); //8 On my system
  for (int i =0; i < num_threads; i++) {
  thread_vec.push_back(thread{&Worker<long long>::producers, &ws});
  thread_vec.push_back(thread{&Worker<long long>::consumers, &ws});
  }

  for(auto &i : thread_vec)
  i.join();
  
} 
