#include <iostream>
#include <deque>

using namespace std;

/* A tree node structure */
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val):data(val), left(NULL), right(NULL)
    {}
};

/* Return a new node */
Node* insert(int val)
{
    Node *new_node = new Node(val);
    return new_node;
}

void print_extremes(Node *root)
{
    deque<Node *> dq;
    dq.push_front(NULL);
    dq.push_front(root);
    bool print_node = true;
    while(dq.size() > 1)
    {
        Node *lroot = dq.front();
        print_node = true;
        while(lroot != NULL)
        {
            dq.pop_front();
            if (print_node) {
                cout << lroot->data <<  " " ;
                print_node = false;
            }

            if(lroot->right != NULL)
                dq.push_back(lroot->right);

            if(lroot->left != NULL)
                dq.push_back(lroot->left);

            lroot = dq.front();
        }

        print_node = true;
        lroot = dq.back();
        while(lroot != NULL)
        {
            dq.pop_back();
            if (print_node) {
                cout << lroot->data <<  " " ;
                print_node = false;
            }

            if(lroot->left != NULL)
                dq.push_front(lroot->left);

            if(lroot->right != NULL)
                dq.push_front(lroot->right);

            lroot = dq.back();
        }
    }
}

void print_spiral(Node *root)
{
    deque<Node *> dq;
    dq.push_front(NULL);
    dq.push_front(root);    
    cout << "Printing\n" <<endl;
    while(dq.size() > 1)
    {
        auto root = dq.front();
        while(root != NULL)
        {
            dq.pop_front();
            cout << root->data << " " ;
            if (root->right != NULL)
                dq.push_back(root->right);

            if(root->left != NULL)
                dq.push_back(root->left);

            root = dq.front();
        }

        root = dq.back();
        while(root != NULL)
        {
            dq.pop_back();
            cout << root->data << " " ;
            if(root->left != NULL)
                dq.push_front(root->left);

            if (root->right != NULL)
                dq.push_front(root->right);

            root = dq.back();
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

    if(level >=2){
        print_given_level(root->left, level -1);
        print_given_level(root->right, level -1);
    }
}


int find_level(Node *root, Node *node, int level)
{
    if(root == NULL)
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

int main()
{
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
    print_spiral(root);
    print_extremes(root); cout << endl;
    print_given_level(root, 4); cout << endl;
    print_cousins(root,root->right->right); cout << endl;
}






