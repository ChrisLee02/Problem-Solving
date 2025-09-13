/* https://www.acmicpc.net/problem/2294

n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

입력
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.

출력
첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N, K, tmp, count;
    int value;
    cin >> N >> K;
    vector<int> coins;
    int *dp = new int[K + 1];
    fill_n(dp, K + 1, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        coins.push_back(tmp);
    }
    sort(coins.begin(), coins.end());
    coins.erase(unique(coins.begin(), coins.end()), coins.end());
    N = coins.size();
    count = 1;
    value = coins[N - 1] * count;
    while (value <= K)
    { //큰 동전 기준 배수부터 채움
        dp[value] = count;
        count++;
        value = coins[N - 1] * count;      
    }

    for (int i = N - 2; i >= 0; i--)
    { // 큰 동전부터 시작
        count = 1;
        value = coins[i] * count;
        while (value <= K)
        { //큰 동전 기준 배수부터 채워나간다.   
            for (int j = 1; j <= K; j++)
            {
                if (dp[j]!=0 && j+value<=K && (dp[j + value] == 0 || dp[j + value] > dp[j] + count)) // 덮어쓰기 되는 상황도 고려해야함.
                    dp[j + value] = dp[j] + count;
            }
            if (dp[value] == 0)
            {
                dp[value] = count;
            }
            
            
            count++;
            value = coins[i] * count;           
        }
    }
    if (dp[K] == 0)
        cout << -1;
    else
        cout << dp[K];
}
