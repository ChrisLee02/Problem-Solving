/*
문제
3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

입력
첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

출력
첫째 줄에 경우의 수를 출력한다. */


#include <bits/stdc++.h>

using namespace std;

int dp[31]; // dp[i] =  3 X i타일을 채우는 경우의 수

int main() {
    int N;
    cin >> N;
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= N; i=i+2) {
        dp[i] = dp[i-2] * 3;
        for(int j = i-4; j>=0; j=j-2) {
            dp[i] = dp[i] + 2 * dp[j];
        }
    }
    if(N%2) {
        cout << 0;
    }
    else cout << dp[N];
}