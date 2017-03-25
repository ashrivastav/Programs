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


int main()
{
    Node *head = nullptr;

    for(int i =12; i > 0 ;i--)
    {
        insert(ref(head), i);
    }


    printlist(head);

    head = reversekelem(head, 4);
    printlist(head);
    head = reversekelem(head, 4);

    printlist(head);

    head = reverse_alternate(head, 3);

    printlist(head);
}
