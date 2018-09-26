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
  TrieNode *parent = &rootPtr_;
  for(int i = 0; i< pattern.size(); i++) {
    if(childrens_.find(string[i]) != childerns_.end()) {

      TrieNode *trieNode  = new TrieNode();
      trieNode->parent_ = parent;
      childrens_[string[i]] = trieNode;
      parent_ = trieNode;
    } else {
    }

    }

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
