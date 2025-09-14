#include <bits/stdc++.h>
using namespace std;

class LRUCache {
 private:
  int capacity;
  unordered_map<int, list<pair<int, int>>::iterator> cache;
  list<pair<int, int>> use_list;

 public:
  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    auto it = cache.find(key);
    if (it == cache.end()) {
      return -1;
    }

    use_list.splice(use_list.begin(), use_list, it->second);
    return it->second->second;
  }

  void put(int key, int value) {
    auto it = cache.find(key);

    if (it != cache.end()) {
      it->second->second = value;
      use_list.splice(use_list.begin(), use_list, it->second);
      return;
    }

    if (cache.size() == capacity) {
      const int LRU_key = use_list.back().first;
      cache.erase(LRU_key);
      use_list.pop_back();
    }

    use_list.emplace_front(key, value);
    cache.insert({key, use_list.begin()});
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */