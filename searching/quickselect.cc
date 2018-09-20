//Program to find k largest element

#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int Partition(vector<int> &arr,const int p, const int q)
{
  int pivot = arr[q];
  int i = p;

  for (int j = p; j < q; j++)
  {
     if(arr[j] < pivot)
     {
       swap(arr[j], arr[i]);
       i++;
     }
  }
  swap(arr[i], arr[q]);
  return i;
}

int RandomPartition(vector<int> &arr, const int p, const int q)
{
  int n = q - p + 1;
  int r = rand() % n;
  swap(arr[q], arr[p + r]);
  return Partition(arr, p , q);
}

int findKthLargest(vector<int> &vec, const int k)
{
  int position = 0;
  int start = 0;
  int end = vec.size() - 1;
  int index = k - 1;
  if (index > end) {
    cout << "invalid index";
    return -1;
    }
  do {
        position = RandomPartition(vec, start, end);
        if (position == index)
          return vec[position];
    
        if (position < index)
        {
          start = position + 1;
        }
        else
          end = position - 1;
     } while (true);
}

int main() {
  vector<int> vec = {12, 3, 5, 7, 4, 19, 26};
  int k = 5;
  int result = findKthLargest(vec, k);
  cout<<"Kth largest " << result;
  return 0;
}
