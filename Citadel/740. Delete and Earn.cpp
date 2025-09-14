#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    int count[10001];
    memset(count, 0, sizeof(count));

    for (int num : nums) {
      count[num]++;
    }

    int dp[10001];  // dp[i]: maximum value ended with i,
                    // dp[i] = max(dp[i - 3], dp[i - 2]) + i * count[i];
    dp[0] = 0;
    dp[1] = count[1];
    dp[2] = 2 * count[2];
    for (int i = 3; i <= 10000; i++) {
      dp[i] = max(dp[i - 3], dp[i - 2]) + i * count[i];
    }

    return max(dp[9999], dp[10000]);
  }
};