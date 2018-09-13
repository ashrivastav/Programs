#include <iostream>
#include <list>
#include <vector>
#include <shared_mutex>
#include <mutex>
#include <thread>
#include <cassert>
#include <algorithm>
#include <thread>

using namespace std;
const size_t BUCKET_SIZE = 1024;

template<typename K, typename V>
/* Entry for the HashTable */
class HashEntry {
  public:
    K key_;
    V value_;
    HashEntry(K key, V value):key_(key), value_(value){}
};

/* Buckets for HashTable, containing HashEntry vector(or list) */
template<typename K, typename V>
class HashBucket {
  private:
    size_t numBucketElem_ = 0;
    mutable shared_mutex mut_; // Reader writer lock
                                    // for cache locality which is fast

 public:
    vector<HashEntry<K,V> >bucket_; //Using vector in place of list 
    // Needed in HashTable for iterating over, for resize
    void Insert(const HashEntry<K,V>& entry)
    {
      unique_lock<shared_mutex> locker(mut_);
        auto key = entry.key_;
        for (auto& it : bucket_) {
          if (it.key_ == key) {
            it.value_ = entry.value_;
            goto done;
          }
        }
      bucket_.push_back(entry);
    done:
      numBucketElem_++;
      return;
    }

    bool Find(const K &key, V &value)
    {
      unique_lock<shared_mutex> locker(mut_);
      for (auto& it : bucket_) {
        if (it.key_ == key) {
          value = it.value_;
          return true;
        }
      }
      return false;
    }

    void Remove(const K& key)
    {
      unique_lock<shared_mutex> locker(mut_);
      for(auto it = bucket_.begin(); it != bucket_.end() ; ) {
        if (it->key_ == key)
          bucket_.erase(it);
      }
    }
    
    void Clear()
    {
      unique_lock<shared_mutex> locker(mut_);
      // for vector
      bucket_.clear();
      bucket_.shrink_to_fit();
    }
};
 
/* HashTable, containing HashBucket */
//Key, Value, HashFunction(default- std::hash)
template<typename K, typename V, typename F = hash<K>>
class HashTable {
public:
  size_t  tableSize_ = 0;
  double  numElem_ = 1;
  double  loadFactor_ = 0;
  HashBucket<K,V> *table_; 
  //Can't use vector for table_ as HashBucket has mutex, which is non movable 
  //and doesn't provide copy constructor, so resize will not work as it needs
  //to copy all values in new vector space if In case when we increase tableSize_
 
  HashTable(const size_t tableSize = BUCKET_SIZE) {
    tableSize_ = tableSize;
    table_  =  new HashBucket<K,V> [tableSize];
  }

  size_t MyHash(K key) 
  {
    F hasher;
    return hasher(key) % tableSize_;
  }   

  void Put(K key, V value) 
  {
    size_t mykey = MyHash(key);
    HashEntry<K,V> entry(key, value);
    table_[mykey].Insert(entry);
    numElem_++;
    loadFactor_ = numElem_ / tableSize_;
    cout << loadFactor_ << endl;
    if (loadFactor_ > 0.75) {
      ReSize(); 
    }
    return;
        
  }

  bool Get(const K& key, V& value)
  {
    size_t mykey = MyHash(key);
    return table_[mykey].Find(key, value); 
  }

  void Delete(const K& key)
  {
    size_t mykey = MyHash(key);
    table_[mykey].Remove(key);
  }

  void Resize()
  {
    size_t oldTableSize = tableSize_;
    auto oldTableRef = table_;

    tableSize_ = 2 * tableSize_; //double each time
    table_  =  new HashBucket<K,V> [tableSize_];
    for (int i = 0 ; i < oldTableSize; i++) {
      oldTableRef[i].;
      oldTableRef[i].Clear();
    }
    delete[] table_;
  }

  ~HashTable() {
   for (int i = 0 ; i < tableSize_; i++) {
      table_[i].Clear();
    }
    delete[] table_;
  }

};

int main()
{
  HashTable<string, int> hashTable;
  hashTable.Put("abhishek", 8);
  hashTable.Put("abhi", 4);
  hashTable.Put("abhis", 5);
  hashTable.Put("abh", 3);
  int value;
  bool result = hashTable.Get("abhis", value);
  if (result)
    cout << "key abhis, Value:" << value << endl;
  else
    cout << "Not found";
  
  hashTable.Delete("abhis");
  result = hashTable.Get("abhis", value);
  if (result)
    cout << "key abhis, Value:" << value << endl;
  else
    cout << "Not found";
   
}

