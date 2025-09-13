#include <bits/stdc++.h>

using namespace std;

int coins[11];

int main()
{
    int N, K;
    cin >> N >> K;

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        cin >> coins[i];
    }
    for (int i = N-1; i >=0 ; --i) {
        int coin = coins[i];
        cnt = cnt + K/coin;
        K = K%coin;
    }
    cout << cnt;
}
