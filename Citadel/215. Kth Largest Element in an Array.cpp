#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> PQ;

    for (int num : nums) {
      PQ.push(num);

      if (PQ.size() == k + 1) PQ.pop();
    }

    return PQ.top();
  }
};