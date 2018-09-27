#include"binary_tree.h"

// Print bottom view of the tree
using namespace std;
void BottomView(Node *root) 
{

  if (!root)
    return;

  int hd = 0; // for root
  
  /* Map for storing distance and Node data,
  WE have used MAPS as we want data in sorted order*/
  map<int, int> distanceMap;
  
  /* Queue of pair Node and horizontal distance */
  queue< pair<Node *, int> > nodeQueue;

  nodeQueue.emplace(root, hd);

  while(!nodeQueue.empty())
  {
    pair<Node *,int> node = nodeQueue.front();
    nodeQueue.pop();

    int hDist = node.second;

    distanceMap[hDist] = node.first->data;
    
    if (node.first->left)
      nodeQueue.emplace(node.first->left, hDist -1);

    if (node.first->right)
      nodeQueue.emplace(node.first->right, hDist + 1);
  }

  for (auto &i: distanceMap)
  {
    cout << i.second <<" ";
  }
    
}


void VerticalOrderTraversal(Node *root) 
{

  if (!root)
    return;

  int hd = 0; // for root
  
  /* Map for storing distance and Node data,
  WE have used MAPS as we want data in sorted order*/
  map<int, vector<int> > distanceMap;
  
  /* Queue of pair Node and horizontal distance */
  queue< pair<Node *, int> > nodeQueue;

  nodeQueue.emplace(root, hd);

  while(!nodeQueue.empty())
  {
    pair<Node *,int> node = nodeQueue.front();
    nodeQueue.pop();

    int hDist = node.second;

    distanceMap[hDist].push_back(node.first->data);
    
    if (node.first->left)
      nodeQueue.emplace(node.first->left, hDist -1);

    if (node.first->right)
      nodeQueue.emplace(node.first->right, hDist + 1);
  }

  for (auto &i: distanceMap)
  {
    for (auto &j : i.second) {
      cout << j <<" ";
    }
    cout << endl;
  }
    
}
int main()
{
  Tree t;
  Node *root = t.root;
  cout << "Bottom View:";
  BottomView(root);
  cout << "\nVerticalOrderTraversal";
  VerticalOrderTraversal(root);
}
