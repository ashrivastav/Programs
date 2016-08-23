#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    long long  number = 0;
   vector<int> A = {0,0,0,0, 1,0, 1, 2, 4, 6, 7, 8, 9, 2, 1, 1, 1, 1,1 ,1 ,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
//	vector<int> A = {0,1,9,9};
     int size = A.size();
	cout << size << endl;

cout << "number is\n";
	for(auto &i: A)
		cout << i;	
     for(auto i = size -1; i >=0; i--)
 	{
		A[i] = (A[i] + 1) %10;
                if(A[i] != 0)
		  break;
	}
	for(int i=0; i< A.size(); i++)
    {
        number = number * 10 + A[i];
    }
	cout << number;
	vector<int> b;
	if(number == 0)
	{
		b.push_back(1);
		for(auto i=0;i<A.size();i++)
		{
			b.push_back(0);
		}
	//	return b;
	}
	auto flag = false; 
	for(auto i = 0; i< A.size(); i++)
	{
	
		if(A[i] != 0 || flag != false){
			b.push_back(A[i]);
			flag = true;
		}
	}
	
			
		

	cout << "number is\n";
	for(auto &i: b)
		cout << i;		

/*
	for(int i=0; i< A.size(); i++)
    {
        number = number * 10 + A[i];
    }
	cout << number;
	number++;
	vector<int> b;
	while(number)
	{
		b.push_back(number %10);
		number = number/10;
	}
	
	reverse(b.begin(), b.end());
	cout << "number is\n";
	for(auto &i: b)
		cout << i;		
*/	
}


