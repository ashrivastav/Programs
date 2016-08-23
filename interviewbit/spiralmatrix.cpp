#include <bits/stdc++.h>


using namespace std;


int main()
{
    int A = 5;
    int size = A + (A-1);
    //int a[size][size];
    vector<vector<int>> a;
    a.resize(size);
	for(int i = 0 ; i < size ; ++i){
	a[i].resize(size);
	}
    int top = 0, bottom = size -1, left= 0, right = size -1;
    int direction = 1;
    int current_num = A;
    int i = top, j = bottom, k = left, l = right;
    
    while(top <= bottom && left <= right)
    {
        if(direction == 1)
        {   k = left;
            while(k <= right)
            {
                a[top][k] = current_num;
                k++;
            }
            top++;
            direction = 2;
        } 
        else if(direction == 2) 
        {   i = top;
            while(i <= bottom)
            {
                a[i][right] = current_num;
                i++;
            }
            right--;
            direction = 3;
        } else if(direction == 3) 
        {   l = right;
            while(l >= left)
            {
                a[bottom][l] = current_num;
                l--;
            }
            bottom--;
            direction = 4;
        } else if(direction == 4) 
        {   j = bottom;
            while(j >= top)
            {
                a[j][left] = current_num;
                j--;
            }
            left++;
            direction = 1;
        }

        if(direction == 1)
            current_num--;
    }

    for(int i = 0 ; i < size; i++)
    {
	
        for(int j = 0; j < size; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}

