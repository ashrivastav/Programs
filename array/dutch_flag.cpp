#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void three_way_partition(vector<int> &v)
{
    auto low = 0, iterator = 0;
    auto  high = v.size() - 1;

    // increment low till we are finding 0's, as they are already in correct place
    while(low < high && v[low] == 0)
        low++;

    // decrement high till we are finding 2's as they are already in correct place
    while(high > 0 && v[high] == 2)
        high--;

    iterator = low;

    // loop and decide what to do if v[iterator] is 0,1 or 2.
    while(iterator < high)
    {
        switch(v[iterator])
        {
            case 0:
                swap(v[iterator], v[low]);
                low++;
                break;
            case 1:
                iterator++;
                break;
            case 2:
                swap(v[iterator],v[high]);
                high--;
                break;
        }
    }

}

int main()
{

    vector<int> v = {2,1,1,0,0,2,0,1,1,1,2,0,1};

    three_way_partition(v);

    for (auto &i:v)
        cout << i <<" ";
    cout << endl;

}
