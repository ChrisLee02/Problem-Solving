#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;

    int ans = 0;

    while (i < j) {
      int width = j - i;
      if (height[i] < height[j]) {
        ans = max(ans, height[i] * width);
        i++;
      } else {
        ans = max(ans, height[j] * width);
        j--;
      }
    }
    return ans;
  }
};
