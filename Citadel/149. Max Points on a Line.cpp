#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
      return static_cast<size_t>(p.first) << 32 ^ static_cast<size_t>(p.second);
    }
  };

  pair<int, int> getRegulatedSlope(pair<int, int> p) {
    if (p.first == 0) return {0, 1};
    if (p.second == 0) return {1, 0};

    int gcd_val = gcd(p.first, p.second);
    if (p.first < 0) {
      return {-p.first / gcd_val, -p.second / gcd_val};
    } else {
      return {p.first / gcd_val, p.second / gcd_val};
    }
  }

 public:
  int maxPoints(vector<vector<int>>& points) {
    // line equation of a,b / c,d is,,
    // ax + by + c  = 0
    // tuple<a, b, c>
    // and calculate (a,b,c) dot (x,y,1), compare to 0
    int ans = 1;
    int n = points.size();
    for (int i = 0; i < n - 1; i++) {
      unordered_map<pair<int, int>, int, PairHash> slope_table;

      for (int j = i + 1; j < n; j++) {
        vector<int> p1 = points[i];
        vector<int> p2 = points[j];

        pair<int, int> regulated_slope =
            getRegulatedSlope({p1[0] - p2[0], p1[1] - p2[1]});

        auto it = slope_table.find(regulated_slope);
        if (it == slope_table.end()) {
          slope_table[regulated_slope] = 2;
          ans = max(ans, 2);
        } else {
          it->second++;
          ans = max(ans, it->second);
        }
      }
    }

    return ans;
  }
};
