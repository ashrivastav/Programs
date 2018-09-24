/*
Given a long DNA sequence made up of chars A,C,T,G only. 
Find the min length substring which has atleast one occurrence of each char.

Input:GGACCGTTACCGAAGT
Output:(2,5):ACCGT

struct* substring minLength(char* dna, int len);

GGACCGTTACCGAAGT
*/


#include <iostream>
#include <set>
#include <climits>

using namespace std;

struct Result {
  int start;
  int end;
  string str;
};


/* This function returns the last substring with minimum length in text */
/* Returns Bool true if string found */
bool minString(const string &text, set<char> &pat, Result& result)
{

  int minLength = INT_MAX;
  int currLength = 0;
  int pattern_len = pat.size();
  int text_length =  text.size();
  bool found = false;
  set<char> current_set;
  int start = 0;
  int end = 1;
  
  if (current_set.find(text[start]) == current_set.end()) 
        current_set.insert(text[start]); 


  // Single iteration till length of text - patten size 
  while ((start <= text_length - pattern_len) && end < text_length) 
  {
      // Set current_set with end index character if absent
      if (current_set.find(text[end]) == current_set.end()) 
        current_set.insert(text[end]); 

      // If current_set has all the pattern elements, then check for min length
      //substring
      if (current_set.size() == pattern_len){
        if (minLength >= (end - start + 1)) {
          result.start = start;
          result.end = end;
          minLength = end - start + 1;
          result.str = text.substr(start, minLength);
          found = true;
        }
        if (text[start] == text[end])
        {
          start++; 
          end++;
        } 
        else 
        { 
          current_set.clear();
          start++; // Found smallest substring , start from new index
          // Need better way to track characters in current window, 
          //not efficient to reinsert, hashing might help
          for (int i = start; i <= end; i++)
            current_set.insert(text[i]);

          continue; // Keep searching from next index as minimum is found at this
          // index will all elements
        }
      }

      if (text[start] == text[end])
      {
        start++; 
        end++;
      } 
      else
      {
        end++;
      }
  }
  return found; // Returns true if a single substring found with all characters
}

int main()
{
  string str = "GGACCGTTACCGAAGT";
  //string str = "GACCGGTTAACCGAAGTAC";
  //string str = "GTAC";
  set<char> pat = {'A' , 'C' , 'T', 'G'};
  Result res;
  bool found =  minString(str, pat, res);
  if (found)
  {
    cout << res.str << endl;
    cout << "Start" << res.start << endl;
    cout << "End" << res.end << endl;
  }
  else
    cout << "Not found";
}
