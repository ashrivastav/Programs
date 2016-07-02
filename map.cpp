#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main()
{

    unordered_map<vector, int> vec_map;
    unordered_map<string, int> mapping;

    vector<int> v;
    vector<int> 
    v.push_back(1);
    
    vec_map[v] = 10;

    v.push_back(20);

    vec_map[v] = 20;

    cout << vec_map[v];
    
    v.pop_back();

    cout << vec_map[v];

//    mapping["abhishek"] = 100;

 //   cout << mapping["abhishek"];
    return 0;
}
