#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int input_count =0;
    cin >> input_count;
    vector<vector<int>> a;
    a.resize(input_count);
    for (int i = 0; i < input_count; ++i)
          a[i].resize(input_count);
    int sum_1 = 0, sum_2 = 0;
    //cout << input_count;

    for(int i=0;  i<input_count; i++){
        for(int j= 0 ; j<input_count; j++) {
            int num;
            cin >> num;
            a[i][j] = num;

            if(i == j)
                sum_1 = sum_1 + a[i][j];

            if((i+ j) == (input_count -1))
                sum_2 = sum_2 + a[i][j];

        }
    }
    cout  <<  abs(sum_1   -    sum_2);
    return
        0;
}
                                                                                                                                                                      
