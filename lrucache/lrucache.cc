
// Generic LRU cache implementation

#include <iostream>
#include <unordered_map>
#include <list>
#include <assert.h>

using namespace std;

// Key and Value types to be c++ literals 
template<typename K, typename V>
class LRUCache {
  private:
    typedef list<pair<K,V>> List;
    
    List LRUList_; //LRU List
    unordered_map<K, typename List::iterator> LRUHash_; //LRU Hash
   
    void RemoveLRUEntry();
    int numElems_; //current number of elems in cache
    int LRUSize_; //Size of Cache

  public:
    LRUCache(int size):LRUSize_(size),numElems_(0) {
    }
    void Insert(const K &key, const V &value);
    bool Lookup(const K &key, V &value);
};

template<typename K, typename V>
void LRUCache<K,V>::RemoveLRUEntry() 
{

  auto lastIterator = LRUList_.end();
  lastIterator--;
  //K key = lastIterator->first;
  LRUHash_.erase(lastIterator->first); //key delete from hash
  LRUList_.erase(lastIterator); //remove iterator from list
  //cout << "\nKey:   " << key << "Removed";
  numElems_--;
}

template<typename K, typename V>
void LRUCache<K,V>::Insert(const K &key, const V &value)
{
  /* Find the element if present in hashtable */
	if (LRUHash_.find(key) != LRUHash_.end()) { //if key present
    
    auto listIterator = LRUHash_[key];
    (*listIterator).second = value;
    if (listIterator != LRUList_.begin()) //already at front return true
      LRUList_.splice(LRUList_.begin(), LRUList_, listIterator); //move front
    return;
  }

  // Check if LRUFull
  if (numElems_ >= LRUSize_) {
    RemoveLRUEntry();
  }

  // If element is absent, push new element
  LRUList_.push_front({key,value});
  auto iter = LRUList_.begin();
  LRUHash_[key] = iter;
  numElems_++;
  return;
}

template<typename K, typename V>
bool LRUCache<K,V>::Lookup(const K &key, V &val)
{
  if (LRUHash_.find(key) != LRUHash_.end()) { //key absent in HT return false

    auto listIterator = LRUHash_[key];
    val = (*listIterator).second; //get value
    if (listIterator != LRUList_.begin()) //already at front return true
      LRUList_.splice(LRUList_.begin(), LRUList_, listIterator); //move front return true
   
    cout << "\nLookup Success Key:  " << key << "   Value:   " << val;
    return true;
  }
 
  cout << "\nKey:   " << key << "Not Found";
  return false;
}

int main()
{
  const int cacheSize = 5;
	LRUCache<int, string> cache(cacheSize);
  
  cache.Insert(1, "india");
  cache.Insert(2, "us");
  cache.Insert(3, "america");
  cache.Insert(4, "africa");
  cache.Insert(1, "china");
  cache.Insert(5, "pak");
  cache.Insert(2, "srilanka");

  string value;
  int key;

  key = 3; 
  cache.Lookup(key, value);
  
  cache.Insert(6, "ratlam");
  cache.Insert(7, "hyderabad");

  key = 4; 
  cache.Lookup(key, value);
  cache.Insert(8, "bangalore");
  
  key = 2; 
  cache.Lookup(key, value);
  cout << endl;
}
