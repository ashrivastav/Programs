/* Program for Longest Increasing Subsequence */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int LongestIncSub(vector<int>& arr)
{
  int size = arr.size();
  
  //Vector to store longest subsequence length at index i
  vector<int> lisLength(size);
  
  // Stack for traversing backwards for getting subsequence
  stack<int> stk;
  
  //Vector to store from where we got the last value which is added to subsequence
  vector<int> charIndex(size);
  
  //Default set each cell subsequence size to 1, as each element
  // is a subsequence in itself.
  for(auto &i : lisLength)
  {
    i = 1;
  }
  
  /* Logic: Start from 1st index for i and 0th index for j
            keep on comparing a[i]to a[j] if a[i] < a[j],
            check if we can add it to lis
   */
  int j = 0;
  int i = 1;
  int maxLength = 1;
  int maxLengthIdx = 0;
  
  /* After this loop, following things are set
  1. listLength[i] will store longest subsequence length ending at i th index
  2. charIndex[i] will store index of last element added to longest sub seq
  3. maxLength - maximum length of longest sub seq
  4. maxLenghtidx - maximum length index in vector
  */
  
  for (int i = 1; i < size ; i++)
    for (int j= 0; j < i; j++)  // for each i, j goes from 0 to i-1
    {
      // if jth element is smaller, check if this can be in lis
      if (arr[j] < arr[i]) {
        // If current lisLength is smaller at index i than lis[j] + 1,
        // so it is better to include list[j] in result and updated lis[i]
        if (lisLength[i] <= (lisLength[j] + 1))
        {
          lisLength[i] = lisLength[j] + 1; //update new lis ending at i
          charIndex[i] = j; //put which j caused the maxlength to change
          
          //Doing it here to avoid another loop
          if (maxLength <= lisLength[i]) 
          {
            maxLength = lisLength[i];
            maxLengthIdx = i; //ending index of  lis element
          }
        }
      }
    }
  
    int idx = maxLengthIdx;
    int length = 0;
  
    //Traverse backwards for finding elements of sub seq
    while(length < maxLength)
    {
      stk.push(arr[idx]);
      idx = charIndex[idx];
      length++;
    }
  
    // Print all elements of longest inc sub seq
    while(stk.empty() == false) {
      cout << stk.top() << " ";
      stk.pop();
    }

  return maxLength;
  
}

int main() {
 //vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
 //vector<int> arr = { 0, 4, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15};
 vector<int> arr = { 5, 1, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15};
 int longest_inc_sub = LongestIncSub(arr);
 cout <<  "Size of longest inc subsequence" << longest_inc_sub;
 return 0;
}
