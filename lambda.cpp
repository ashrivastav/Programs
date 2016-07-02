#include <iostream>


using namespace std;


int main()
{
  auto add1 = [](int n) { return n+1;};


  cout << add1(20) << endl;
}
