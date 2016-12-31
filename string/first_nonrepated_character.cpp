#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool find_first_nonrepeat_char(auto &str, auto &result)
{
	unordered_map<char, int> hm;
	for(auto &i:str)
	{
		auto it = hm.find(i);
		if(it != hm.end())
		{
			hm[i]++;
		}
		else
			hm[i]= 1;
	}

	for(auto &i:str)
	{
		if(hm[i] == 1){
		result = i;
		return true;
		}
	}

	return false;
}


int main()
{
	string str("teether");
	char var;
	auto result = find_first_nonrepeat_char(str, var);

	if(result == true)
		cout << var << endl;
	else
		cout << "No non repeated charter in string" << endl;
}
