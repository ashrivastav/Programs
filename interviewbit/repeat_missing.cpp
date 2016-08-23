#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> A;
    int repeating, absent;
   	long long sum = 0, actual_sum  =0 ;
	long long first_term = 0;

	long long sum_sq = 0, actual_sum_sq =0;
	long long second_term =0;
	long long a_plus_b = 0;
	

	for(int i = 1; i <= 100000 ; i++)
		A.push_back(i);

	A[11] = 2;
long long size = A.size();
    cout << "A size   " << A.size() << endl;
    
	for(int i = 0; i< A.size(); i++)
    {
            sum = sum + A[i];
    }

	actual_sum = (size * (size + 1)) / 2;
	cout << "actual sum   " << actual_sum << endl;
	cout << "sum  " << sum << endl;;


	first_term = actual_sum - sum;
	cout << "first ter" << first_term;

    	for(int i = 0; i< A.size(); i++)
    {
            sum_sq = static_cast<long long>( sum_sq + static_cast<long long> (static_cast<long long> (A[i]) * static_cast<long long> (A[i])));
    }

	actual_sum_sq = ((size * (size + 1) * (2*size + 1)) / 6);
	second_term = actual_sum_sq -  sum_sq;

	//cout << "actual sum  sq " << actual_sum_sq << endl;
	//cout << "sum sq " << sum_sq << endl;;
	//cout << "second_term" << second_term << endl;


	a_plus_b = (second_term / first_term);
	absent = (first_term +  a_plus_b ) /2;
	repeating =  absent - first_term;

    cout << "Repeating;" << repeating << endl;
    cout << "Absent" << absent << endl;
}
