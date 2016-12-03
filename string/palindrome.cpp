#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

int isPalindrome(string A)
{
	auto *A_l = A.c_str();
	auto length = strlen(A_l);
	if (length < 1)
		return 0;
	auto i = length;
	auto lastptr = length;
	auto firstptr = 0;
	auto flag = 0;
	while(firstptr < lastptr)
	{
		auto first = A_l[firstptr];
		auto second = A_l[lastptr];

		if(!isalnum(first))
		{
			firstptr++;
			continue;
		}

		if(!isalnum(second))
		{
			lastptr--;
			continue;
		}

		if(tolower(first) == tolower(second))
		{
			firstptr++;
			lastptr--;
			continue;
		} else
			return 0;
	}

	if(firstptr >= lastptr)
		return 1;

	return 0;
}

int main()
{
	string A = "A man, a plan, a canal: Panama";
	string B = "abba";
	int ret = isPalindrome(B);
	cout << ret << endl;
	ret = isPalindrome(A);
	cout << ret << endl;



}
