#include <iostream>

using namespace std;

int fib(int n)
{
    if ( n == 0)
        return 0;

    if (n == 1 || n == 2)
        return 1;
    
    return fib(n-1) + fib(n -2);
}

int sum_fibonacci(int n)
{
    if (n == 1)
        return 1;

    return fib(n) + sum_fibonacci(n-1);
}


int main()
{
    int result, input;
    input = 3;
    cout << "Result for" << input << "is:"<< sum_fibonacci(input) << endl;
    input = 4;
    cout << "Result for" << input << "is:"<< sum_fibonacci(input) << endl;
    return 0;
}





