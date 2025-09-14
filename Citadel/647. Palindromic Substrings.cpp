#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countSubstrings(string s) {
    bool dp[1001][1001];

    for (int i = 0; i < s.length() - 1; i++) {
      dp[i][i] = true;
      dp[i][i + 1] = (s[i] == s[i + 1]);
    }

    dp[s.length() - 1][s.length() - 1] = 1;

    for (int k = 2; k < s.length(); k++) {
      for (int i = 0; i + k < s.length(); i++) {
        dp[i][i + k] = dp[i + 1][i + k - 1] && (s[i] == s[i + k]);
      }
    }

    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
      for (int j = 0; j < s.length(); j++) {
        if (dp[i][j]) ans++;
      }
    }

    return ans;
  }
};