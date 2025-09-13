/*
 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;


int main() {
    int N, K;
    cin >> N >> K;
    if(N>K) {
        cout << N-K;
        return 0;
    }
    int dp[100001]; //

    memset(dp, -1, sizeof(dp));
    //큐를 이용하면 안쪽 포문을 굳이 무식하게 전체탐색할 이유가 없다. 인접노드는 고작 3개에 불과함
    queue<pair<int, int>> list = queue<pair<int,int>>();
    list.push(pair<int,int>(N, 0));
    while (/*dp[K] == -1*/ !list.empty()) {
        int index = list.front().first;
        if(dp[index] == -1) {
            dp[index] = list.front().second;
            if (index + 1 < 100001  ) list.push(pair<int,int>(index+1, dp[index] + 1));
            if (index - 1 >= 0  ) list.push(pair<int,int>(index-1, dp[index] + 1));
            if (index * 2 < 100001 ) list.push(pair<int,int>(index*2, dp[index] + 1));
        }

        list.pop();
    }
    cout << dp[K];
}