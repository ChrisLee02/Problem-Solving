#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    // prefix[i] = sum of 0, ... , i - 1
    // prefix[i+1] - prefix[j] = sum of j ... i

    // prefix[i] - prefix[j] = sum of j, ... , i-1 so its len = i - j

    unordered_map<int, int> mod_idx;

    mod_idx[0] = -1;

    int prefix_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      prefix_sum += nums[i];

      int mod = (prefix_sum % k);
      if (mod < 0) mod += k;

      if (mod_idx.count(mod)) {
        if (i - mod_idx[mod] >= 2) return true;
      } else {
        mod_idx[mod] = i;
      }
    }
    return false;
  }
};