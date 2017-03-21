#include <bits/stdc++.h>
using namespace std;


void compute(vector<int> &A)
{
	vector<int> local(A);
	auto size = A.size();
	A.clear();
	int count = 1;
	unsigned int i =0;
	while(i < size)
	{
	count = 1;
	while((i +1 < size) && local[i] == local[i+1])
	{
		count++;
		i++;
	}
	A.push_back(count);
	A.push_back(local[i]);
	i++;
	}
}


string countnsay(auto n)
{
	vector<int> vec = {1};
	for(int i=1;i < n; i++)
	{
		compute(vec);
	}

	stringstream result;
	copy(vec.begin(), vec.end(), ostream_iterator<int>(result,""));
	return result.str();
}




int main()
{
	int n=8;
	string result = countnsay(n);
	cout << result << endl;
}
