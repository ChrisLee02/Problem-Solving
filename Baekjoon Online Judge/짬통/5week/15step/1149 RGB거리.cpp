/* https://www.acmicpc.net/problem/1149

RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서
모든 집을 칠하는 비용의 최솟값을 구해보자.
1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

입력
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 
한 줄에 하나씩 주어진다. 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.
출력
첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다. */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) 
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, tmp;
    cin >> N;
    int **dp = new int*[N]; // dp[i][RGB] = i번째에서 R/G/B 칠할 때 최적해
    int **costOfPainting= new int*[N];
    for(int i = 0;i<N;i++) {
        dp[i] = new int[3];
        costOfPainting[i] = new int[3];
        cin >> costOfPainting[i][0] >> costOfPainting[i][1] >> costOfPainting[i][2];
    }
    dp[0][0] = costOfPainting[0][0];
    dp[0][1] = costOfPainting[0][1];
    dp[0][2] = costOfPainting[0][2];

    for(int i = 1;i<N;i++) {
        dp[i][0] = costOfPainting[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = costOfPainting[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = costOfPainting[i][2] + min(dp[i-1][1], dp[i-1][0]);
    }
    // for(int i = 0;i<N;i++) {
    //      cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    // }
    cout << min(min(dp[N-1][0], dp[N-1][1]),dp[N-1][2]);
}
