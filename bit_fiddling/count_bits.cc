#include <iostream>


using namespace std;



int CountBitsGeneric(int number)
{
  int numBits = 0;
  while (number) {
    if (number & 0x01)
      numBits++;
    number >>= 1;
  }
  return numBits;
}



// Complexity number of 1's in number
int CountBit(int number)
{
  int numBits =0;
  while (number) {
    number = number & (number -1);
    numBits++;
  }
  return numBits;
}


int main()
{
  int bitCount = 0, bitCountGeneric;
  int number = 0;
  cout <<"Enter the number to find number of bits: ";
  cin >> number;
  bitCount = CountBit(number);
  bitCountGeneric = CountBitsGeneric(number);
  cout << "Number of bits: " << bitCount << endl;
  cout << "Number of bits Generic: " << bitCountGeneric << endl;

}
  
