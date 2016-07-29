#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>

using namespace std;


void reverse_string(string &str)
{
    stack<string> string_stack;
    string word;
    istringstream iss(str);
    while(iss >> word) 
    {
        string_stack.push(word);
    }
    str.clear();

    while(!string_stack.empty())
    {
        str.append(string_stack.top());
        string_stack.pop();
        str.append(" ");
    }
}



int main()
{
    string sample;
    cout << "Enter a string: ";
    getline(cin, sample);
    cout << sample << endl;
    reverse_string(sample);
    cout << sample << endl;
}

