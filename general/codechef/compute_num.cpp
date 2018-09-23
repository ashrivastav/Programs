#include <iostream>
#include <algorithm>


using namespace std;


int main()
{
    vector<int> v = {1,4,6,2,3};
    sort(v.begin(), v.end());

    for(auto &i:v)
        cout << i <<" ";

    auto a = 0, b = 0;
    for(auto &j:v)
    {
        static auto i=0;

        if(i&1)
          a = a*10+j;
        else
            b = b*10 +j;
        i++;
    }
    cout << "a is" << a;
    cout << "b is" << b;
    cout << endl << a+b << endl;


}
