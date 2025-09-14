#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  // !important: should use reference when handling string
  inline bool isPredecessor(const string& wordA, const string& wordB) {
    int diff_count = 0;
    for (int i = 0, j = 0; j < wordB.size(); j++) {
      if (wordA[i] == wordB[j]) {
        i++;
      } else {
        diff_count++;
      }

      if (diff_count == 2) return false;
    }
    return true;
  }

 public:
  int longestStrChain(vector<string>& words) {
    /*
    wordA is a predecessor of wordB if and only if we can insert exactly one
    letter anywhere in wordA without changing the order of the other characters
    to make it equal to wordB.

    For example, "abc" is a predecessor of "abac", while "cba" is not a
    predecessor of "bcad". A word chain is a sequence of words [word1, word2,
    ..., wordk] with k
    >= 1, where word1 is a predecessor of word2, word2 is a predecessor of
    word3, and so on. A single word is trivially a word chain with k == 1.
    */

    // dp[i] = LSC len ended with ith words
    int dp[1001];

    // !important: should use reference when handling string
    sort(words.begin(), words.end(),
         [](const string& a, const string& b) { return a.size() < b.size(); });

    for (int i = 0; i < words.size(); i++) {
      dp[i] = 1;

      for (int j = i - 1; j >= 0; j--) {
        if (words[j].size() == words[i].size()) continue;
        if (words[j].size() + 1 < words[i].size()) break;

        if (isPredecessor(words[j], words[i])) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < words.size(); i++) {
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};