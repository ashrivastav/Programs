#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == NULL)
        return NULL;
        
    if(A->left == NULL && A->right == NULL)
        return A;
        
    TreeNode *right = A->right;
    A->right = flattenHelper(A->left);
    A->left = NULL;
    A->right->right = flattenHelper(right);
    
}


int main();
