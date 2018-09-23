#include <iostream>


#define MAX_ELEMS 100000
#define MOD 1000000007

typedef long long ll;
using namespace std;

ll arr[MAX_ELEMS];
int index = 0;
ll sum = 0;
void calc(ll a,ll b, ll c, ll d)
{
    sum = sum + 


ll calculate(ll arr[], int num_elems)
{
    ll a = arr[index];
    ll b = arr[++index];
    calc(a, b, b, a);
}


int main()
{
    
    int testcases, num_elems;
    std::ios::sync_with_stdio(false);
    cin >> testcases;
    for (int i=0; i < testcases; i++)
    {
        cin >> num_elems;

        for (int i=0; i< num_elems; i++)
            cin >> arr[i];
    
        sum_local = calculate(arr, num_elems);
        cout << sum_local;
    }
}


