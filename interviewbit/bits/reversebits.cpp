#include <iostream>
#include <bitset>

using namespace std;


unsigned int reverse(unsigned int A)
{
    unsigned int rev = 0, bit = 0;
    unsigned int const SIZE = sizeof(A) * 8;
    int i = 0;
    while(i < SIZE)
    {
       bit = A & 0x1;
       rev = rev ^ bit;
       A = A >> 1;
       i++;
       if( i < SIZE)
        rev = rev << 1;
    }

    return rev;

}



int main()
{

    unsigned int i = 3;
    cout << "Number is " << bitset<32>(i) << endl;
    cout << "Reverse is " << bitset<32>(reverse(i)) << endl;

}
