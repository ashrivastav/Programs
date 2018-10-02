#include <iostream>
#include <unordered_map>
#include <assert.h>
/* Trie for strings */
using namespace std;

namespace trie {

using namespace std;

struct TrieNode {
  std::unordered_map<char, TrieNode*>  childrens_;
  TrieNode* parent_;
  bool endOfWord_;
  TrieNode(): endOfWord_(false), parent_(nullptr){}
};

class Trie {
  TrieNode rootPtr_;
public:
  void InsertWord(const std::string &pattern);
  bool DeleteWord(const std::string &pattern);
  bool SearchWord(const std::string &pattern);
};

void Trie::InsertWord(const std::string &pattern) 
{
  TrieNode *current = &rootPtr_;
  assert(current != nullptr);
  int i = 0;

  for (i = 0; i< pattern.size(); i++) {
    auto& childMap = current->childrens_; //Take reference of child hashmap(compulsory)

    if(childMap.find(pattern[i]) == childMap.end()) {
      TrieNode *trieNode  = new TrieNode();
      trieNode->parent_ = current;
      childMap[pattern[i]] = trieNode;
      current = trieNode;
    } else {
      current = childMap[pattern[i]]; 
    }
  }
  current->endOfWord_ = true;
}

bool Trie::SearchWord(const std::string &pattern)
{
  TrieNode* current = &rootPtr_;
  assert(current != nullptr);
  
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


bool Trie::DeleteWord(const std::string &pattern)
{

return false;
}


}

using namespace trie;

int main()
{
  Trie tr;
  tr.InsertWord("abhishek");
  tr.InsertWord("abhi");
  cout << "Seaching abhi " << std::boolalpha << tr.SearchWord("abhi") << endl;
  cout << "Seaching abh " << std::boolalpha << tr.SearchWord("abh") << endl;
  cout << "Seaching abhishek " << std::boolalpha << tr.SearchWord("abhishek") << endl;
  cout << "Seaching achishek " << std::boolalpha << tr.SearchWord("achishek") << endl;
}
