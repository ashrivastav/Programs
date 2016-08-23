#include <iostream>

using namespace std;

int compute_gcd(auto a, auto b)
{
    long reminder;
    while(b !=0)
    {
        reminder = a % b;
        a = b;
        b = reminder;
    }

    return a;
}


int main()
{
    long long a , b, gcd;
    cout << "Enter two numbers :" ;
    cin >> a;
    cin >> b;

    gcd = compute_gcd(a,b);
    cout << "gcd is " << gcd;
}

