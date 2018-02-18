#include "binary_tree.h"
// Print top view of the tree

void TopView(const Node *root) 
{
  if (!root)
    return;

  queue<pair<const Node *, int>> level_queue;
  unordered_set<int> set;
  level_queue.push({root, 0});
  int hd;

  while(level_queue.empty() == false) 
  {
    auto value = level_queue.front();
    level_queue.pop();
    int hd = value.second;
    auto node = value.first;
    
    if (set.find(hd) == set.end())
    {
      cout << node->data << " ";
      set.insert(hd);
    }

    if (node->left)
      level_queue.push({node->left, hd - 1});
    
    if (node->right)
      level_queue.push({node->right, hd +1});
    
  }
}

int main()
{
  Tree t;
  Node *root = t.root;
  TopView(root);
}
