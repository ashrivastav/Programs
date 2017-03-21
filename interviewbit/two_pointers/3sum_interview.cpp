#include <iostream>
#include <random>
#include <tuple>
#include <algorithm>
#include <limits.h>
using namespace std;


int three_sum(vector<int> vec, int num) {
    auto length = vec.size();
    
    sort(vec.begin(), vec.end());

    int min_sum = INT_MAX;
    for(int i =0; i < length -2; i++)
       {
           int start = i + 1;
           int end = length - 1;
           
           while(start < end)
           {
               if(abs(vec[i] +  vec[start] + vec[end] - num) < abs(min_sum))
                    min_sum = vec[i] +  vec[start] + vec[end];
               
               if(vec[i] +  vec[start] + vec[end] < num)
               {
                   int current_start = start;
                   while( current_start < end && vec[current_start] == vec[current_start+1])
                   {
                       current_start++;
                   }
                       start = ++current_start;

               } 
               else if (vec[i] + vec[start] + vec[end] > num)
               {
                   auto current_end = end;
                   while(current_end > start && vec[current_end] == vec[current_end -1] )
                   {
                       current_end --;
                   }
                       end = --current_end;
               }
            }
       }
      return min_sum;
}


int main()
{
    vector<int> vec = {10, -6, 3, 4, -8, -5 };
//    vector<int> vec = {-10, -10, -10};
  /*  vector<tuple<int,int,int>> result;
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(-500, 500);
    for(int i = 0; i < 100; i ++)
    {
        vec.push_back(dist(mt));
    }
*/
	
    auto result = three_sum(vec, 3);

    cout << "Result " << result << endl;
 //   for ( const auto& i : result ) {
  //        cout << get<0>(i) <<" , " << get<1>(i) << " , " << get<2>(i) << endl;
  //  }
}






        

