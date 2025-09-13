/*
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서
 모든 집을 칠하는 비용의 최솟값을 구해보자.

1번 집의 색은 2번, N번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번, 1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1, i+1번 집의 색과 같지 않아야 한다.
입력
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다.
 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.
 */

#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define INF 2000000000;

using namespace std;

int N;

/*int one_case[6] = {0, 0, 1, 1, 2, 2};
int n_case[6] = {1, 2, 0, 2, 0, 1};*/

int dp[3][1001][3];
int cost_of_painting[1001][3];

int main() {
    FastIO;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> cost_of_painting[i][j];
        }
    }
    int ans = 2000000000;
    for (int CASE = 0; CASE < 3; ++CASE) {
        dp[CASE][1][0] = INF;
        dp[CASE][1][1] = INF;
        dp[CASE][1][2] = INF;


        dp[CASE][1][CASE] = cost_of_painting[1][CASE];

        for (int i = 2; i <= N; ++i) {
            dp[CASE][i][0] = min(dp[CASE][i-1][1], dp[CASE][i-1][2]) + cost_of_painting[i][0];
            dp[CASE][i][1] = min(dp[CASE][i-1][0], dp[CASE][i-1][2]) + cost_of_painting[i][1];
            dp[CASE][i][2] = min(dp[CASE][i-1][1], dp[CASE][i-1][0]) + cost_of_painting[i][2];
        }

        dp[CASE][N][CASE] = INF;

        ans = min(ans, min(min(dp[CASE][N][0], dp[CASE][N][1]), dp[CASE][N][2]));




    }
    cout << ans;
}


