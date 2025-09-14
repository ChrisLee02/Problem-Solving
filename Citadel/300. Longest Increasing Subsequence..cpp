#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lengthOfLIS_N2(vector<int>& nums) {
    // dp[i] = LIS which ends with nums[i]
    // dp[i] = 1 (base case, only itself), dp[i] = dp[j] + 1 where j < i and
    // nums[j] < nums[i]
    int dp[2501];
    dp[0] = 1;

    for (int i = 1; i < nums.size(); i++) {
      dp[i] = 1;

      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i] && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
        }
      }
    }

    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
      ans = max(ans, dp[i]);
    }
    return ans;
  }

  int lengthOfLIS(vector<int>& nums) {
    vector<int> dumb_lis;

    for (int i = 0; i < nums.size(); i++) {
      auto it = lower_bound(dumb_lis.begin(), dumb_lis.end(), nums[i]);
      if (it == dumb_lis.end()) {
        dumb_lis.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
    }

    return dumb_lis.size();
  }
};
