/*
입력
첫째 줄에 N (1 ≤ N ≤ 1,500,000)이 주어진다.

둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 50, 1 ≤ Pi ≤ 1,000)

출력
첫째 줄에 백준이가 얻을 수 있는 최대 이익을 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;

int dp[1500001]; // dp[i] = ith day에 일을 시작할 떄 갖는 최대이익, dp[N] = P[N]
// ith day의 work를 채택할 경우 -> dp[i] = dp[i+T[i]] + P[i] // 채택 안 할 경우 -> 그 다음 날에 일을 시작하는 것과 동치, dp[i] = dp[i+1]
int T[1500001];
int P[1500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> T[i] >> P[i];
    }
    if (N + T[N] <= N + 1) dp[N] = P[N];
    for (int i = N - 1; i >= 1; --i) {
        if (i + T[i] <= N+1) {
            dp[i] = max(dp[i+T[i]] + P[i], dp[i+1]);
        } else {
            dp[i] = dp[i+1];
        }


    }

    cout << dp[1];

}