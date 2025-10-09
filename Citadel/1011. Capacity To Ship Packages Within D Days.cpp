#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  bool isValidContainer(const vector<int>& weights, int days, int container) {
    int consumed_days = 1;
    int container_processing = container;

    for (const int weight : weights) {
      if (weight > container) return false;

      if (container_processing - weight >= 0) {
        container_processing -= weight;
      } else {
        container_processing = container - weight;
        consumed_days++;
      }
    }
    return consumed_days <= days;
  }

 public:
  int shipWithinDays(vector<int>& weights, int days) {
    int lower = 1;
    int upper = 5 * 10000 * 500;

    while (lower < upper) {
      int candidate = (lower + upper) / 2;

      if (isValidContainer(weights, days, candidate)) {
        upper = candidate;
      } else {
        lower = candidate + 1;
      }
    }

    return lower;
  }
};