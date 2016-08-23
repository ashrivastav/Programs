#include<bits/stdc++.h>

using namespace std;

int reverse(int num)
{
    int rev = 0, temp;

    while(num)
    {
	temp = rev;
        rev = rev * 10;
	if ( rev / 10 != temp )
		return 0;
	temp = rev;
        rev = rev + num %10;
	if(rev - (num % 10) != temp)
		return 0;
        num = num /10;
    }

    return rev;
}

int main()
{
    int a=-1146467, rev;

    rev= reverse(a);
    cout << rev;
}

