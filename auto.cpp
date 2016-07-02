#include <iostream>
#include <vector>
#include <string>
using namespace std;
template <typename T>
T abs(T myNum)
{
    if (myNum > 0)
        return myNum;
    else
        return -myNum;
}

constexpr int fact(int n){ return ((n>2)?n * fact(n-1): 1);}

int main()
{
    auto v = {1,2,3,4,5};
    auto strings = {"abhishek","hemant","brajesh"};
    for(auto i: v)
        std::cout << i << std::endl;
    for(auto i:strings)
        cout << i << endl;

    cout << fact(4) << endl;
    cout << fact(5) << endl;
    cout << fact(10) << endl;;

//    double myNegDouble = -5.0;
//    double myDouble = 5.3;

//    cout<< abs(myNegDouble) << endl << abs(myDouble) << endl;
}

