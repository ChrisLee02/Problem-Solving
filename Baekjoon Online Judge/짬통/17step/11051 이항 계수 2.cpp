// https://www.acmicpc.net/problem/11051
// 동적 계획법으로 더 넓은 범위의 이항계수를 계산하라.
/* 자연수 \(N\)과 정수 \(K\)가 주어졌을 때 이항 계수 
\(\binom{N}{K}\)를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 \(N\)과 \(K\)가 주어진다. (1 ≤ \(N\) ≤ 1,000, 0 ≤ \(K\) ≤ \(N\))

출력
 
\(\binom{N}{K}\)를 10,007로 나눈 나머지를 출력한다. */

#include <iostream>
#include <cmath>

using namespace std;

int fac(int n) {
    if(n == 0) return 1;
    else return n*fac(n-1);
}


int main(void){
    int N,K;
    int M = 10007;
    cin >> N >> K;
    int **dp = new int*[N+1];
    for(int i = 1; i<=N; i++) {
        dp[i] = new int[i+1];
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for(int i = 2; i<=N; i++) {
        for(int j = 1; j<=i-1; j++ ) {
            dp[i][j] = (dp[i-1][j]%M + dp[i-1][j-1]%M)%M;
        }
    }
    cout << dp[N][K];
}