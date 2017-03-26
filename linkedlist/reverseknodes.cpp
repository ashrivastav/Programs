#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Revese k elements here k = 3

struct Node {
    Node *next;

    int data;

    Node(int val): next(nullptr), data(val){};
};

void insert(Node * &head, int val)
{
    Node *new_node = new Node(val);

    if(new_node)
    {
        new_node->next = head;
        head = new_node;
    }
}


void printlist(Node *head)
{
    while(head)
    {
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;
}

Node *reverse_alternate(Node *head, int count)
{
    Node *curr = head;

    Node *prev = nullptr, *next;
    int num = count;

    while(curr != nullptr && num--)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    if(head)
        head->next = next;

   num = count;
   while(curr != nullptr && --num)
       curr = curr->next;
   
   if(curr)
        curr->next = reverse_alternate(curr->next, count);
   
   return prev;
}


Node* reversekelem(Node* head, int count)
{
    Node *curr = head;
    Node *next, *prev = nullptr;
    int n = count;

    while(curr != nullptr && n--)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    if(head)
        head->next = reversekelem(next, count);
    return prev;
}

/* Elegant and awesome recusion*/
Node* reverse_recur(Node *curr)
{
    Node *new_head = nullptr; // Return new head after recursion ends
    if(curr->next)
    {
        new_head = reverse_recur(curr->next); // return new_head after each call
        curr->next->next = curr; // Pointer manipulation, make curr->next->next point to current node
        curr->next = nullptr; // make current next to null 
    } 
    else
      new_head = curr; // Assign new head when recusion ends

   return new_head; // return new_head always
}

void delete_elems(Node *head)
{
    if(!head)
        return;

    int max = head->data;

    while(head->next)
    {
        if(head->next->data < max)
        {
            Node *next = head->next;
            head->next = head->next->next;
            delete next;
        } else{
            head = head->next;
        }
    max = head->data;
    }

}

Node * delete_rg(Node *curr)
{
    Node *head = reverse_recur(curr);

    delete_elems(head);

    return reverse_recur(head);
}

int main()
{
    Node *head = nullptr;

    random_device r;//get random device for seed

    mt19937 gen(r()); // initialize generator with seed

    uniform_int_distribution<int> dis; // which type of random number is needed

    for(int i =12; i > 0 ;i--)
    {
        insert(ref(head), dis(gen) % 20000);
    }

    printlist(head);

    head = reversekelem(head, 4);
    printlist(head);
    
    head = reversekelem(head, 4);
    printlist(head);

    head = reverse_alternate(head, 3);
    printlist(head);

    head = reverse_recur(head);
    printlist(head);

    head = delete_rg(head);
    printlist(head);

}
