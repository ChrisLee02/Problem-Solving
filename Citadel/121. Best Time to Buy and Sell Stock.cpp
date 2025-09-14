#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    int min_buy = prices[0];

    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] > min_buy) {
        ans = max(ans, prices[i] - min_buy);
      }
      min_buy = min(min_buy, prices[i]);
    }

    return ans;
  }
};