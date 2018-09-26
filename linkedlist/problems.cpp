#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

struct Node {
    int data;
    mutex node_mut;
    Node *next;
    Node(int val): data(val), next(nullptr){};
};

//3
void insert_at_beg(Node* &node, int val)
{
    Node *new_node = new Node(val);

    if(node){
    	cout << "Trying to take lock for node: " << node->data << endl;
       	lock_guard<mutex> lock_curr(node->node_mut);
       	cout << "Lock taken for node : " << node->data << endl;;
    }

    if(new_node){
    	cout << "Trying to take lock for new node: " << val << endl;
    	lock_guard<mutex> lock_next(new_node->node_mut);
    	cout << "Lock taken for new_node: " << val << endl;
    }

    if(node == nullptr)
    {
        node = new_node;
        return;
    }

    new_node->next = node;
    node = new_node;
}
    
//4
void delete_key(Node * &head, int value)
{
	Node *curr = head;

	if(head == nullptr)
		return;

	if(head->data == value)
	{
		Node *temp = head;
		head = head->next;
		delete temp;
		return;
	}

	while(curr && curr->next &&curr->next->data!=value)
		curr = curr->next;

	if(curr && curr->next && curr->next->data == value)
	{
		Node *temp = curr->next;
		curr->next = curr->next->next;
		delete temp;
	}
}

//5
void delete_key_position(Node *&head, int position)
{
	Node *prev = nullptr;
	Node *curr = head;

	if(head == nullptr)
		return;

	int position_local = position;
	while(--position_local && curr != nullptr)
	{
		prev = curr;
		curr = curr->next;
	}

	if(curr == nullptr || position == 0)
	{
		cout << "Node postion invalid" << endl;
		return;
	}

	if(prev == nullptr)
	{
		head = head->next;
		delete curr;
		return;
	}

	prev->next = curr->next;
	delete curr;
 }


void print(Node *head)
{
    for(; head != nullptr; head= head->next)
    {
        cout << head->data << " ";
    }
    cout <<"--> NULL" << endl;
}

//Rotate the linked list by some amount
void rotate(Node *&head, int val)
{
	Node *curr = head;

	while(curr->next!=nullptr)
		curr = curr->next;

	for(int i=0 ; i<val ;i++)
	{
		curr->next = head;
		Node *temp = head->next;
		head->next = nullptr;
		head = temp;
		curr = curr->next;
	}
}

int find_length(Node *head)
{
	int count =0;
	while(head!=nullptr)
	{
		count++;
		head = head->next;
	}
	return count;
}

int find_length_rec(Node *head)
{
	int count =0;

	if(head == nullptr)
		return 0;

	return (find_length_rec(head->next) + 1);

}

void delete_alternate(Node * &head)
{
	Node *curr = head;

	if(head == nullptr || head->next == nullptr)
		return;

	while(curr->next)
	{
		Node *temp = curr->next;
		curr->next = curr->next->next;
		delete temp;

		if(curr->next)
			curr = curr->next;
	}

}

void move_front(Node * &dest, Node* &src)
{
	Node *temp = src;
	src = src->next;
	temp->next = dest;
	dest = temp;
}

void move_end(Node * &dest, Node * &src)
{


}

void alternate_split(Node *source, Node * &first, Node * &second)
{
	Node *curr = source;

	while(curr)
	{
		move_front(first, curr);
		curr = curr
		if(curr)
			move_front(second, curr);
	}

	source = nullptr;
}


void alternate_split_end(Node *source, Node * &first, Node * &second)
{
	Node *curr = source;

	while(curr)
	{
		move_end(first, curr);
		if(curr)
			move_end(second, curr);
	}

	source = nullptr;
}

void reverseList()

int main()
{
    Node *head = nullptr;
    thread t1(insert_at_beg ,ref(head), 60);
    thread t2 (insert_at_beg, ref(head), 50);
    thread t3 (insert_at_beg, ref(head), 40);
    thread t4 (insert_at_beg, ref(head), 30);
    thread t5 (insert_at_beg, ref(head), 20);
    thread t6 (insert_at_beg, ref(head), 10);
    //insert_at_beg(head, 40);
    //insert_at_beg(head, 30);
    //insert_at_beg(head, 20);
    //insert_at_beg(head, 10);

    t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
        t6.join();

    print(head);
   // delete_alternate(head);
    Node *first = nullptr, *second = nullptr;
    alternate_split_end(head, ref(first), ref(second));
    //rotate(head, 4);
    print(head);
    print(first);
    print(second);
    cout <<"Length of list is " << find_length(head) <<"         By recursion " << find_length_rec(head) << endl;

    //delete_key(head, 50);
 //   delete_key_position(head, 0);
 //   delete_key_position(head, 1);
   // delete_key_position(head, 5);
  //  print(head);


}
