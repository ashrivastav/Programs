#include <iostream>
#include <unordered_map>

/* Trie for strings */

namespace trie {

struct TrieNode {
  std::unordered_map<char, TrieNode*>  childrens_;
  TrieNode* parent_;
  bool endOfWord_;
  TrieNode(): endOfWord_(false), parent_(nullptr){}
};

class Trie {
  TrieNode rootPtr_;
  bool InsertWord(const std::string &pattern);
  bool DeleteWord(const std::string &pattern);
  bool SearchWord(const std::string &pattern);
};

bool Trie::InsertWord(const std::string &pattern) 
{

}

bool Trie::DeleteWord(const std::string &pattern)
{

}
bool Trie::SearchWord(const std::string &pattern)
{

}

}

using namespace trie;
int main()
{
  Trie* tr = new Trie();
  tr.InsertWord("abhishek");
  tr.InsertWord("abhi");

}
