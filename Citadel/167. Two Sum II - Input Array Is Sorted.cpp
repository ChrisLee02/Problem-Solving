#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    // two pointer -> in the sorted state, start with
    int i = 0;
    int j = numbers.size() - 1;

    while (i < j) {
      int sum = numbers[i] + numbers[j];
      if (sum == target) break;

      if (sum < target) {
        i++;
      } else {
        j--;
      }
    }

    return {i + 1, j + 1};
  }
};