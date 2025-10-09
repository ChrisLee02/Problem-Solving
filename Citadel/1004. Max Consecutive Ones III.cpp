#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // The key concept of sliding window:
  /* - it is used for subarray or substring
     - there's a validity condition, expand j every time / check validity / if
     invalid, shrink until valid
  */
  int longestOnes(vector<int>& nums, int k) {
    int i = 0;
    int j = 0;
    int count_zero = 0;
    int ans = 0;
    while (j < nums.size()) {
      if (nums[j] == 0) count_zero++;

      while (count_zero > k) {
        if (nums[i] == 0) count_zero--;
        i++;
      }

      ans = max(ans, j - i + 1);
      j++;
    }
    return ans;
  }
};
