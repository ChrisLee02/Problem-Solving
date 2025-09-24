#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  inline string commonPrefix(const string &a, const string &b) {
    string result = "";
    int len = min(a.length(), b.length());
    for (int i = 0; i < len; i++) {
      if (a[i] != b[i]) break;
      result = result += a[i];
    }
    return result;
  }

 public:
  string longestCommonPrefix(vector<string> &strs) {
    string LCP = strs[0];
    for (int i = 1; i < strs.size(); i++) {
      LCP = commonPrefix(LCP, strs[i]);
    }
    return LCP;
  }
};