#include "binary_tree.h"

int findMax(Node *root) {

  int maxValue = 0;
  int nodeValue;
  int leftMaxValue;
  int rightMaxValue;

  if (!root)
    return 0;

  nodeValue = root->data;
  leftMaxValue = findMax(root->left);
  rightMaxValue = findMax(root->right);

  if (leftMaxValue > rightMaxValue)
    maxValue = max(leftMaxValue, nodeValue);
  else 
    maxValue = max(rightMaxValue, nodeValue);

  return maxValue;
}

int main()
{
  Tree t;
  Node *root = t.root;

  cout << "Max value is " << findMax(root);
}
