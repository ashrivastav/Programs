#include <iostream>
#include <unordered_map>
#include <assert.h>
/* Trie for strings */
using namespace std;

namespace trie {

using namespace std;
class Trie {

  struct TrieNode {
    std::unordered_map<char, TrieNode*>  childrens_;
    bool endOfWord_;
    TrieNode(): endOfWord_(false){}
  };

  TrieNode rootPtr_;
  bool deleteWord(TrieNode *current, const string& pattern, int index);
public:
  void InsertWord(const string &pattern);
  void DeleteWord(const string &pattern);
  bool SearchWord(const string &pattern);
};

void Trie::InsertWord(const string &pattern) 
{
  TrieNode *current = &rootPtr_; //not null as it is in stack
  int i = 0;

  for (i = 0; i< pattern.size(); i++) {
    auto& childMap = current->childrens_; //Take reference of child hashmap(compulsory)

    if(childMap.find(pattern[i]) == childMap.end()) {
      TrieNode *trieNode  = new TrieNode();
      childMap[pattern[i]] = trieNode;
      current = trieNode;
    } else {
      current = childMap[pattern[i]]; 
    }
  }
  current->endOfWord_ = true;
}

bool Trie::SearchWord(const string &pattern)
{
  TrieNode* current = &rootPtr_;//not null as it is in stack
  
  int i = 0;
  for (i=0; i < pattern.size(); i++) 
  {
      auto& childMap = current->childrens_; //take child reference(space optimization)

      if (childMap.find(pattern[i]) != childMap.end())
      {
       //cout << "\nfound tree node \"" << current <<" \"for : " << pattern[i] << endl; 
       current = childMap[pattern[i]];
      }
      else 
        return false; //node not present
  }

  return current->endOfWord_;
}

bool Trie::deleteWord(TrieNode *current, const string& pattern, int index)
{
    if (current == nullptr)
      return false;

    // Reached the end of string
    if (index == pattern.length())
    {
      if(current->endOfWord_ == false)
        return false; // Already deleted / Invalid word

      current->endOfWord_ = false;
      return (current->childrens_.size() == 0); // if leaf node, delete from parent
    }

    auto& childMap = current->childrens_;
    bool deleteChar = false;
    auto currentChar = pattern[index];

    if (childMap.find(currentChar) != childMap.end())
    {
      current = childMap[currentChar];
      deleteChar = deleteWord(current, pattern, index + 1);
    } 
    else
      return false;
    
    if(current->endOfWord_ == true)
        return false; // Do not delete prefix complete word

    if (deleteChar)
    {
      cout << "\nDeleting char "<< currentChar;
      TrieNode *childNode = childMap[currentChar];
      delete childNode;
      childMap.erase(currentChar);
      return (childMap.size() == 0);
    }
    return false;
}

void Trie::DeleteWord(const string &pattern)
{
    TrieNode *root = &rootPtr_;
    int index = 0;
    cout <<"Deleting word: "<< pattern;
    deleteWord(root, pattern, 0);
}

}

using namespace trie;

int main()
{
  Trie tr;
  tr.InsertWord("abhishek");
  tr.InsertWord("abhi");
  tr.InsertWord("computer");
  tr.InsertWord("computerscience");

  cout << "Seaching abhi " << std::boolalpha << tr.SearchWord("abhi") << endl;
  cout << "Seaching abh " << std::boolalpha << tr.SearchWord("abh") << endl;
  cout << "Seaching abhishek " << std::boolalpha << tr.SearchWord("abhishek") << endl;
  cout << "Seaching achishek " << std::boolalpha << tr.SearchWord("achishek") << endl;
  cout << "Seaching computer " << std::boolalpha << tr.SearchWord("computer") << endl;
  cout << "Seaching computerscience " << std::boolalpha << tr.SearchWord("computerscience") << endl;
  tr.DeleteWord("abhi");
  tr.DeleteWord("computerscience");
  cout << "\nSeaching computer " << std::boolalpha << tr.SearchWord("computer") << endl;
  cout << "\nSeaching computerscience " << std::boolalpha << tr.SearchWord("computerscience") << endl;
  tr.DeleteWord("compute");
  cout << "\nSeaching computer " << std::boolalpha << tr.SearchWord("computer") << endl;
  cout << "\nSeaching computerscience " << std::boolalpha << tr.SearchWord("computerscience") << endl;
  tr.DeleteWord("dance");
  cout << "\nSeaching abhi " << std::boolalpha << tr.SearchWord("abhi") << endl;
}
