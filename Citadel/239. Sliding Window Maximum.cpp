#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow_dumb_map(vector<int>& nums, int k) {
    int i = 0;
    int j = k - 1;

    vector<int> ans;

    map<int, int, greater<int>> window;

    for (int idx = 0; idx < k - 1; idx++) {
      window[nums[idx]]++;
    }

    while (j < nums.size()) {
      window[nums[j]]++;

      ans.push_back(window.begin()->first);

      window[nums[i]]--;
      if (window[nums[i]] == 0) window.erase(nums[i]);

      i++;
      j++;
    }
    return ans;
  }
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // use deque, save index,, remove meaningless indices to keep deque
    // decreasing order

    vector<int> ans;
    deque<int> window;
    for (int i = 0; i < k; i++) {
      while (!window.empty() && nums[window.back()] <= nums[i]) {
        window.pop_back();
      }

      window.push_back(i);
    }

    int i = 0;
    int j = k - 1;

    while (j < nums.size()) {
      // remove elements which are less and order than j
      while (!window.empty() && nums[window.back()] <= nums[j]) {
        window.pop_back();
      }

      // push num[j]
      window.push_back(j);

      // if window.front is i-1, then remove outdated element i-1
      if (window.front() < i) window.pop_front();

      ans.push_back(nums[window.front()]);

      i++;
      j++;
    }
    return ans;
  }
};
