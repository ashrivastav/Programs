#include "binary_tree.h"
// Print bottom view of the tree

void BottomView(const Node *root, int hd, auto &set) 
{
  if (!root)
    return;

  if (root->left)
    BottomView(root->left, hd -1, set);

  if (root->right)
    BottomView(root->right, hd + 1, set);

  if (set.find(hd) == set.end())
    {
      cout << root->data << " ";
      set.insert(hd);
    }
}

int main()
{
  Tree t;
  Node *root = t.root;
  unordered_set<int> set;
  BottomView(root, 0, set);
}
