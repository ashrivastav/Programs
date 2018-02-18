#include "binary_tree.h"
//Iterative way to find value in binary tree, without recursion


bool FindKey(const Node* root, const int key) {
  
  bool result = false;

  queue<const Node *> q;
  
  if (root == nullptr)
    return false;

  q.push(root);

  while(q.empty() == false) 
  {
    const Node *node = q.front();

    if (node-> data == key)
      return true;

    q.pop();

    if(node->left)
      q.push(node->left);

    if(node->right)
      q.push(node->right);
  
  }
}





int main()
{
  Tree t;
  Node *root = t.root;
  int key = 14;
  cout << "Enter key to find\n" ;
  cin >> key;
  bool result = FindKey(root, key);

  cout << "Key: " << key << "  Is present? " << boolalpha<< result << endl;
}
