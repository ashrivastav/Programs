#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/* Maximum sum subarry problemi */


int MaxSumSubarray(auto &vec, auto &start_idx, auto &end_idx)
{
  int currMaxSum = vec[0]; 
  int maxSum = vec[0];

  for (int i = 1;  i < vec.size(); i++ )
  {
      if (vec[i] +  currMaxSum <  vec[i]) {
        currMaxSum = vec[i];
        start_idx = i;
      } else {
        currMaxSum = vec[i] + currMaxSum;
      }
      
      if (currMaxSum > maxSum){
        maxSum = currMaxSum;
        end_idx = i;
      }
   }

  return maxSum;
}



// Recursive approach - by which we can understand what is happening
// At each index, pick whether the ((last sum + current) < current) if yes
// start from current( as the sum became negative), if not i.e number is negative we take it and continue to
// wait for positive number to increase number

vector<int>  maxSum;
int MaxSumsubarray(auto &vec, int num)
{

  if (num == 0) 
  if(vec[0] > 0) {
    maxSum.push_back(vec[0]);
    return vec[0];
  }
  else{ 
    maxSum.push_back(0);
    return 0;
  }

  int currentMax = max((MaxSumsubarray(vec, num-1) + vec[num]), vec[num]);
  maxSum.push_back(currentMax);
  
  return currentMax;
}


int main()
{
  vector<int> vec = {-2, -3, 4, -1, -2, 1, 5, -3};
  //vector<int> vec = {-2 , 11, -4 , 13, -5, -2};
  //vector<int> vec = {1, -3, 4, -2, -1, 6};

  int start_idx = 0, end_idx = 0;
  int maxsum1 = MaxSumSubarray(vec, start_idx, end_idx);
  
  cout << "Maximum contiguous sum is " <<  maxsum1 << endl;
  maxsum1 = MaxSumsubarray(vec, vec.size() -1 );
  auto iter = max_element(maxSum.begin(), maxSum.end());
  for(auto &i: maxSum)
    cout << i << " ";
  cout << "Maximum contiguous sum is (by recursion)" <<  *iter << endl;
  cout << "Starting Idx  " << start_idx << endl;
  cout << "Ending Idx  " << end_idx <<  endl;
}

