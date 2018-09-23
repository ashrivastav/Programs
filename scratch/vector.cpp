#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {7, 5, 4, 5};

    v.push_back(10);
    v.push_back(20);

    for( int n :v)
        cout << n << " ";
}
