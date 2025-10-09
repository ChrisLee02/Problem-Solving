#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int i, j;
    i = 0;
    j = 0;
    int ans = numeric_limits<int>::max();
    int sum = 0;
    while (j < nums.size()) {
      sum += nums[j];

      while (i < j && sum - nums[i] >= target) {
        sum -= nums[i];
        i++;
      }

      if (sum >= target) ans = min(ans, j - i + 1);

      j++;
    }

    return ans == numeric_limits<int>::max() ? 0 : ans;
  }
};