#include <iostream>
#include <algorithm>


using namespace std;

void permute(auto& str, auto start, auto end)

{

    if (start == end)
    {
        for(auto &i : str)
        cout << i;
        cout << endl;
    }

   for(auto i = start; i < end ; i++)
   {
       char temp;
       temp = str[i]; str[i] = str[start]; str[start]=temp;
       permute(str, start+1, end);
       temp = str[i]; str[i] = str[start]; str[start]=temp;
    }
}
int main()
{
    vector<char> str = {'a','b','c','d'};
    auto size = str.size();
    permute(str, 0,size);


}
