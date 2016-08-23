#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	int col = A[0].size();
	int row = A.size();
cout << row << endl;
cout << col << endl;
	int direction = 0;

	int top = 0;
	int bottom = row - 1;
    int left = 0;
	int right = col - 1;
    int i = 0;
    int j = 0;
    
    while(top <= bottom && left <= right)
    {
        if(direction == 0)
        {   i = left;
            while(i <= right) {
                 result.push_back(A[top][i]);
                 i++;
            }
            
            direction = 1;
            top++;
        } else  if (direction == 1)
        {
            i = top;
            while( i <= bottom) {
                result.push_back(A[i][right]);
                i++;
            }
            
            direction = 2;
            right--;
        } else if(direction == 2)
        {  
            i = right;
            while(i >= left) {
                result.push_back(A[bottom][i]);
                i--;
            }
            
            direction = 3;
            bottom--;
        } else if (direction == 3)
        {
            i = bottom;
            while(i >= top) {
                result.push_back(A[i][left]);
                i--;
            }
            
            direction = 0;
            left++;
        }
     }

	// DO STUFF HERE AND POPULATE result
	return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

int main()
{
    vector< vector<int> > A = {{1,2},{3,4},{5,6}};
    auto result = spiralOrder(A);

    for(auto i: result)
        cout << i << " ";
}
