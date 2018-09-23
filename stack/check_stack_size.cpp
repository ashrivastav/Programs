#include <iostream>
using namespace std;
long long recurse_add(long long n)
{
    if (n == 1)
        return n;

    return (recurse_add(n -1) + n) % 10000000;
}

int main()
{
    long long result;

    result = recurse_add(1000000);
    cout << "Result"<< result;
}

    
