#include "binary_tree.h"
// Print all nodes from min level to max level

void printLevels(const Node *root, const int minLvl, 
                 const int maxLvl) 
{
  if (!root)
    return;

  queue<pair<const Node *, int>> level_queue;

  level_queue.push({root, 0});
  int oldLevel = 0;
  while(level_queue.empty() == false) 
  {
    auto value = level_queue.front();
    level_queue.pop();
    int level = value.second;
    auto node = value.first;
    
    if (level != oldLevel)
     cout << endl;
    
    if (level >= minLvl && level <= maxLvl)
      cout << node->data << " ";

    oldLevel = level;

    if (node->left)
      level_queue.push({node->left, level + 1});
    
    if (node->right)
      level_queue.push({node->right, level +1});
    
  }
}

int main()
{
  Tree t;
  Node *root = t.root;
  int minLevel, maxLevel;
  cin >> minLevel;
  cin >> maxLevel;

  printLevels(root, minLevel, maxLevel);
}
