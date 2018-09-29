#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int min(int x, int y, int z)
{
  return (min(min(x,y),z));
}

/* Min edit distane */
int EditDistance(const char *a,const  char *b, int m, int n)
{
  int distance[m+1][n+1]; // arry for computing edit distance
  
  for (int i = 0; i <= m ; ++i)
  {
    for(int j = 0; j <=n; ++j)
    {
      if (i ==0) //fill first row with edit dist
      {
        distance[i][j] = j;
      } 
      else if (j == 0) //fill first column with edit dist
      {
        distance[i][j] = i;
      }
      else if(a[i-1] == b[j-1]) //NO cost incurred if char are same
      {
        distance[i][j] = distance[i-1][j-1];
      }
      else {
        distance[i][j] = 1 + min(distance[i][j-1],//add character
                                 distance[i-1][j],//delee character
                                 distance[i-1][j-1]); //transform character
      } 
    }
  }
  return distance[m][n]; 
}



int main() {
  string s1 = "sunday";
  string s2 = "saturday";
  
  const char *p = s1.c_str();
  const char *q = s2.c_str();
  
  int m = s1.size();
  int n = s2.size();
  int ed = EditDistance(p,q,m,n);
  cout <<" edit distance " << ed << endl;
  return 0;
}
