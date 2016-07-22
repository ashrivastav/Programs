#include<malloc.h>
#include<stdlib.h>

/* Program for performing various operations on trees (Binary Search tree Included) */

/* Structure for Binary tree node */
struct node{
	int data;
	struct node *left;
	struct node *right;
};

/*Create a new node */
struct node* create(int val)
{

	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=val;
	return (temp);
}

/* Insert into binary search tree */
struct node* insert(struct node *new,int val)
{
	/* If new node is the first node or any of its childs points to NULL(end of recursion), then return the newly created node*/
	if(new==NULL)
		return(create(val));
	/* If node data is less than the newly inserted data, then insert into the right child recursively*/
	else if (new->data <= val)
		new->right = insert(new->right,val);
	/* If node data is greater than the newly inserted data, then insert into the left child recursively */
	else if (new->data > val)
		new->left = insert(new->left,val);
	
	/* In case of recursion(intermediate) assign same node to itself(No change in pointers in intermediate recursion */
	return (new);
}

/* Inorder traversal of a tree rooted at r */
void inorder(struct node *r)
{
	if(r)
	{	
	inorder(r->left);
	printf("%d ",r->data);
	inorder(r->right);
	}

}

/* Depth of the tree */
/* The main concept here is that at the time of merging, compare the results from both the childs and return the maximum, so in this way, the maximum depth goes upwards and at the end of recursion, max goes to the root */

int maxdepth(struct node* node)
{
	if(node==NULL)
		return 0;
	else if(node->left != NULL || node->right !=NULL)
		return (max(maxdepth(node->left)+1,maxdepth(node->right)+1));
	else
		return 1;
}

/* Find maximum of two integers, Can be implemented in maxdepth, but for clarity is written apart from it */

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}



/* Returns the number of nodes in a tree */
/* If node is NULL, return 0, otherwise always add 1 for itself and call for both left and right child recursively */
/* In case it has no child then it would be NULL and 0 would be returned */
int size(struct node* node)
{
	if(node == NULL)
		return 0;
	/* Finally all would expand in the next statement and final answer would be returned */
	else return ( size(node->left) + size(node->right) +1 );
}


/* Minimum value in Binary Search Tree (BST) */
/* Concept is simple, just recurse till the left child of a node is NULL and print its value */
/* First one is recursive */
int minvalue1(struct node* node)
{
	if(node == NULL)
		return -1;
	/* here return is necessary, as I want to return that value which is found at the end of recursion, otherwise it would print the value of the root node, because at the end of recursion, node=root and its data value got printed */
	/* So, here my aim is when the recurse end, that value should get returned by function not something else :) */
	if(node->left!=NULL)
		return minvalue1(node->left);
	/* Print the value of the leftmost node in the tree with no left child */
	return node->data;
}


/* Second one is not recursive */
int minvalue2(struct node* node)
{
	while(node->left !=NULL)
		node=node->left;
	return (node->data);
}

/* Is any path from root to leaf has a particular sum */
/* Main concept here is subtract the value from the root and  recurse down, until node == NULL and if sum == 0, then there exist an exact match. Also the catch is true or false value is returned at the last node whose both left and right child are null*/

int haspathsum(struct node* node, int sum)
{
	if(node == NULL)
		return 0;
	if(node->left == NULL && node->right == NULL )
		return (sum==node->data);
	else
		return	(haspathsum(node->left,sum-(node->data)) || haspathsum(node->right,sum-(node->data)));
}


int sumoftree(struct node* node)
{
	if(node ==NULL)
		return 0;
	else if(node->left != NULL || node->right !=NULL)
		return (node->data + sumoftree(node->left) +sumoftree(node->right));
	else
		return (node->data);
}

// Just check node not null then call mirror on both left and right subtrees, after mirror both childes, swap left and right pointers(subtrees just swaped)
void mirror(struct node* root)
{
	struct node* temp;

	if(root == NULL)
		return;	
	if(root->left!=NULL)
		mirror(root->left);
	if(root->right!=NULL)
		mirror(root->right);

	temp=root->left;
	root->left=root->right;
	root->right=temp;
	
}
// Main concept is the use of static variable here, one we get the appropriate value, then just return val;
int nthSmallest(struct node *root, int n)
{
	static int i=0;
	static int val;
	if(root != NULL ){
	nthSmallest(root->left, n);
	
	if((++i)==n)
		val= root->data;
	nthSmallest(root->right, n);
	}
	return val;
}

// Fairly simple, if values in two nodes equal try to match their left and right childs, other combinatin check and return appropriate value
int compareTrees(struct node *r1, struct node *r2)
{
	if(r1==NULL && r2==NULL)
		return 1;
	else if(r1!=NULL && r2==NULL)
		return 0;
	else if(r1==NULL && r2!=NULL)
		return 0;
	else if(r1->data==r2->data)
		return (compareTrees(r1->left,r2->left) && compareTrees(r1->right, r2->right));

}

int main()
{

	/* This pointer holds the address of the root pointer */
	struct node *root = NULL;
	struct node *root1 = NULL;
	int hps=-100;
	int n=7;
	root=insert(root,12);
	root=insert(root,25);
	root=insert(root,1);
	root=insert(root,2);
	root=insert(root,45);
	root=insert(root,42);
	root=insert(root,50);
	root=insert(root,13);
	printf("\nThe inorder traversal of Binary Search tree 1  -->  ");
	inorder(root);
	
	root1=insert(root1,12);
	root1=insert(root1,25);
	root1=insert(root1,1);
	root1=insert(root1,2);
	root1=insert(root1,45);
	root1=insert(root1,42);
	root1=insert(root1,50);
	root1=insert(root1,13);
	
	printf("\nThe inorder traversal of Binary Search tree 2  -->  ");
	inorder(root1);
	printf("\nBoth the trees are equal ? --->  %d \n", compareTrees(root,root1));
	
	//mirror(root);
	//printf("\nThe inorder traversal of Binary Search tree ");
	inorder(root);
	printf("\nThe %d smallest element in the tree ---> %d \n",n,nthSmallest(root,n));
	printf("\nThe number of nodes in the tree are --> %d \n",size(root));
	printf("\nThe maximum depth of the tree is --> %d \n", maxdepth(root));
	printf("\nThe minimum value in the tree is (recursively)--> %d \n",minvalue1(root));
	printf("\nThe minimum value in the tree is (non recursively)--> %d \n",minvalue2(root));
	printf("\nThe sum of the nodes of the tree is --> %d \n",sumoftree(root));
	hps=haspathsum(root,13);
	printf("\n haspathsum --> %d\n ",hps);
	


}







