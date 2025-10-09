#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  struct PairComp {
    bool operator()(const vector<int>& p1, const vector<int>& p2) {
      return p1[0] < p2[0];
    }
  };

 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // 1. sort given intervals to increasing order by start position
    // 2. declare merged vector
    // 3. loop through intervals, push back OR merge by overlapping condition

    sort(intervals.begin(), intervals.end(), PairComp());

    vector<vector<int>> merged;
    merged.push_back(intervals.front());

    for (const vector<int>& interval : intervals) {
      if (interval[0] <= merged.back()[1]) {  // merge condition
        merged.back()[1] = max(merged.back()[1], interval[1]);
      } else {
        merged.push_back(interval);
      }
    }

    return merged;
  }
};
