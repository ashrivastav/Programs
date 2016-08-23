#include<iostream>
#include <vector>
using namespace std;

// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int coverPoints(vector<int> &X, vector<int> &Y) {
    int sum = 0;
    int length = X.size();
    cout << length << endl;
    for(int i = 0; i < length -1 ; i++)
    {
        if( abs(X[i] - X[i+1]) >=  abs(Y[i] - Y[i+1]))
            sum +=  abs(X[i] -X[i+1]);
        else
            sum += abs(Y[i] - Y[i+1]);
    }
    
    return sum;
}


int main()
{
	vector<int> A = {4 ,8, -7, -5 , -13, 9 , -7, 8};
	vector<int> B = {4, -15, -10, -3, -13, 12, 8 , -8};
	cout << coverPoints(A,B) << endl;
}
