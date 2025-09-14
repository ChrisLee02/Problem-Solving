#include <bits/stdc++.h>
using namespace std;

class LFUCache {
 private:
  struct Node {
    int key;
    int value;
    int freq;
  };

  int capacity;

  // freq, list<node>
  unordered_map<int, list<Node>> use_counter;

  // key, node
  unordered_map<int, list<Node>::iterator> cache;
  int min_counter;

 private:
  void incrementFrequencyAndMove(list<Node>::iterator node) {
    int freq = node->freq;
    node->freq++;

    use_counter[freq + 1].splice(use_counter[freq + 1].begin(),
                                 use_counter[freq], node);

    if (use_counter[freq].size() == 0 && min_counter == freq) {
      min_counter = freq + 1;
    }
  }

 public:
  LFUCache(int capacity) {
    this->capacity = capacity;
    this->min_counter = 0;
  }

  int get(int key) {
    auto it = cache.find(key);
    if (it == cache.end()) {
      return -1;
    }

    list<Node>::iterator node = it->second;
    incrementFrequencyAndMove(node);
    return node->value;
  }

  void put(int key, int value) {
    auto it = cache.find(key);
    if (it != cache.end()) {
      list<Node>::iterator node = it->second;
      incrementFrequencyAndMove(node);

      node->value = value;
      return;
    }

    if (capacity == cache.size()) {
      int LRU_key = use_counter[min_counter].back().key;
      cache.erase(LRU_key);
      use_counter[min_counter].pop_back();
    }

    use_counter[1].push_front({key, value, 1});
    cache.emplace(key, use_counter[1].begin());
    min_counter = 1;
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */