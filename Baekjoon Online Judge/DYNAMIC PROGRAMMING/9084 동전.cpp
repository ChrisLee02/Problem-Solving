/*

 */

#include <bits/stdc++.h>

using namespace std;

long long dp[10001];
long long dp_next[10001];
int coin[101];

int main() {
    int T,N,K;
    cin >> T;
    for (int p = 0; p < T; ++p) {

        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> coin[i];
        }
        cin>>K;
        for (int j = 0; j <=K; ++j) {
            dp[j] = 0;
        }
        dp[0] = 1; // 0을 만드는 방법은 아무것도 넣지 않는, 1가지의 경우다.
        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < K; ++k) {
                if(k+coin[i] > K) break;
                dp[k + coin[i]] = dp[k + coin[i]] + dp[k];
            }
        }

        cout << dp[K]<<endl;
    }



}