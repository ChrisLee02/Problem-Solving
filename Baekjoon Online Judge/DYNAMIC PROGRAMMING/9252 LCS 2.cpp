/*
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 둘째 줄에 LCS를 출력한다.

LCS가 여러 가지인 경우에는 아무거나 출력하고, LCS의 길이가 0인 경우에는 둘째 줄을 출력하지 않는다.
 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

using namespace std;

int N, M;

char str1[1001];
char str2[1001];
int dp[1001][1001];
int backtrack[1001][1001]; // 0: -1, -1 // 1: 0, -1 // 2: -1, 0 로 정의하자.


int main()
{
    FastIO;
    string tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    N = tmp1.length(); M = tmp2.length();
    for (int i = 0; i < tmp1.size(); ++i) {
        str1[i+1] = tmp1[i];
    }
    for (int i = 0; i < tmp2.size(); ++i) {
        str2[i+1] = tmp2[i];
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if(str1[i] == str2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                backtrack[i][j] = 0;
            } else {
                if(dp[i][j-1] > dp[i-1][j]) {
                    dp[i][j] = dp[i][j-1];
                    backtrack[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j];
                    backtrack[i][j] = 2;
                }
            }
        }
    }

    cout << dp[N][M] << endl;

    int i = N;
    int j = M;
    vector<char> ans{};
    while(i != 0 && j != 0) {
        if(backtrack[i][j] == 0) {
            ans.push_back(str1[i]);
            i--; j--;
        }
        else if(backtrack[i][j] == 1) {
            j--;
        } else {
            i--;
        }
    }
    std::reverse(ans.begin(), ans.end());
    for(char c: ans) {
        cout << c;
    }


}