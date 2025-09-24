#include <bits/stdc++.h>
using namespace std;
class Solution {
  /* You are given two 0-indexed integer arrays nums1 and nums2 of equal length.
  Every second, for all indices 0 <= i < nums1.length, value of nums1[i] is
  incremented by nums2[i]. After this is done, you can do the following
  operation:

  Choose an index 0 <= i < nums1.length and make nums1[i] = 0.
  You are also given an integer x.

  Return the minimum time in which you can make the sum of all elements of nums1
  to be less than or equal to x, or -1 if this is not possible.

  Example 1:

  Input: nums1 = [1,2,3], nums2 = [1,2,3], x = 4
  Output: 3
  Explanation:
  For the 1st second, we apply the operation on i = 0. Therefore nums1 =
  [0,2+2,3+3] = [0,4,6]. For the 2nd second, we apply the operation on i = 1.
  Therefore nums1 = [0+1,0,6+3] = [1,0,9]. For the 3rd second, we apply the
  operation on i = 2. Therefore nums1 = [1+1,0+2,0] = [2,2,0]. Now sum of nums1
  = 4. It can be shown that these operations are optimal, so we return 3.
  123 -> 046 -> 109 ->
  123 -> 140 -> 203 -> 026

  Example 2:

  Input: nums1 = [1,2,3], nums2 = [3,3,3], x = 4
  Output: -1
  Explanation: It can be shown that the sum of nums1 will always be greater than
  x, no matter which operations are performed. */

 public:
  int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
    /*
      2 axioms we can say:
      1. if we apply operation on same index, then it's not the optimal case.
      Because we can change first one with operation on another index, and that
      should be smaller case.
      2. when we apply k times of operations, then that operations should be
      sorted in order of nums2.
      - suppose we apply operaions on 0, 3, 4, 5 sequentially then
      - result = sum(nums1) + sum(nums2)*4 - (nums2[0]*1 + nums2[3]*2 +
      nums2[4]*3 + nums2[5]*4) - (nums1[0] + nums1[3] + nums1[4] + nums1[5])
    */

    vector<pair<int, int>> nums_integrated;
    int N = nums1.size();

    int sum_nums_1 = 0;
    int sum_nums_2 = 0;

    for (int i = 0; i < N; i++) {
      nums_integrated.push_back({nums2[i], nums1[i]});
      sum_nums_1 += nums1[i];
      sum_nums_2 += nums2[i];
    }

    sort(nums_integrated.begin(), nums_integrated.end());

    int dp[1002][1002];  // dp[i][j] = max value of choose j elements among
                         // 0...i (how much deducted from sum(nums2)*j)
                         // dp[i][j] = dp[i-1][j] or
                         // dp[i-1][j-1] + nums2[i]*j + nums1[i]

    for (int i = 0; i <= N; i++) {
      dp[i][0] = 0;
    }

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= i; j++) {
        int nums1_i = nums_integrated[i - 1].second;
        int nums2_i = nums_integrated[i - 1].first;
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + nums2_i * j + nums1_i);
      }
    }

    for (int j = 0; j <= N; j++) {
      if (sum_nums_1 + sum_nums_2 * j - dp[N][j] <= x) return j;
    }
    return -1;
  }
};