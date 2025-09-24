#include <bits/stdc++.h>
using namespace std;

class StreamChecker {
 private:
  struct TrieNode {
    bool isEnd;
    TrieNode* children[26] = {nullptr};
  };

  class Trie {
   private:
    TrieNode* root;
    set<TrieNode*> effective_nodes;

   public:
    Trie() { root = new TrieNode(); }

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

    bool query(char letter) {
      bool ans = false;
      int idx = letter - 'a';

      set<TrieNode*> new_effective_nodes;

      if (root->children[idx]) {
        ans = ans || root->children[idx]->isEnd;
        new_effective_nodes.insert(root->children[idx]);
      };

      for (const TrieNode* node : effective_nodes) {
        if (node->children[idx]) {
          ans = ans || node->children[idx]->isEnd;
          new_effective_nodes.insert(node->children[idx]);
        }
      }
      effective_nodes = std::move(new_effective_nodes);
      return ans;
    }
  };

  Trie trie;

 public:
  // manage list of effective node pointers
  StreamChecker(vector<string>& words) {
    for (string word : words) {
      trie.insert(word);
    }
  }

  bool query(char letter) { return trie.query(letter); }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */