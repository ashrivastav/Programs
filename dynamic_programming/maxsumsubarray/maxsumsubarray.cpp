
/* Maximum sum subarry problem 
  Find maximum contiguous array whose sum is maximum, return result and indexes as well */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits>

using namespace std;

/* Kadane Algorithm, Remember this solution */
long MaxSumSubarray(auto &vec, auto &start_idx, auto &end_idx)
{
  long currentMax = vec[0]; 
  long result = vec[0];

  int new_start = 0;
  for (size_t i = 1;  i < vec.size(); ++i )
  {
      if (vec[i] +  currentMax <  vec[i]) { 
      /* if vec[i] + currentMax is -ve, start new window from here */
        currentMax = vec[i];
        new_start = i; //New window is starting from here, so put as new_start
      } else {
        currentMax = vec[i] + currentMax;
      }
      
      if (currentMax >= result){
        result = currentMax;
        start_idx = new_start; 
        //Now, we have exceed result, so last starting point ie new_start will be
        // start_idx and end_idx is also i, if more positive entries comes, 
        // end_idx will keep on incrementing.
        end_idx = i;
      }
   }

  return result;
}

/* Max Sum upto last index + current Index value or Current Index ,
   Choose Current index if last index sum is negative, otherwise take sum of both */ 

/* Remember to choose result & currentMax as first element of vector, for getting correct results if 
  array has all negative numbers */

long MaxSumRecursive(vector<long> &vec, size_t n, long &result)
{
  /* First define boundary condition,
    return first element as currentMax*/
  if (n == 0) {
    return vec[0];
  }

  int currentMax = max(MaxSumRecursive(vec, n-1, result) + vec[n], vec[n]);
 
  if (currentMax > result)
    result = currentMax;
  
  return currentMax;
}


int main()
{
  vector<long> vec = {-2, -3, 4, -1, -2, 1, 5, -3};
  //vector<long> vec = {-2 , 11, -4 , 13, -5, -2};
  //vector<long> vec = {-3, -1, 4, -2, -1, 5}; //Result is 6(sum), 2, 5
  //vector<long> vec = { 1,  -3, 2, -5, 7, 6, -1 , -4, 11, -23};
  cout << "Input array is ";
  for (auto &i: vec)
    cout << i << " ";
  cout << endl;

   /* Recursive approach */
  //long result = numeric_limits<long>::min();
  long result = vec[0];
  MaxSumRecursive(vec, vec.size() - 1, result);
  
  cout << "Maximum contiguous sum is (Recursive) " <<  result << endl;


  /* Kadanes Algo */
  int start_idx = 0, end_idx = 0;
  int maxsum1 = MaxSumSubarray(vec, start_idx, end_idx);
  cout << "Maximum contiguous sum is (Kadanes) " <<  maxsum1 << endl;
  cout << "Starting Idx  " << start_idx << endl;
  cout << "Ending Idx  " << end_idx <<  endl;
}

