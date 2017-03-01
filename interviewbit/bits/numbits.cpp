#include <iostream>

using namespace std;


int numbits(unsigned int i)
{
    int count =0;
    while(i)
    {
        if(i& 0x1)
        count++;
        i = i >>1;
    }
    return count;
}




int main()
{
    unsigned int i = 1;
    cout << numbits(i) << endl;
}
