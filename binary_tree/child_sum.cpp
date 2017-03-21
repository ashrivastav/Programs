/*
 * child_sum.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: abhishek
 */

#include <iostream>
using namespace std;

/* A tree node structure */
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val):data(val), left(NULL), right(NULL)
    {}
};

/* Return a new node */
Node* insert(int val)
{
    Node *new_node = new Node(val);
    return new_node;
}

bool child_sum(Node *root)
{
	int left_data = 0, right_data =0;

	/* leaf nodes and null will return true */
	if(root == nullptr || ( root->left == nullptr && root->right == nullptr)){
			return true;
	}
	if(root->left)
		left_data = root->left->data;

	if(root->right)
		right_data = root->right->data;

	return ((root->data == left_data + right_data) && child_sum(root->left) && child_sum(root->right));

}

void fix_child_sum(Node *root)
{
	if(root == nullptr || (root->left == nullptr & &root->right == nullptr))
		return;

	fix_child_sum(root->left);
	fix_child_sum(root->right);

	if(root->left && root->right)
		root->left->data = root->data - root->right->data;
	else if(root->left)
		root->data = root->left->data;
	else if(root->right)
		root->data = root->right->data;
}

void inorder(Node *root)
{
	if(root)
	{
	inorder(root->left);
	cout << root->data <<" " ;
	inorder(root->right);
	}
}

int height(Node *root)
{
	if(root == nullptr)
		return 0;

	return max(height(root->left), height(root->right)) + 1;
}

bool is_balanced(Node *root)
{
	if(root == nullptr)
		return true;

	auto left_height = height(root->left);
	auto right_height = height(root->right);

	return((abs(left_height - right_height) <=1)
			&& is_balanced(root->left)
			&& is_balanced(root->right));
}
int main()
{
	Node *root = new Node(100);
    root->left = new Node(11);
    root->right = new Node(90);
    root->left->left = new Node(40);
    root->left->right = new Node(20);
   // root->right->left = new Node(7);
    //root->right->right = new Node(33);
    //root->right->right->right = new Node(32);

    inorder(root);
    auto result = child_sum(root);

    cout << "Result is " << std::boolalpha << result << endl;

    cout << "Tree is balanced? :" << boolalpha << is_balanced(root);

/*
    fix_child_sum(root);
    result = child_sum(root);

    cout << " After changing Result is " << std::boolalpha << result << endl;

    inorder(root);

    cout << endl;

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    root->left->left->left->left = new Node(16);
    root->right->right->right->right = new Node(31);
*/
}

