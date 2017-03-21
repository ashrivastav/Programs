#include <iostream>
#include <random>
#include <tuple>
#include <algorithm>

using namespace std;


void three_sum(auto &vec, auto &result)
{
    auto length = vec.size();
    
    sort(vec.begin(), vec.end());

    cout << "Sorted" ;
    for(auto i: vec)
        cout << i << " ";

    for(int i =0; i < length - 3; i++)
       {
           int start = i + 1;
           int end = length - 1;
           while(start < end)
           {
               if(vec[i] +  vec[start] + vec[end] ==  0)
               {
                   result.emplace_back(vec[i], vec[start], vec[end]);
                   start++;
               }
               else  if(vec[i] +  vec[start] + vec[end] < 0)
               {
                   int current_start = ++start;
                   while(vec[current_start] == vec[current_start+1] && current_start < end)
                   {
                       current_start++;
                   }
                       start = current_start;

               } 
               else if (vec[i] + vec[start] + vec[end] > 0)
               {
                   auto current_end = --end;
                   while(vec[current_end] == vec[current_end -1] && current_end > start)
                   {
                       current_end --;
                   }
                       end = current_end;
               }
            }
       }
}


int main()
{
    vector<int> vec;
    vector<tuple<int,int,int>> result;
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(-500, 500);
    for(int i = 0; i < 100; i ++)
    {
        vec.push_back(dist(mt));
    }

    three_sum(vec, result);

    cout << "Result" <<  endl;
    for ( const auto& i : result ) {
          cout << get<0>(i) <<" , " << get<1>(i) << " , " << get<2>(i) << endl;
    }
}






        

