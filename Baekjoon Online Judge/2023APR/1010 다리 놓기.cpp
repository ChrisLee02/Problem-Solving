#include <bits/stdc++.h>

using namespace std;

int combination(int M, int N) { // mCn을 구하는 상황
    int **dp = new int*[M+1];
    for(int i = 1; i<=M; i++) {
        dp[i] = new int[i+1];
        dp[i][0] = 1; dp[i][i] = 1;
    }
    for(int i = 2; i<=M; i++) {
        for(int j = 1; j<i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[M][N];
}

int answer(int N, int M) {

}

int main()
{
    int n, tmp1, tmp2;
    int map[100][100];
    memset(map, 0, sizeof(map));
    cin >> n ;
    for(int i = 0; i<n; i++) {
        cin >> tmp1 >> tmp2;
        cout << combination(tmp2, tmp1) << endl;
    }

}