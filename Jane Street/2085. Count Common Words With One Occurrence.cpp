#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_map<string, int> words1_table;
    unordered_map<string, int> words2_table;

    for (const string& a : words1) {
      words1_table[a]++;
    }

    for (const string& a : words2) {
      words2_table[a]++;
    }

    int ans = 0;

    for (const auto& [word, count] : words1_table) {
      if (count == 1 && words2_table[word] == 1) ans++;
    }
    return ans;
  }
};