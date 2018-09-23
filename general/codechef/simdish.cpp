#include <iostream>
#include <set>
#include <sstream>
#include <cmath>

using namespace std;


int main()
{
	int count;
	cin >> count;
	cin.ignore();
	set<string> myset;
	bool first = false;
	float total_count = 0;
	for(int i = 0 ; i < count *2; i++)
	{
		string str;
		string word;
		int second_count = 0;
		getline(cin, str);
		istringstream iss(str);
		first = !first;
		while(first && iss >> word)
		{
			myset.insert(word);
			total_count ++;		
		}
		while(!first && iss >> word)
		{
			if(myset.count(word) != 0)
				second_count++;
		}
		
		if(!first)
		{
			if(second_count >= ceil(total_count/2))
			cout << "similar" << endl;
			else
			cout << "dissimilar" << endl;	
			total_count  =0;
			myset.clear();
		}

	}

}
