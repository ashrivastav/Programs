#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void three_way_partition(vector<int> &v)
{
    auto low = 0, mid = 0;
    auto  high = v.size() - 1;

    // increment low till we are finding 0's, as they are already in correct place
    while(low < high && v[low] == 0)
        low++;

    // decrement high till we are finding 2's as they are already in correct place
    while(high > 0 && v[high] == 2)
        high--;

    mid = low;

    // loop and decide what to do if v[mid] is 0,1 or 2.
    while(mid < high)
    {
        switch(v[mid])
        {
            case 0:
                swap(v[mid], v[low]);
                low++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(v[mid],v[high]);
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
