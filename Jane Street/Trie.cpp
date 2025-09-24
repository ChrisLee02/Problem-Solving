#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
  bool isEnd = false;
  TrieNode* children[26] = {nullptr};
};

class Trie {
 public:
  TrieNode* root = new TrieNode();

  void insert(string word) {
    TrieNode* node = root;
    for (char c : word) {
      int idx = c - 'a';
      if (!node->children[idx]) {
        node->children[idx] = new TrieNode();
      }
      node = node->children[idx];
    }
    node->isEnd = true;
  }

  bool search(string word) {
    TrieNode* node = root;
    for (char c : word) {
      int idx = c - 'a';
      if (!node->children[idx]) {
        return false;
      }
      node = node->children[idx];
    }
    return node->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
      int idx = c - 'a';
      if (!node->children[idx]) {
        return false;
      }
      node = node->children[idx];
    }
    return true;
  }
};
