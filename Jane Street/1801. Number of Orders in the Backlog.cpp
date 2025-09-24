#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  const int MOD_CONST = 1e9 + 7;
  const int BUY = 0;
  const int SELL = 1;

 public:
  int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    // priority_queue in c++ is max-heap by default..
    // and it use less by default..
    // which means, less -> max-heap, greater -> min_heap

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
        buy_queue;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        sell_queue;

    for (const vector<int>& order : orders) {
      int price = order[0];
      int amount = order[1];
      int orderType = order[2];

      if (orderType == BUY) {
        while (!sell_queue.empty() && amount > 0) {
          auto [sell_price, sell_amount] = sell_queue.top();
          if (sell_price > price) break;

          int matched_amount = min(amount, sell_amount);
          amount -= matched_amount;
          sell_amount -= matched_amount;

          sell_queue.pop();
          if (sell_amount > 0) sell_queue.push({sell_price, sell_amount});
        }
        if (amount > 0) buy_queue.push({price, amount});
      } else {
        while (!buy_queue.empty() && amount > 0) {
          auto [buy_price, buy_amount] = buy_queue.top();
          if (buy_price < price) break;

          int matched_amount = min(amount, buy_amount);
          amount -= matched_amount;
          buy_amount -= matched_amount;

          buy_queue.pop();
          if (buy_amount > 0) buy_queue.push({buy_price, buy_amount});
        }

        if (amount > 0) sell_queue.push({price, amount});
      }
    }

    int ans = 0;

    while (!buy_queue.empty()) {
      auto [_price, amount] = buy_queue.top();
      buy_queue.pop();
      ans = (ans + amount) % MOD_CONST;
    }

    while (!sell_queue.empty()) {
      auto [_price, amount] = sell_queue.top();
      sell_queue.pop();
      ans = (ans + amount) % MOD_CONST;
    }

    return ans;
  }
};