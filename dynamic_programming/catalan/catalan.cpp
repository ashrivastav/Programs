#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/* Catalan number for distinct keys */
// Recursive approach
long long ComputeCatalan(long long numKeys)
{
  if (numKeys < 1)
    return 1;

    long long count = 0;
    for (long long i=1; i <= numKeys ; i++ ) {
      count += ComputeCatalan(numKeys - i) * ComputeCatalan(i -1 );
    }
    return count;
}


long long ComputeCatalanDynamic(long long numKeys)
{
  vector<long long> catalanNum;
  catalanNum.reserve(5000);
  catalanNum[0] = 1; // Null tree, needed for recursion

  int count = 0;
  for(int i = 1; i <= numKeys; i++)
  {
    for( int j = 0 ; j < i; j++ )
    {
      catalanNum[i] += catalanNum[numKeys - i ] * catalanNum [i -1];
    }
  }

  return catalanNum[numKeys];
}


int main()
{
  long long numKeys = 0 ;
  cin >> numKeys;
  cout << "Catalan Number" << ComputeCatalanDynamic(numKeys) << endl;  
  return 0;
}

