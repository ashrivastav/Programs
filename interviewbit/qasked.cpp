#include <iostream>

using namespace std;

int main()
{

int A = 2147482644;
   int rev = 0, temp = 0;

    while(A)
    {
        temp = rev;
        rev = rev * 10;
        if(rev/ 10 != temp)
            return 0;
        temp = rev;
        rev = rev + A %10;
        
        if(rev - (A % 10) != temp)
            return 0;
        A = A /10;
    }
	cout << rev;
    return rev;
}
