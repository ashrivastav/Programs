#include <iostream>
#include <list>
#include <vector>
#include <mutex>
#include <thread>
#include <cassert>
#include <algorithm>
#include <thread>

using namespace std;


/* Assumption, key will be unique
   Key will be inserted only once
   as Lookup will be done on key and then insertion
   will happen */
template<typename K, typename V>
class HashTable {
  
  class ListEntry {
  public:
    K key_;
    V value_;
    ListEntry(K key, V value):key_(key), value_(value){}
  };

  class HashEntry {
  public:
    size_t numElem_ = 0;
    mutex mut_;
    list<ListEntry> bucket_;
    bool Insert(const ListEntry& entry)
    {
      auto key = entry.key_;
      for (auto& it : bucket_) {
        if (it.key_ == key)
          return false;
      }
      bucket_.push_back(entry);
      numElem_++;
      return true;
    }

    bool Find(const K &key, V &value)
    {
      for (auto& it : bucket_) {
        if (it.key_ == key) {
          value = it.value_;
          return true;
        }
      }
      return false;
    }
  };
  
  const size_t BUCKET_SIZE = 128;

  size_t  tableSize_ = 0;
  size_t  loadFactor_ = 0;
  vector<HashEntry> table_;
 
  size_t MyHash(K key) 
  {
    hash<K> hasher;
    return hasher(key) % tableSize_;
  }   

public:

  HashTable() {
    HashTable(BUCKET_SIZE);
  }

  HashTable(const size_t tableSize) {
    tableSize_ = tableSize;
    table_.resize(tableSize);
    cout << table_.size();
    this_thread::sleep_for(chrono::seconds(10));
  }

  bool Put(K key, V value) 
  {
    size_t mykey = MyHash(key);
    ListEntry entry(key, value);
    return table_[mykey].Insert(entry);
        
  }

  bool Get(const K& key, V& value)
  {
    size_t mykey = MyHash(key);
    return table_[mykey].Find(key, value); 
  }



};



int main()
{
  HashTable<string, int> hashTable;
  /*bool result;
  result = hashTable.Put("abhishek", 8);
  assert(result);
  result = hashTable.Put("abhi", 4);
  assert(result);
  result = hashTable.Put("abhis", 5);
  assert(result);
  result = hashTable.Put("abh", 3);
  assert(result);
  int value;
  result = hashTable.Get("abhis", value);
  if (result)
    cout << "key abhis, Value:" << value;
    */
}

