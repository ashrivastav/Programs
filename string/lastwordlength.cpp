#include <iostream>
using namespace std;



int main(){


	string str("Thisis       ");
	int count = 0, old_count = 0;
	for(auto i:str)
	{
		if(i != ' ')
			old_count = ++count;
		else
			count = 0;
	}

	cout << old_count << endl;
}
