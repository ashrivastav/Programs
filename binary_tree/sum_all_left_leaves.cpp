// Sum of all left leaves of a binary tree
#include "binary_tree.h"


int LeftLeafSumUtil(const Node *root, int &sum) {
  
  if (!root)
    return 0;

  if (root->left && (root->left)->IsLeaf()) {
    sum = sum + root->left->data;
    return sum;
  }

  LeftLeafSumUtil(root->left, sum);
  LeftLeafSumUtil(root->right, sum);
}


int LeftLeafSum(Node *root) {

  int leftLeafSum = 0;
  
  leftLeafSum = LeftLeafSumUtil(root, leftLeafSum);

  return leftLeafSum;
}

int main()
{
  Tree t;
  Node *root = t.root;

  cout << "Left leaf sum in tree is " << LeftLeafSum(root);
}
