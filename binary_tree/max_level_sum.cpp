/*
 * max_level_sum.cpp
 *
 *  Created on: Dec 24, 2016
 *      Author: abhishek
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int val):data(val), left(nullptr), right(nullptr){};
};

void create_tree(TreeNode *root)
{
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(-1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(-5);
    root->left->left->left = new TreeNode(-1);
    root->left->left->right = new TreeNode(-2);
    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(2);
    root->right->left->left = new TreeNode(1);
    root->right->left->right = new TreeNode(1);
    root->right->right->left = new TreeNode(2);
    root->right->right->right = new TreeNode(-2);
    root->left->left->left->left = new TreeNode(16);
    root->right->right->right->right = new TreeNode(-8);
}

int find_max_sum_level(TreeNode *root)
{
	deque<TreeNode *> dq ={NULL};
	dq.push_back(root);
	bool insert_front = true;
	TreeNode *temp =nullptr;
	int sum = 0;
	int max_sum = 0;
	int level = 0;
	while(dq.size() > 1)
	{
		if(insert_front){
			temp = dq.back();
			while(temp != NULL)
			{
				if(temp->left)
					dq.push_front(temp->left);

				if(temp->right)
					dq.push_front(temp->right);

				sum += temp->data;

				dq.pop_back();
				temp = dq.back();
				insert_front = false;
			}
			level++;
		} else {
			temp = dq.front();
			while(temp != NULL)
			{
				if(temp->left)
					dq.push_back(temp->left);

				if(temp->right)
					dq.push_back(temp->right);

				sum += temp->data;
				dq.pop_front();
				temp = dq.front();
				insert_front = true;
			}
			level++;
		}

		if(max_sum < sum)
				max_sum=sum;

		cout << level << "Sum is " << sum <<  endl;
		sum = 0;
	}

return max_sum;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    create_tree(root);
    auto sum = find_max_sum_level(root);
    cout <<"Maximum sum is " << sum << endl;
    return 0;
}





