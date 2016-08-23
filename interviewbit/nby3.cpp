#include <iostream>
#include <vector>

using namespace std;


int repeatedNumber(const auto &A)
{
    int count1 = 0, count2 = 0, number1 = 0, number2 = 0, cnt1 =0 , cnt2 = 0;
	int maxnum1 = 0, maxnum2 = 0, maxcount = 0;
 
   for(int i =0; i < A.size(); i++)
    {
    	if(A[i] == number1){
            count1++;
            number1 = A[i];
	} else if(A[i]  == number2) {
            count2++;
            number2 = A[i];
	}
        else if(count1 == 0)
		{ count1++; number1 = A[i]; }
	else if(count2 == 0)
		{ count2++; number2 = A[i];}
	 else {
	    count2--;
            count1--;
        }
    }

   for(int i = 0; i < A.size(); i++)
    {
        if(A[i] ==  number1)
            cnt1++;
        if(A[i] ==  number2)
            cnt2++;
    }
//cout << cnt1 << "," << cnt2 << "------------" << maxnum1 << "--------------" << maxnum2 << endl;
   if(cnt1 > A.size()/3){
//	cout << "counter:   " << cnt1 << "value   " << number1 << endl;
    return number1;
	}
   else if(cnt2 > A.size()/3) {
//cout << "counter:      " << cnt2 << "value   " << number2 << endl;
    return number2;
	}
   else
    return -1;
}


int main()
{
    //vector<int> A = {1000727, 1000727, 1000641, 1000517, 1000212, 1000532, 1000727, 1001000, 1000254, 1000106, 1000405, 1000100, 1000736, 1000727, 1000727, 1000787, 1000105, 1000713, 1000727, 1000333, 1000069, 1000727, 1000877, 1000222, 1000727, 1000505, 1000641, 1000533, 1000727, 1000727, 1000727, 1000508, 1000475, 1000727, 1000573, 1000727, 1000618, 1000727, 1000309, 1000486, 1000792, 1000727, 1000727, 1000426, 1000547, 1000727, 1000972, 1000575, 1000303, 1000727, 1000533, 1000669, 1000489, 1000727, 1000329, 1000727, 1000050, 1000209, 1000109};
	vector<int> A = {1,1};
    int num = repeatedNumber(A);
    cout << num;
}
