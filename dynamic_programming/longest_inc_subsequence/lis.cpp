/* Program for Longest Increasing Subsequence */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int LongestIncSub(vector<int>& arr)
{
  int size = arr.size();
  vector<int> longestIncSub(size);
  stack<int> stk;
  for(auto &i : longestIncSub)
  {
    i = 1;
  }
  
  vector<int> charIndex(size);
  
  int j = 0;
  int i = 1;
  int maxLength = 1;
  int maxLengthIdx = 0;
  for (int i = 1; i < size ; i++)
    for (int j= 0; j < i; j++)
    {
      if (arr[j] < arr[i]) {
        if (longestIncSub[i] <= (longestIncSub[j] + 1))
        {
          longestIncSub[i] = longestIncSub[j] + 1;
          if (maxLength <= longestIncSub[i]) 
          {
            maxLength = longestIncSub[i];
            maxLengthIdx = i;
            charIndex[i] = j;
          }
        }
      }
    }
  
    int idx = maxLengthIdx;
    int length = 0;
    while(length < maxLength)
    {
      stk.push(arr[idx]);
      idx = charIndex[idx];
      length++;
    }
  
    while(stk.empty() == false) {
      cout << stk.top() << " ";
      stk.pop();
    }

  return maxLength;
  
}

int main() {
 //vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
 vector<int> arr = { 0, 4, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15};
 int longest_inc_sub = LongestIncSub(arr);
 cout <<  "Size of longest inc subsequence" << longest_inc_sub;
 return 0;
}
