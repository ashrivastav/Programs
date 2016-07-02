#include <iostream>


struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;


void Reverse()
{
    struct Node *curr, *prev;
    curr = head;
    prev = NULL;

    while(curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        curr->next = prev;
        curr = curr->next;
        prev->next = curr;

    }
}










