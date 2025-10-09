#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> pos_of_char;

    int ans = 0;
    int i, j;  // for two-pointer algorithm
    // a b c d a b c d
    // pwwpkew

    i = j = 0;
    while (j < s.size()) {
      char c = s[j];
      auto it = pos_of_char.find(c);

      if (it != pos_of_char.end() && it->second >= i) {
        i = it->second + 1;
      }

      pos_of_char[c] = j;

      ans = max(ans, j - i + 1);

      j++;
    }
    return ans;
  }
};