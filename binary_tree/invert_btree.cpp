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

/* Return a new node */
TreeNode* insert(int val)
{
    TreeNode *new_node = new TreeNode(val);
    return new_node;
}

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
/*
TreeNode* flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


    if (A == NULL)
        return NULL;



    if(A->left)
        if(A->right)
            flatten(A->right);
     A->left = NULL;    
    

     if(right)
            A->right->right = right;

     if(right)
           flatten(A->right->right);

    return A;
   }

*/

void invert_tree(TreeNode *root)
{
    if(root == NULL)
        return;

    invert_tree(root->left);
    invert_tree(root->right);

    TreeNode *temp;

    temp = root->left;
    root->left = root->right;
    root->right = temp;

}

void preorder(TreeNode *root)
{
    if(root == NULL)
        return;
        
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


int main()
{
    TreeNode *root = new TreeNode(1);
    create_tree(root);
    preorder(root); cout << endl;
    invert_tree(root);
    preorder(root); cout << endl;
} 
