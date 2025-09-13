#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, vector<int>> table;
    for (int i = 0; i < nums.size(); i++) {
      table[nums[i]].push_back(i);
    }

    for (int i = 0; i < nums.size(); i++) {
      auto table_it = table.find(target - nums[i]);
      if (table_it != table.end()) {
        if (target - nums[i] == nums[i] && table_it->second.size() >= 2) {
          return {table_it->second[0], table_it->second[1]};
        }
        if (target - nums[i] != nums[i]) {
          return {i, table_it->second[0]};
        }
      }
    }
    return {};
  }
};