/*
입력
첫째 줄에 N (1 ≤ N ≤ 1,500,000)이 주어진다.

둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 50, 1 ≤ Pi ≤ 1,000)

출력
첫째 줄에 백준이가 얻을 수 있는 최대 이익을 출력한다.
 */



#include <bits/stdc++.h>

using namespace std;

int dp[1500001]; // dp[i] = i-1th day까지 일했을 때의 최대이익, dp[1] = 0;
//dp[i] = max(dp[i-1], dp[i]) => i-1일에 일을 쉬면 dp[i-1], i-1일에 일을 하면 dp[i]값, 이 둘 중에 큰 것을 취한다.
// 그 후 dp[i + T[i]]을 갱신.

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

    for (int i = 1; i <= N; ++i) {
        dp[i] = max(dp[i-1], dp[i]);
        if (i + T[i] - 1 <= N) {
            dp[i + T[i]] = max(dp[i + T[i]], dp[i]+P[i]);
        }
    }

    cout << max(dp[N], dp[N+1]); // 마지막 날 일 할지 안 할지로

}