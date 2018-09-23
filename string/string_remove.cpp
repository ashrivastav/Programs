#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    list<int> l  = {1,2,3};
    l.remove(1);
    string str = "hello world abhishek,";
    str.pop_back();
    str.push_back('!');
    //    str.erase(remove(str.begin(), str.end(), ','), str.end());
    //    str.erase(remove(str.begin(), str.end(),' '), str.end());

    cout << str;
//    for(auto &i: l)
//        cout << i << " ";
    cout << endl;
}
