#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> sums_cnt;
    sums_cnt[0] = 1;
    int acc_sum = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      acc_sum += nums[i];
      // acc_sum = sums[0...i]
      // acc_sum - sums[0...j] == k
      // # of j where acc_sum - k == sums[0...j]
      // => sums_cnt[acc_sum-k]

      ans += sums_cnt[acc_sum - k];
      sums_cnt[acc_sum]++;
    }
    return ans;
  }
};