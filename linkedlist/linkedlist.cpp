// Program to perform various functions over linked list, C++ program wth mostly C structs

#include<stdio.h>
#include<iostream>
#include<malloc.h>

using namespace std;


typedef struct node{
int data;
struct node* next;
}mynode;

mynode* createNode(int val)
{
	mynode *newNode = (mynode*) malloc(sizeof(mynode));
	if(newNode != NULL)
	{
		newNode->data=val;
		newNode->next=NULL;
	}
	return newNode;
}

// Insertion using Double Pointer 
int insert(mynode **headptr, int val)
{
	
	mynode *temp,*iterator;
	iterator=*headptr;
	if(*headptr == NULL)
		{
			*headptr = createNode(val);
			return 1;
		}
	while(iterator!=NULL)
		{
			temp=iterator;
			iterator=iterator->next;
		}
			
		temp->next=createNode(val);
		if(temp->next == NULL)
			cout << "Error: No new node added";
}

// New efficient implementation of inserting node in a linked list using double pointer
// But what is efficient here ?? What was I trying to do here.
int effInsert(mynode **pptr, int val)
{
	mynode **lptr,**lastnode;
	lastnode=pptr;
	for(lptr=pptr;(*lptr)!=NULL;lptr = &(*lptr)->next)
	{
		lastnode=lptr;
	}
	if((*lastnode)!=NULL)
		(*lastnode)->next=createNode(val);
	else
		(*lastnode)=createNode(val);
}

	int countNodes(mynode *head)
	{
		mynode *temp;
		int count=0;
		for(temp=head;temp!=NULL;temp=temp->next)
			count++;
		return count;
	}
	
void printList(mynode* head)
	{
		if(head==NULL)
			{
				cout<<"Empty list"<< endl;
				return;
			}
		while(head->next!=NULL)
		{
			printf("%d->", head->data);
			head=head->next;
		}
		printf("%d->NULL\n", head->data);
	}

//Reverse the linked list

mynode* reverseList(mynode **head)
{
		static mynode *root;
		static int count=0;
		int stk=0;

			if((*head)==NULL)
				return NULL;
		
					
		if((((*head)->next)->next)!=NULL)
			{
				stk=count++;
				reverseList(&(*head)->next);
							
			}
			else
				root=(*head)->next;
				
		((*head)->next)->next=*head;
		if(stk==0)
			(*head)->next=NULL;

		return root;
	}

// Add two linked list, Main Recursive Method

int  addList1(mynode **first,mynode **second, mynode **third, int length1, int length2)
	{
		 int carry=0;
		
			
			if((*first)!=NULL || (*second)!=NULL)
			{
				if(length1 == length2)
				{
					(*third)=createNode(0);
					carry=addList1(& ((*first)->next),&((*second)->next),&((*third)->next), length1-1, length2-1);
					(*third)->data=(((((*first)->data)+((*second)->data)+carry)%10));
					carry=(((*first)->data)+((*second)->data))/10;
				}
			
				else if(length1 > length2)
				{
					(*third)=createNode(0);
					carry=addList1(& ((*first)->next),&((*second)),&((*third)->next), length1-1, length2);
					(*third)->data=(((((*first)->data)+carry)%10));
					carry=(((*first)->data)+ carry )/10;
				}
				else
				{
					(*third)=createNode(0);
					carry=addList1(& ((*first)),&((*second)->next),&((*third)->next), length1, length2-1);
					(*third)->data=(((((*second)->data)+carry)%10));
					carry=(((*second)->data)+ carry )/10;
				}	
			}	
		return carry;		
	
	}
	
// Make a copy of a linked list
mynode* copy(mynode **first){

	mynode *temp=NULL;
		if(*first!=NULL)
		{
			temp= createNode((*first)->data);
			temp->next=copy(&(*first)->next);
		}
		return temp;
	}


// Helper method for adding linked list
mynode* addList(mynode *first, mynode *second)
	{
		int  f=0;
		int  s=0;
		int diff=0, flag=0;
		mynode *addition=NULL;
		
		mynode *fir=first;
		mynode *sec=second;
		
		f=countNodes(first);
		s=countNodes(second);
		diff=f-s;
		
		if(diff<0)
		{
			diff=-(f-s);
		}
		cout << "The value of diff is "  <<diff << endl;
		
		int carry=0;
		carry=addList1(&first,&second,&addition,f,s);
		
		mynode *temp;
		if(carry)
		{
			temp=createNode(1);
			(temp->next)=addition;
			addition=temp;
		}	
		
		return addition;
	}

mynode*  reverse_list(mynode* first)
{
    mynode * temp = NULL;
    if(first->next != NULL) {
        temp = reverse_list(first->next);
        first->next->next = first;
        first->next = NULL;
        return temp;
    } else
        return first;
}

void printnthlast(mynode *node, int n)

{
    static int num = n;
    if (node == nullptr)
        return;

    printnthlast(node->next, n);
    num--;

    if(num ==0)
        cout << "Number is" << node->data;
}

int main()
{

	mynode *first=NULL;
	mynode *second=NULL;
	mynode *sum=NULL;
	insert(&first,1);
	insert(&first,2);
	insert(&first,5);
	insert(&first,4);
	insert(&first,9);
    insert(&first,10);
	//insert(&first,3);
	//effInsert(&second,1 );
//	effInsert(&second,9);
//	effInsert(&second,0);
//	printList(first);
//	printList(second);
//	cout<< "The number of nodes in first linked list is " << countNodes(first)<<endl;
//	cout<< "The number of nodes in first linked list is " << countNodes(second)<<endl;
//	sum=addList(first,second);	
	//sum=copy(&second);
//	printList(sum);
	//head=reverseList(&head);
    printList(first);
    cout << "Reversing it"<< endl;
    first = reverse_list(first);
    printList(first);
    printnthlast(first, 5);
	//printList(head);
	return 0;
}

