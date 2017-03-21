#include <iostream>


using namespace std;


bool find_interleving(string &str, string &str1, string &str2 , unsigned int i, unsigned int j,unsigned int k)
{
	static auto flag = false;

	if(i == str.length() && (i = str1.length() + str2.length())) {
		flag =  true;
		return flag;
	}

	if(str[i] == str1[j])
	 find_interleving(str, str1, str2, i+1, j+1, k);

	if(str[i] == str2[k])
	 find_interleving(str, str1, str2, i+1, j, k+1);

	return flag;
}


int main()
{
	string str = "abhishrishvasekta";

	string str1="abhishek";
	string str2="shrivastav";

	bool result = find_interleving(str, str1, str2, 0 , 0 , 0);

	cout << "Two strings interleve the given string " <<  std::boolalpha  << result;
}
