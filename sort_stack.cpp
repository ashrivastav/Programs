#include<bits/stdc++.h>

using namespace std;

void insertSorted(auto & stk , auto elem)
{
    if(stk.empty() || stk.top() < elem)
        stk.push(elem);
    else {
        auto val = stk.top();
        stk.pop();
        insertSorted(stk, elem);
        stk.push(val);
    }
}
        

void sortStack(auto & myStack)
{
    if(!myStack.empty())
    {
        auto temp = myStack.top();
        myStack.pop();
        sortStack(myStack);
        insertSorted(myStack, temp);
    }
}

void anotherSortStack(auto &myStack, auto &anotherStack)
{

    while(!myStack.empty())
    {
        auto val = myStack.top();
        myStack.pop();
        insertSorted(anotherStack, val);
    }        
}

void printStack(auto & myStack){
 while(!myStack.empty())
    {
        int val = myStack.top();
        cout << val << " ";
        myStack.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> myStack;
    srand(time(0));
    for(auto i=0; i< 10; i++)
        myStack.push(rand() % 100);

    stack<int> auxStack = myStack;
    stack<int> dstStack = myStack;
    stack<int> anotherStack;

    printStack(myStack);
    sortStack(auxStack);
    anotherSortStack(dstStack, anotherStack);
    printStack(auxStack);
    printStack(anotherStack);
}
