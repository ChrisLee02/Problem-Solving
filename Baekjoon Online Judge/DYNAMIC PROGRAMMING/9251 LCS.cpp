/*
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.


*/

#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
char str1[1001];
char str2[1001];

// X와 Y의 부분 문자열에 대한 LCS를 부분해로 정의. dp[i][j] = X1~Xi와 Y1~Yj의 LCS.
// X[i] == Y[i]면 무조건 dp[i][j]의 끝은 X[i]가 되어야함. 따라서 dp[i][j] = dp[i-1][j-1] + 1
// else, dp[i][j]는 dp[i-1][j] 혹은 dp[i][j-1]. 둘 중에 하나는 포함되지 못하기 때문.

int main() {
    string tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    for (int i = 0; i < tmp1.size(); ++i) {
        str1[i+1] = tmp1[i];
    }
    for (int i = 0; i < tmp2.size(); ++i) {
        str2[i+1] = tmp2[i];
    }
    for (int i = 1; i <= tmp1.size() ; ++i) {
        for (int j = 1; j <= tmp2.size(); ++j) {
            if(str1[i] == str2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[tmp1.size()][tmp2.size()];


}