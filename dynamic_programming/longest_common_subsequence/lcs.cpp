#include <iostream>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;
/* Bottom up approach */
int lcs(char *a, char* b, int m, int n)
{
  // Take matrix of size m+1 and n+1,(m,n are length of strings)
  int arr[m+1][n+1];

  for(int i=0 ;i <= m ;i++)
  {
    for(int j=0; j <= n;j++)
    {
      if (i ==0 || j == 0) {
        arr[i][j] = 0; //0th row, col zero out
      } else if (a[i -1] == b[j - 1]) {
          arr[i][j] = arr[i-1][j-1] + 1; // if character match add 1 to diagonal element
        }
        else {
          arr[i][j] = max( arr[i-1][j], arr[i][j-1]); //otherwise take max of top or left
        }
     }
  }
  
  stack<char> result;//store result string
  int i = m, j = n; //
  
  /* Compute LCS and print it */
  while (i > 0 && j > 0)
  {
    if (a[i -1] == b[j - 1])
    {
      result.push(a[i-1]);
      i--; j--; // go diagonally up
    }
    else if (arr[i-1][j] > arr[i][j -1]){
          i--;      // go left
    } 
    else {
      j--; // go up
    }
    
  }
  
  //print lcs
  while(result.empty() == false) {
    cout << result.top() << " ";
    result.pop();
  }
  cout << endl;
  
  return arr[m][n]; //return lcs length  

}

int main() {
 char a[] = "AGGTAB"; 
 char b[] = "GXTXAYB"; 
 int m = strlen(a);
 int n = strlen(b);
 int length = lcs(a, b, m,n);
 cout << "lcs length: " << length;
 return 0;
}
