#include <iostream>
#include <vector>

using namespace std;

int max_sum_subarray(const auto &A)
{
	auto max_overall_sum = A[0];
        auto max_sum_ending_here = A[0];
    
    
    for(int i = 1; i < A.size(); i++)
    {
	max_sum_ending_here = max_sum_ending_here +  A[i];
	if(max_sum_ending_here < A[i])
	{
		max_sum_ending_here = A[i];
	}

        if(max_overall_sum < max_sum_ending_here)
            {
                max_overall_sum = max_sum_ending_here;
            }
    }

    return max_overall_sum;
}

int main()
{
   vector<int> v = {-2, -3, 4, -1, -2, 1, 5, -3};
	//vector<int> v = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	//vector<int> v ={-200, -20};
    cout <<   max_sum_subarray(v);
}
