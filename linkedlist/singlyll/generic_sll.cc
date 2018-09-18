/* Generic Singly Linked List For Various Operation */
#include <iostream>
using namespace std;
template<typename T>
class LinkedList {
 struct Node {
    T data_;
    Node *next_;
    Node(T data): data_(data), next_(nullptr) {}
  };
  
  Node *head_ = nullptr;
  
public:
  
  void AddToFront(T data)
  {
    if (head_ == nullptr)
    {
      head_ = new Node(data);
      goto done;
    }
    
    Node *temp;
    temp = head_;
    head_ = new Node(data);
    head_->next_ = temp;
    
  done:
    return;
    
  }
  
  void PrintList()
  {
    Node *temp;
    for(temp = head_; temp != nullptr; temp = temp->next_)
      cout << " " << temp->data_ ;
    cout << endl;
  }
  
  void Reverse()
  {
    Node *prev = nullptr;
    Node *current = head_;
    Node *next;
    
    while(current != nullptr)
    {
      next = current->next_; // Save next pointer of current
      current->next_ = prev; // Assign prev to next pointer of current
      // We are done for this loop
      prev = current; // Prepare for next loop, make current node prev
      if (next == nullptr) //Reached end of list
        head_ = current; // reset head
      current = next; // make next node current and loop
      
    }
  }

  void AddOne()
  {
    Reverse();
    int carry = 1; //Number to add once (ie.1)
    int sum = 0;
   for (Node *temp = head_; temp != nullptr; temp = temp->next_)
    {
        sum = temp->data_ + carry;
        carry = 0;
      if(sum % 10 == 0) {
         carry = 1;
        sum = 0;
      }
      
      temp->data_  = sum;
     }
    Reverse();
    if (carry == 1)
      AddToFront(1);
    
  }

   void RReverse() 
   {
     head_ = RReverseUtil(head_);
   }
  
  Node* RReverseUtil(Node *current)
  {
    Node *new_head = nullptr;
    if (current && current->next_)
    {
      new_head = RReverseUtil(current->next_);
      current->next_->next_ = current;
      current->next_ = nullptr;
    } else
    {
      new_head = current;
    }
    
    return new_head;
  }
};

template<typename T>
void RReverse(LinkedList<T> &list)
{ 
  list.AddToFront(11);
  list.AddToFront(2);
  list.AddToFront(3);
  cout << "Orig List is:" ;
  list.PrintList();
  cout << "Printing reverse list:";
  list.RReverse();
  list.PrintList();
  cout <<endl;
}

template<typename T>
void Reverse(LinkedList<T> &list)
{ 
  list.AddToFront(10);
  list.AddToFront(20);
  list.AddToFront(30);
   cout << "Orig List is:" ;
  list.PrintList();
  cout << "Printing reverse list:";
  list.Reverse();
  list.PrintList();
}

template<typename T>
void AddOne(LinkedList<T> &list)
{
  list.AddToFront(9);
  list.AddToFront(9);
  list.AddToFront(1);
   cout << "Orig List is:" ;
  list.PrintList();
  cout << "Adding one to it:";
  list.AddOne();
  list.PrintList();
}

int main() {
  LinkedList<int> list;
  Reverse(list);
  RReverse(list);
  LinkedList<int> list1;
  AddOne(list1);
  
  return 0;
}