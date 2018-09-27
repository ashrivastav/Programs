#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#include <tuple>
#include <map>
#include <limits.h>
#include <unordered_set>
#include <unordered_map>
#include <stack>


/* A tree node structure */
struct Node {
    int data;
    Node *left;
    Node *right;
    Node *nextright;
    Node(int val):data(val), left(NULL), right(NULL)
    {}

    bool IsLeaf() {
      if (left == nullptr && right == nullptr) {
        return true;
      }
      return false;
    }
      
};

/* Bottom View: 16 8 4 12 6 14 7 15 31 */
/* Vertical order:
16 
8 
4 
2 9 10 12 
1 5 6 
3 11 13 14 
7 
15 
31 
*/

class Tree {
  public: 
  Node *root;
  Tree() {
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
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
  }
};

