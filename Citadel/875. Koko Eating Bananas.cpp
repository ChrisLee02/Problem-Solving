#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  inline bool isValidK(const vector<int>& piles, int k, int h) {
    long sum = 0;

    for (int pile_size : piles) {
      sum += (long)(pile_size / k) + (pile_size % k == 0 ? 0 : 1);
    }

    return sum <= h;
  }

 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    // we have candidates from 1 to 10^9
    // if we increase k, then total time decrease
    // so we can choose k_cand within lower/upper, and narrow it by whether
    // k_cand is valid or not

    int lower = 1;
    int upper = (int)1e9;

    while (lower < upper) {
      int k_cand = (lower + upper) / 2;
      if (isValidK(piles, k_cand, h)) {
        upper = k_cand;
      } else {
        lower = k_cand + 1;
      }
    }

    return lower;
  }
};