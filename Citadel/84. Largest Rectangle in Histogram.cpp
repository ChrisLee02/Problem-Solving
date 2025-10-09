#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /* int largestRectangleArea(vector<int>& heights) {
    int ans = 0;

    stack<pair<int, int>> S;  // x1, y1

    for (int x1 = 0; x1 < heights.size(); x1++) {
      int y1 = heights[x1];
      if (S.empty() || S.top().second <= y1) {
        S.push({x1, y1});
      } else {
        int x2, y2;
        while (!S.empty() && S.top().second > y1) {
          x2 = S.top().first;
          y2 = S.top().second;
          S.pop();

          ans = max(ans, y2 * (x1 - x2));
        }
        S.push({x2, y1});
        S.push({x1, y1});
      }
    }

    if (!S.empty()) {
      int x = S.top().first + 1;
      while (!S.empty()) {
        auto [x1, y1] = S.top();
        S.pop();
        ans = max(ans, y1 * (x - x1));
      }
    }
    return ans;
  } */

  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int ans = 0;

    stack<int> S;
    for (int i = 0; i <= n; i++) {
      int h = (i == n) ? 0 : heights[i];
      while (!S.empty() && heights[S.top()] > h) {
        int pos = S.top();
        int height = heights[pos];
        S.pop();

        int left = S.empty() ? 0 : S.top() + 1;
        int right = i - 1;

        ans = max(ans, height * (right - left + 1));
      }

      S.push(i);
    }

    return ans;
  }
};