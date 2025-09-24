#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string addStrings_recur(string num1, string num2) {
    if (num1 == "") return num2;
    if (num2 == "") return num1;

    int a = num1.back() - '0';
    int b = num2.back() - '0';

    int c = a + b;
    string result = addStrings_recur(num1.substr(0, num1.size() - 1),
                                     num2.substr(0, num2.size() - 1));

    if (c >= 10) {
      result = addStrings_recur(result, "1");
    }

    return (result + to_string(c % 10));
  }

  string addStrings(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string result;

    while (i >= 0 || j >= 0 || carry != 0) {
      int a = i >= 0 ? num1[i] - '0' : 0;
      int b = j >= 0 ? num2[j] - '0' : 0;

      int c = a + b + carry;

      int carry = (c) / 10;

      result.push_back((c % 10) + '0');
      i--;
      j--;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};