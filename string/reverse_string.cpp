#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

void reverse(string &A)
{
	istringstream ss(A);
	string s;
	stack<string> stk;

	while(ss >> s)
	{
		stk.push(s);
	}
	A.clear();
	while(!stk.empty()){
		A.append(stk.top());
		stk.pop();
		if(!stk.empty())
			A.append(" ");

	}



}

int main()
{
	string str("       This is            wrong             ");

	cout << str << endl;

	reverse(str);
	//str.erase(1,1);

	cout << str;


}
