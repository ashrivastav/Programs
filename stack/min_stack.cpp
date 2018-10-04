#include <iostream>
#include <stack>

using namespace std;


class MinStack {
	stack<int> stk;
	stack<int> minstk;

public:
	void Push(int elem);
	void Pop();
	int Top();
	int GetMin();
};

void MinStack::Push(int elem)
{
	stk.push(elem);
	cout << "Push: " << elem << endl;
	if (minstk.empty() || minstk.top() >= elem)
	{
		minstk.push(elem);
	}
}

void MinStack::Pop()
{
	if (stk.empty())
		throw "Empty Stack";
	
	cout << "Popped Element is " << stk.top() << endl;
	int elem = stk.top();
	stk.pop();

	if (elem <= minstk.top()) {
		minstk.pop();
	}
}

int MinStack::Top()
{
	if (stk.empty())
		throw "Empty Stack";
	cout << "Top Element is " << stk.top() << endl;
	return stk.top();
}

int MinStack::GetMin()
{
	if (stk.empty())
		throw "Empty Stack";
	cout << "Min Element is " << minstk.top() << endl;
	return minstk.top();
}


int main()
{
	MinStack minstk;

	minstk.Push(6);
	minstk.Push(7);
	minstk.GetMin();
	minstk.Top();
	minstk.Push(4);
	minstk.Push(8);
	minstk.GetMin();
	minstk.Top();
	minstk.Push(3);
	minstk.GetMin();
	minstk.Top();
	minstk.Push(10);
	minstk.Push(50);
	minstk.GetMin();
	minstk.Top();
	minstk.Pop();
	minstk.GetMin();
	minstk.Top();
	minstk.Pop();
	minstk.Pop();
	minstk.Top();
	minstk.GetMin();
}