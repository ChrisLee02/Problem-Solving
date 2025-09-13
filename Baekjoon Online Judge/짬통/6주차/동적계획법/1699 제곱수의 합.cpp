/* https://www.acmicpc.net/problem/1699

어떤 자연수 N은 그보다 작거나 같은 제곱수들의 합으로 나타낼 수 있다. 예를 들어 11=3^2+1^2+1^2(3개 항)이다. 이런 표현방법은 여러 가지가 될 수 있는데, 11의 경우 11=2^2+2^2+1^2+1^2+1^2(5개 항)도 가능하다. 이 경우, 수학자 숌크라테스는 “11은 3개 항의 제곱수 합으로 표현할 수 있다.”라고 말한다. 또한 11은 그보다 적은 항의 제곱수 합으로 표현할 수 없으므로, 11을 그 합으로써 표현할 수 있는 제곱수 항의 최소 개수는 3이다.

주어진 자연수 N을 이렇게 제곱수들의 합으로 표현할 때에 그 항의 최소개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 100,000)

출력
주어진 자연수를 제곱수의 합으로 나타낼 때에 그 제곱수 항의 최소 개수를 출력한다. */
#include <iostream>
#include <cmath>

using namespace std;

int sqaure(int n, int k, int **dp) {
    if(k<0) return 1000000;
    if(dp[n][k]!=0) return dp[n][k];

    // if((n == 0 && k != 0)) return 10000000;
    // if(n==0 && k ==0) return 0;
    if(k<0) return 1000000;
    if(n==1 || k==0) return k;
    if(n*n==k) {
        dp[n][k] = 1;
        return 1;
    }
    //cout << n << " " << k << " " << sqaure(n-1,k,dp) << "  "<< sqaure(n,k-n*n,dp)+1 << endl;
    dp[n][k] = min(sqaure(n-1,k,dp), sqaure(n,k-n*n,dp)+1);
    //cout << n << " " << k << " " << dp[n][k] <<endl;
    return dp[n][k];
}


int DP(int n, int k, int *dp) {
    if(k<0) return 1000000;
    
    if(n==1||k==0) return k;

    if(dp[k]!=0) return dp[k];
    
    dp[k] = min(DP(n-1, k, dp), DP(n, k-n*n, dp));
    return dp[k];
    
}


int main(void)
{
    int N,tmp,count,iicount;
    cin >> N;
    int sqrtN = int(sqrt(N));
    int dp[100001];
    fill_n(dp,100001, 0);
    DP(sqrtN,N,dp);
    cout << dp[N];
    
    
    
    
    // for(int i = 1; i<=sqrtN;i++) {
    //     for(int j =1;j<=N;j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}


