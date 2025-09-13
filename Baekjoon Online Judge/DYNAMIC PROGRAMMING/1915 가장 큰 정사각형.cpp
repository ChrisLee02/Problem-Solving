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
int dp_next[1001][1001];
int Array[1001][1001];
int main() {
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
            dp[i][j] = Array[i][j];
            ans = ans | Array[i][j];
        }
    }

    for (int i = 2; i <= maxSquare; ++i) {
       // cout<<"DD"<<endl;
        bool success = false;
        for (int j = 1; j <= n-i+1; ++j) {
            for (int k = 1; k <= m-i+1; ++k) {
                dp_next[j][k] = dp[j][k] & dp[j+1][k] & dp[j][k+1] & dp[j+1][k+1];
                success = success || dp_next[j][k];
            }
        }
        if(!success) break;
        for (int j = 1; j <= n-i+1; ++j) {
            for (int k = 1; k <= m - i + 1; ++k) {
                dp[j][k] = dp_next[j][k];
            }
        }
        ans = i;
    }
    cout << ans*ans;
}