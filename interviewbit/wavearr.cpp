#include<bits/stdc++.h>


using namespace std;


vector<int> convertwave(vector<int> A)
{
	sort(A.begin(), A.end());
    for(int i =1 ; i < A.size(); i+=2)
    {
        if(A[i-1] < A[i])
        {
            swap(A[i] , A[i-1]);
        }

        if( (i < A.size() -1) && A[i] > A[i+1])
        {
            swap(A[i], A[i+1]);
        }
    }

    return A;
}


int main()
{
    //vector<int> A = { 1, 2, 3 , 4 ,5 ,6};
    vector<int> A = { 40, 65, 92, 42, 87, 3, 27, 29, 40, 12};

    vector<int> result;
    result = convertwave(A);

    for(auto &i: result)
        cout << i << " ";
}

