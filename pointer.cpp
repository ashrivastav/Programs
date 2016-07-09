#include<iostream>


using namespace std;

int *p[10] = {NULL};

int main()
{
    for(int i=0; i< 10; i++)
        cout << &p[i] << " ";
}


