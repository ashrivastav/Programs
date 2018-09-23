#include <iostream>

using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    cin.ignore();
    string str;
    long long int result = 0;
    for(int i = 0; i < testcases; i++)
    {
        cin >> str;
        int length = str.size();
        long long int num_of_one = 0;
        result = 0;
        long long int num_of_zero = 0;
        bool one_seen = false;
        for( int j = 0; j < length ; j++)
        {
          if(str[j] == '1'){
            if(one_seen && (str[j-1] != '1'))
              result = result + num_of_one * (num_of_zero + 1);
            num_of_one++;
            num_of_zero = 0;
            one_seen = true;
          }else if(str[j] == '0' && one_seen){
              num_of_zero++;
            }
         }  
        if(num_of_zero)    
          result = result + num_of_one * (num_of_zero + 1);
            cout << result << endl;
    }
}
