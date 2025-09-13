/*
입력
첫째 줄에 N (1 ≤ N ≤ 15)이 주어진다.

둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로 구분되어서 주어지며, 1일부터 N일까지 순서대로 주어진다. (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1,000)

출력
첫째 줄에 백준이가 얻을 수 있는 최대 이익을 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;

int dp[16]; // dp[i] = ith task를 마지막으로 끝낼 때 갖는 최대이익, dp[0], T[0], P[0] = 0으로 정의
int T[16];
int P[16];

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> T[i] >> P[i];
    }
    if(1+T[1] <= N+1) dp[1] = P[1];
    for (int i = 2; i <= N; ++i) {
        int max = 0;
        for (int j = i-1; j >= 1; --j) {
            if( j+T[j] <= i && max < dp[j]) max = dp[j];
        }
        dp[i] = max;
        if(i+T[i] <= N+1) dp[i] = dp[i] + P[i];
    }

    cout << *max_element(dp+1, dp+1+N);

}