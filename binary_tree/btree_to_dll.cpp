#include <iostream>
#include <deque>

using namespace std;

/* A tree node structure */
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val):data(val), left(NULL), right(NULL)
    {}
};

void btree_to_dll(Node *root, Node* &prev, Node* & head)
{
    if(root == NULL)
        return;

    btree_to_dll(root->left, prev, head);

    root->left = prev;

    if(prev)
        prev->right = root;
    else
        head = root;

    
    prev = root;

    btree_to_dll(root->right, prev, head);
}

/* Return a new node */
Node* insert(int val)
{
    Node *new_node = new Node(val);
    return new_node;
}

void create_tree(Node *root)
{
    root->left = new Node(50);
    root->right = new Node(200);
    root->left->left = new Node(20);
    root->left->right = new Node(55);
    root->left->left->left = new Node(10);
    root->left->left->right = new Node(30);
    root->left->left->right->left = new Node(25);
    root->left->left->right->right = new Node(35);
}


int main()
{
    Node *root = new Node(100);
    Node *head = NULL;
    Node *prev = NULL;
    create_tree(root);
    btree_to_dll(root, prev, head);
    Node *temp = head;
    Node *tail;
    while(temp)
    {
        cout << temp->data << " --> " ;
        tail = temp;
        temp = temp->right;
    }

    cout << endl;
    while(tail)
    {
        cout << tail->data << " -- " ;
        tail = tail->left;
    }

    cout << endl;
} 
