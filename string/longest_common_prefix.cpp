#include <bits/stdc++.h>


using namespace std;

string compute(string a1, string a2)
{
	auto l1 = a1.length() - 1;
	auto l2 = a2.length() - 1;
	string result;
	for(auto i=0 , j=0; i <= l1 && j <=l2; i++,j++)
	{
		if(a1[i] == a2[j])
			result.push_back(a1[i]);
		else
			break;
	}

	return result;
}


string longestCommonPrefix(vector<string> &A)
{
	auto vector_size = A.size();
	auto result = A[0];

	for(auto i=0 ; i < vector_size -1 ; i++)
	{
		result = compute(result, A[i+1]);
	}

	return result;
}




int main()
{
	vector<string> str = {  "abcdefgh",

					  "abcefghijk",

					  "abcefgh"
					};

	auto result = longestCommonPrefix(str);
	cout << result << endl;

}
