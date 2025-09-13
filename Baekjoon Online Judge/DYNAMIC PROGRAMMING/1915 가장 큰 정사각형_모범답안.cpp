/*
n×m의 0, 1로 된 배열이 있다. 이 배열에서 1로 된 가장 큰 정사각형의 크기를 구하는 프로그램을 작성하시오.

0	1	0	0
0	1	1	1
1	1	1	0
0	0	1	0
위와 같은 예제에서는 가운데의 2×2 배열이 가장 큰 정사각형이다.

입력
첫째 줄에 n, m(1 ≤ n, m ≤ 1,000)이 주어진다. 다음 n개의 줄에는 m개의 숫자로 배열이 주어진다.

출력
첫째 줄에 가장 큰 정사각형의 넓이를 출력한다. */


#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
int Array[1001][1001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int ans;
    cin >> n >> m;
    string tmp;
    int maxSquare = min(n,m);
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        for (int j = 1; j <= m; ++j) {
            Array[i][j] = tmp[j-1] - '0';
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(Array[i][j]) {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    // dp[i][j] = 0,0 ~ i,j까지의 부분 직사각형에서, i,j를 포함하는 최대 정사각형의 크기
    // 그러면 dp[i][j] -> dp[i-1][j]
    // dp문제에서 핵심은 부분 최적해를 어떻게 정의할 것인가, 그리고 그 기준은 optimal structure 를 충족하는지와 점화식이 얼마나 이쁘게 나오는지이다.

    cout << ans*ans;
}