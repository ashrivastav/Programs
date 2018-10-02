#include <iostream>
#include <string>

using namespace std;

void Substring(const string input,const string output)
{
  if (input.empty() == true) {
    cout << output << endl;
    return;
  }
  
  Substring(input.substr(1), output);
  Substring(input.substr(1), output + input[0]);
}

int main() {
  string input ="ABCDEF";
  string output = "";
  
  Substring(input, output);
  return 0;
}
