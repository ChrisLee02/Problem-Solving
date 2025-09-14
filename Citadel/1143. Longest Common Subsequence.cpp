#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    // dp[i][j] => LCS of text[0..i], text[0..j]
    // dp[i][j] = dp[i][j] + 1 or dp[i-1][j] or dp[i][j-1]
    int dp[1001][1001];

    memset(dp, 0, sizeof(dp));

    dp[0][0] = (text1[0] == text2[0]) ? 1 : 0;

    for (int i = 1; i < text1.size(); i++) {
      dp[i][0] = (text1[i] == text2[0]) ? 1 : dp[i - 1][0];
    }

    for (int j = 1; j < text2.size(); j++) {
      dp[0][j] = (text1[0] == text2[j]) ? 1 : dp[0][j - 1];
    }

    for (int i = 1; i < text1.size(); i++) {
      for (int j = 1; j < text2.size(); j++) {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        if (text1[i] == text2[j]) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
      }
    }

    return dp[text1.size() - 1][text2.size() - 1];
  }
};
