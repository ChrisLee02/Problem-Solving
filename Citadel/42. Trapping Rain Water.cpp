#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int trap(vector<int>& heights) {
    // use stack of (height, x)
    // stack should keep its decreasing order by height
    // then, previous top is base of 'effective height'
    /*
      for each height:

        here: greater than or equal to top, add area, update base, pop
        int base = 0;
        while(!S.empty() && S.top.height <= height) {
          calculate using S.top.x, x, S.top.height, base

          base = S.top.height
        }

        here: less than top
        if (!S.empty()) {
          calculate using S.top.x, x, height, base
        }
        S.push(height, x);
    */
    stack<pair<int, int>> S;
    int ans = 0;

    for (int i = 0; i < heights.size(); i++) {
      int height = heights[i];
      int base = 0;
      while (!S.empty() && S.top().first <= height) {
        // S.top.x, x, S.top.height, base

        int effective_height = S.top().first - base;
        int width = i - S.top().second - 1;

        ans += effective_height * width;

        base = S.top().first;

        S.pop();
      }

      if (!S.empty()) {
        // S.top.x, x, height, base
        int effective_height = height - base;
        int width = i - S.top().second - 1;

        ans += effective_height * width;
      }

      S.push({height, i});
    }

    return ans;
  }
};