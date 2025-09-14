#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    /*
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation:
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not
    matter.
    -4 -1 -1 -1 0 1 2
    */
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size() - 2; i++) {
      if (nums[i] > 0) break;
      if (i > 0 && nums[i] == nums[i - 1]) continue;

      int target = -1 * nums[i];
      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
        int sum = nums[j] + nums[k];
        if (sum > target) {
          k--;
        } else if (sum < target) {
          j++;
        } else {
          ans.push_back({nums[i], nums[j], nums[k]});
          while (nums[j] == nums[j + 1]) j++;
          j++;
          while (nums[k] == nums[k - 1]) k--;
          k--;
        }
      }
    }

    return ans;
  }
};