#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#include <tuple>
#include <map>
#include <limits.h>

using namespace std;

/* A tree node structure */
struct Node {
    int data;
    Node *left;
    Node *right;
    Node *nextright;
    Node(int val):data(val), left(NULL), right(NULL)
    {}
};

/* Return a new node */
Node* insert(int val)
{
    Node *new_node = new Node(val);
    return new_node;
}

/* Print nodes at the extremes of tree */
void print_extremes(Node *root)
{
    deque<Node *> dq;
    dq.push_front(NULL);
    dq.push_front(root);
    bool print_node = true;
    while(dq.size() > 1)
    {
    	/* Take node from dq front and print*/
        Node *curr = dq.front();
        print_node = true;

        while(curr != NULL)
        {
            dq.pop_front();
            if (print_node) {
                cout << curr->data <<  " " ;
                print_node = false;
            }

            if(curr->right != NULL)
                dq.push_back(curr->right);

            if(curr->left != NULL)
                dq.push_back(curr->left);

            curr = dq.front();
        }

        /* Pop nodes from dequeue back & print*/
        curr = dq.back();
        print_node = true;

        while(curr != NULL)
        {
            dq.pop_back();
            if (print_node) {
                cout << curr->data <<  " " ;
                print_node = false;
            }

            if(curr->left != NULL)
                dq.push_front(curr->left);

            if(curr->right != NULL)
                dq.push_front(curr->right);

            curr = dq.back();
        }
    }
}


void print_spiral(Node *root)
{
    deque<Node *> dq; // Create a dequeue
    Node *current = nullptr;
    dq.push_front(NULL); // Push null as a marker
    dq.push_front(root); // Push root of tree

    cout << "Printing\n" <<endl;

    while(dq.size() > 1) // While all the front and back elements are processed
    {
        while(current = dq.front())
        {
            dq.pop_front(); //Remove front element
            cout << current->data << " " ;

            /* First push back right then left child for proper printing */
            if (current->right != NULL)
                dq.push_back(current->right);

            if(current->left != NULL)
                dq.push_back(current->left);
        }


        while(current = dq.back())
        {
            dq.pop_back();
            cout << current->data << " " ;

            /* Push left child first and then right child for proper printing */
            if(current->left != NULL)
                dq.push_front(current->left);

            if (current->right != NULL)
                dq.push_front(current->right);

        }

    }
    cout << endl;
}


/* level = 1, desired level to print 
   level >=2, recurse till we get level = 1
*/
void print_given_level(Node *root, int level)
{
    if (root == NULL)
        return;

    if(level == 1) // Level to print 
    {
        cout << root->data << " ";
        return;
    }

    if(level > 1){
        print_given_level(root->left, level -1);
        print_given_level(root->right, level -1);
    }
}


int find_level(Node *root, Node *node, int level)
{
    if(root == NULL || node == NULL)
        return 0;

    else if(root == node)
        return level;

    return max(find_level(root->left,node, level +1), find_level(root->right,node, level +1));
}

void print_level_nodes_except_sibling(Node *root,Node *node, int level)
{
    if(level <2 || root == NULL)
        return;

    if(level == 2) // One level above the level to print 
    {
        if(root->left == node || root->right == node)
            return;
        if(root->left)
            cout << root->left->data << " ";
        if(root->right)
            cout << root->right->data << " ";
    }

    if (level > 2)
    {
    print_level_nodes_except_sibling(root->left, node, level -1);
    print_level_nodes_except_sibling(root->right, node, level -1);
    }

}

// Print nodes on a level other than the given node sibling
void print_cousins(Node *root, Node *node)
{
    int level = 1;

    level = find_level(root, node, level);
    cout << level << endl;;

    print_level_nodes_except_sibling(root, node, level);
}

//Print tree in level order

void print_level_order(Node *root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node *curr = q.front();
		q.pop();
		if(curr == nullptr)
			continue;
		cout << curr->data << endl;
		q.push(curr->left);
		q.push(curr->right);
	}
}

int max_depth(Node *root)
{
	if(root == nullptr)
		return 0;

	return max(max_depth(root->left), max_depth(root->right)) + 1;
}


void print(vector<Node *> &vec)
{
	cout <<"Printing Path: ";
	for(auto &i: vec)
		cout << i->data <<  " ";
	cout << endl;
}

void print_all_nodes_to_leaf(Node *root, vector<Node *> &vec)
{
	if(root)
		vec.push_back(root);

	if(root == nullptr)
		return;

	if(root->left ==nullptr && root->right == nullptr){
		print(vec);
		vec.pop_back();
		return;
	}

	print_all_nodes_to_leaf(root->left, vec);
	print_all_nodes_to_leaf(root->right, vec);
	vec.pop_back();
}

/*
bool sum_all_nodes_to_leaf(Node *root, vector<Node *> &vec)
{
	if(root)
		vec.push_back(root);

	if(root == nullptr)
		return;

	if(root->left ==nullptr && root->right == nullptr){
		(vec);
		vec.pop_back();
		return;
	}

	print_all_nodes_to_leaf(root->left, vec);
	print_all_nodes_to_leaf(root->right, vec);
	vec.pop_back();
}
*/

int max_width_of_tree(Node *root)
{
	deque<Node *> dq;
	int max_width = 0;
	Node *current = nullptr;

	if(root == nullptr)
		return 0;

	dq.push_front(nullptr);
	dq.push_front(root);
	auto width = 0;
	while(dq.size() > 1)
	{
		while(current = dq.front())
		{
			dq.pop_front();
			width++;

			if(current->left)
				dq.push_back(current->left);

			if(current->right)
				dq.push_back(current->right);
		}

		if(max_width < width)
			max_width = width;

		width =0;

		while(current = dq.back())
		{
			dq.pop_back();
			width++;


			if(current->left)
				dq.push_front(current->left);

			if(current->right)
				dq.push_front(current->right);

		}

		if(max_width < width)
				max_width = width;

		width =0;
	}

	return max_width;
}



int count_leaves_nodes(Node *root)
{
	if(root == nullptr)
		return 0;

	if(root->left == nullptr && root->right == nullptr)
		return 1;

	return (count_leaves_nodes(root->left) + count_leaves_nodes(root->right));
}

void connect_nodes(Node *root)
{
	queue<pair<Node*, int>> q;
	q.push(make_pair(root, 0));
	int curr_level = 0, prev_level=-1;
	Node *curr_node = nullptr;
	Node *prev = nullptr;
	while(!q.empty())
	{
		auto temp = q.front();
		q.pop();
		curr_level = temp.second;
		curr_node = temp.first;
		if(curr_level == prev_level && prev != nullptr)
		{
			prev->nextright = curr_node;
			cout <<"Linking ->" << prev->data <<"---->" << curr_node->data << endl;
		}

		prev = curr_node;
		prev_level = curr_level;

		if(curr_node->left)
			q.push(make_pair(curr_node->left, curr_level+1));


		if(curr_node->right)
			q.push(make_pair(curr_node->right, curr_level+1));
	}

}

void sum(Node *root, int &total_sum, int curr_sum)
{
	if(root== nullptr)
		return;

	curr_sum = curr_sum *10 + root->data;

	if(root->left == nullptr && root->right == nullptr)
	{
		total_sum = curr_sum + total_sum;
		return;
	}

    sum(root->left, total_sum, curr_sum);
    sum(root->right, total_sum, curr_sum);
	return;
}

void find_next_on_level(Node *root, int key)
{
	queue<pair<Node *, int>> q;

	if(root == nullptr)
		return;

	pair<Node*,int > prev;
	prev.first = nullptr;
	int  curr_level = 0;
	q.push(make_pair(root, curr_level));

	while(q.empty() == false)
	{
		auto temp1 = q.front();
		auto temp = temp1.first;
		q.pop();

		if(temp1.second == curr_level && prev.first && prev.first->data == key){
			cout<< temp1.first->data;
		return;
		}

		prev = temp1;
		curr_level = temp1.second;

		if(temp->left)
					q.push(make_pair(temp->left,curr_level+1));

		if(temp->right)
					q.push(make_pair(temp->right, curr_level+1));



	}
}

bool is_mirror_util(Node *left_ptr, Node *right_ptr)
{
	if(left_ptr == nullptr && right_ptr == nullptr)
		return true;

	if(left_ptr == nullptr || right_ptr == nullptr)
		return false;

	//Pre order traversal check
	if(left_ptr->data == right_ptr->data)
	{
	return (is_mirror_util(left_ptr->right, right_ptr->left) && is_mirror_util(left_ptr->left , right_ptr->right));
	}

	return false;
}


bool is_mirror(Node *root)
{
	return is_mirror_util(root->left, root->right);
}


int min_height(Node *root)
{
	if(root == nullptr)
		return -1;

	return( min(min_height(root->left), min_height(root->right)) + 1);
}

bool has_path_sum(Node *root, int sum)
{
	if(root == nullptr)
		return (sum == 0);

	int subsum = sum - root->data;

	if(subsum == 0  && root->left == nullptr && root->right == nullptr)
		return true;

	if(subsum == 0)
		return false;

	return(has_path_sum(root->left, subsum) || has_path_sum(root->right, subsum));
}

/* Vertical order traversal of tree */
void vertical_order_print(Node *root)
{
	multimap<int,int> mmap;
	
	if (!root) 
		return;
		
	queue<pair<Node*, int>> myqueue;
	myqueue.push(make_pair(root, 0));
	int min_vd = INT_MAX; 
	int max_vd = INT_MIN;
	int vd = 0;	
	while(!myqueue.empty()) {
		pair<Node*, int> q_node = myqueue.front();
		myqueue.pop();
		if (q_node.first) {
			int vd = q_node.second;
			
			if (vd < min_vd)
				min_vd = vd;
			if (vd > max_vd)
				max_vd = vd;

			auto node = q_node.first;
			mmap.insert(make_pair(vd,node->data));
			if (node->left) 
				myqueue.push(make_pair(node->left, vd - 1));
			if (node ->right)
				myqueue.push(make_pair(node->right, vd + 1));
		}
	}

	for (int i = min_vd; i <= max_vd ; i++) {
		auto it = mmap.equal_range(i);
		cout << "Vertical Distance " << i << "-->"  ;
		for (auto iter = it.first; iter != it.second; iter++)
		{
			cout << iter->second << " ";
		}
		cout << endl;
	}
	
}

int main()
{
	//vector<Node *> vec; // Vector for printing all path from root to leaves
	/*
	   Node *root = new Node(1);
	   root->left = new Node(2);
	   root->right = new Node(2);
	   root->left->left = new Node(3);
	   root->left->right = new Node(4);
	   root->right->right = new Node(3);
	   root->right->left = new Node(4);
	   root->left->right->left = new Node(7);
	   root->left->right->right = new Node(8);
	   root->right->left->left = new Node(8);
	   root->right->left->right = new Node(7);
	   cout << boolalpha << is_mirror(root);
	   cout << min_height(root);
	   cout << boolalpha << has_path_sum(root, 14);

	   int total_sum = 0, curr_sum =0;
	   sum(root, total_sum, curr_sum);
	   cout << "Total sum:" << total_sum;
	 */
	//    find_next_on_level(root, 14);
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(11);
	root->right->left->left = new Node(12);
	root->right->left->right = new Node(13);
	root->right->right->left = new Node(14);
	root->right->right->right = new Node(15);
	root->left->left->left->left = new Node(16);
	root->right->right->right->right = new Node(31); 
	vertical_order_print(root);
	//  cout << "Max width is : " << max_width_of_tree(root) << endl;
	// connect_nodes(root);

	// print_spiral(root);
	//   print_extremes(root); cout << endl;
	//  print_given_level(root, 4); cout << endl;
	//  print_cousins(root,root->right->right); cout << endl;
	//print_level_order(root); cout << endl;
	//cout << max_depth(root);
	//print_all_nodes_to_leaf(root, vec);
	//cout << count_leaves_nodes(root);
	cout << endl;

}






