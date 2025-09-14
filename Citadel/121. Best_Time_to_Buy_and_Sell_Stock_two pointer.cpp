#include <bits/stdc++.h>
using namespace std;

/*
문제 설명

121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on
the i-th day.

You want to maximize your profit by choosing a single day to buy one stock and
choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot
achieve any profit, return 0.

Example 1

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6
- 1 = 5. Note that buying on day 2 and selling on day 1 is not allowed because
you must buy before you sell.

Example 2

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints

1 <= prices.length <= 10^5

0 <= prices[i] <= 10^4

*/

// two pointer
// buy_idx와 sell_idx에 대해서, sell이 buy보다 낮아지면 buy를 sell로 옮겨온다.
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int buy_idx = 0;
    int sell_idx = 0;
    int n = static_cast<int>(prices.size());
    int max_ans = 0;

    while (sell_idx < n) {
      int profit = prices[sell_idx] - prices[buy_idx];

      max_ans = max(max_ans, profit);

      if (profit < 0) {
        buy_idx = sell_idx;
      }
      sell_idx++;
    }
    return max_ans;
  };
};

int main(void) {
  vector<int> case1 = vector<int>{7, 1, 5, 3, 6, 4};
  vector<int> case2 = vector<int>{7, 6, 4, 3, 1};

  printf("%d\n", Solution().maxProfit(case1));  // 5
  printf("%d\n", Solution().maxProfit(case2));  // 0
  return 0;
}