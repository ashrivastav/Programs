#include <bits/stdc++.h>

using namespace std;

vector<int> generate(vector<int> v, int line)
{
    vector<int> pascal_t;
    int size = v.size();
   
    if(line == 1)
        return v;
        
    pascal_t.push_back(v[0]);
    for(auto i =1; i <v.size(); i++)
    {
        auto elem = v[i] + v[i -1];
        pascal_t.push_back(elem);

    }
    line --;
    pascal_t.push_back(v[size-1]);
	
    return generate(pascal_t, line);
}

int main()
{
    vector<int> v = {1};
    vector<vector<int>> res(10);
    auto A = 10;
    for(int i = 0; i < A ; i++)
    {
    vector<int> result = generate(v, i+1);
	res[i] =  result;
	}
     
    for (int i = 0 ; i <  res.size() ; i ++) {
	for(int j = 0; j < res[i].size(); j++)
		cout << res[i][j] << " " ;
	cout << endl;
}
//    return result;
}

