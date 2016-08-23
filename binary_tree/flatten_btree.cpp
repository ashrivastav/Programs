#include <iostream>
#include <deque>

using namespace std;

/* A tree node structure */
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val):data(val), left(NULL), right(NULL)
    {}
};

void create_tree(TreeNode *root)
{
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
//    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(6);
/*    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);
 
    root->left->left->left->left = new TreeNode(16);
    root->right->right->right->right = new TreeNode(31);
*/

}

void flatten(TreeNode* A) {
    
    if (A == NULL)
        return;
    TreeNode * node = A;
    while(node)
    {
        if(node->left)
        {
            TreeNode *rightMost = node->left;
            while(rightMost->right)
                rightMost = rightMost->right;

            rightMost->right = node->right;

            node->right = node->left;
            node->left = NULL;
        }
         
        node = node->right;
    }
}
            
int main()
{
    TreeNode *root = new TreeNode(1);
    create_tree(root);
    flatten(root);
    TreeNode *temp = root;
    while(temp->right != NULL)
    {
        cout << temp->data << endl;
        temp = temp->right;
    }
} 
