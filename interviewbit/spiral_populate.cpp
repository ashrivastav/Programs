#include <bits/stdc++.h>

using namespace std;




int main()
{
    const int A = 10000;
    vector< vector<int>> result(A, vector<int>(A));;

    int direction = 0;

    int top = 0;
    int bottom = A -1;
    int left = 0;
    int right = A -1;
    int i = 0;
    int j = 0;
    int num = 1;
    
    while(top <= bottom && left <= right)
    {
        if(direction == 0)
        {   i = left;
            while(i <= right) {
                 result[top][i] = num++;
                 i++;
            }
            
            direction = 1;
            top++;
        } else  if (direction == 1)
        {
            i = top;
            while( i <= bottom) {
                result[i][right] = num++;
                i++;
            }
            
            direction = 2;
            right--;
        } else if(direction == 2)
        {  
            i = right;
            while(i >= left) {
                result[bottom][i] = num++;
                i--;
            }
            
            direction = 3;
            bottom--;
        } else if (direction == 3)
        {
            i = bottom;
            while(i >= top) {
                result[i][left] = num++;
                i--;
            }
            
            direction = 0;
            left++;
        }
     }

  for(auto i = 0; i < A; i++)
{
    for(auto j = 0; j < A; j ++)
{
	//res[i].push_back(result[i][j]);
       cout << result[i][j] << " " ;
}
	cout << endl;
}

}
