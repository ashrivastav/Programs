#include <iostream>
#include <bitset>
#include <sstream>

using namespace std;


int main()
{
	int noOfTestcases;
	cin >> noOfTestcases;
	cin.ignore();
	bool some =false, all =false;
	bitset<100000> bitmap;
	for(int i = 0 ; i < noOfTestcases; i++)
	{
		string str;
		getline(cin, str);
		istringstream iss(str);
		int rows, bitsize;
		iss >> rows;
		iss >> bitsize;
		
		for(int j = 0; j < rows; j++)
		{
			getline(cin, str);
			istringstream iss(str);
			int cols;
			iss >> cols;
			for (int k =0 ; k < cols; k++)
			{
				int pos;
				iss >> pos;
				bitmap[pos -1] = 1;
			}
			
			if(bitmap.count() == bitsize)
			{
				if(j < rows-1 )
					some = true;
				else 
					all = true;
			}	
		}
		if(some){
			cout << "some" << endl;
		} else if(all) {
			cout << "all" << endl;
		} else {
			cout << "sad" << endl;
		}
		all = some = false;
		bitmap.reset();
	}			
	
}
