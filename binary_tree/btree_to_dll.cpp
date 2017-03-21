/* Program to convert a binary tree to circular doubly linked list */
/* THE GREAT RECURSION TREE PROBLEM */
/* Author: Abhishek Shrivatav */

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
/* Convert tree to circular doubly linked list */
/* Inorder traversal, Work between two recursive calls for making cll */
void btree_to_dll(Node *root, Node* &prev, Node* & head)
{
	// If null return
    if(root == NULL)
        return;

    /* Recursively go left to find head*/
    btree_to_dll(root->left, prev, head);  //---> first recursive

    /* During unwinding change intermediate node properly */
    if(prev)
    {
        prev->right = root;
        root->left = prev;
    }
    else /* Initially prev is null and hence this is the first
    	unwinding from left we will assign head here, Only called once */
        head = root;
    
    prev = root; // Always make current node as prev

    /* Recurse on right childs */
    btree_to_dll(root->right, prev, head); // -->second recursive

    /* This makes last node to point to head and head point to last node in dll, making it circular */
    if(!root->right)
    {
    	root->right = head;
    	head->left = root;
    }
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
    root->right->left = new Node(12);
    root->right->left->right = new Node(21);
    root->left->left = new Node(20);
    root->left->right = new Node(55);
    root->left->left->left = new Node(10);
    root->left->left->right = new Node(30);
    root->left->left->right->left = new Node(25);
    root->left->left->right->right = new Node(35);
}


void print_ll(Node *head)
{
	if(head == NULL)
		return;
	Node *local_head = head;
	Node *tail = nullptr;
	do{
		cout << local_head->data <<  " --> ";
		tail = local_head;
		local_head = local_head->right;
	} while(local_head != head);
	cout << endl;
	cout << "Head data: " << head->data << endl;
	cout <<"Head left: " << head->left->data << endl; // Global head left
	cout <<"Tail right:" << tail->right->data << endl; // Tail right
}

int main()
{
    Node *root = new Node(100);
    Node *head = NULL;
    Node *prev = NULL;
    create_tree(root);

    btree_to_dll(root, prev, head);

    Node *temp = head;

    print_ll(head);

    cout << endl;
} 
