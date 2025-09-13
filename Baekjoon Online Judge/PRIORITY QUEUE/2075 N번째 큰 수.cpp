/*
N×N의 표에 수 N^2개 채워져 있다. 채워진 수에는 한 가지 특징이 있는데, 모든 수는 자신의 한 칸 위에 있는 수보다 크다는 것이다. N=5일 때의 예를 보자.
12	7	9	15	5
13	8	11	19	6
21	10	26	31	16
48	14	28	35	25
52	20	32	41	49
이러한 표가 주어졌을 때, N번째 큰 수를 찾는 프로그램을 작성하시오. 표에 채워진 수는 모두 다르다.

입력
첫째 줄에 N(1 ≤ N ≤ 1,500)이 주어진다. 다음 N개의 줄에는 각 줄마다 N개의 수가 주어진다. 표에 적힌 수는 -10억보다 크거나 같고, 10억보다 작거나 같은 정수이다.

출력
첫째 줄에 N번째 큰 수를 출력한다.
 */

#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

using namespace std;

priority_queue<int, vector<int>, greater<>> priorityQueue{};
// 이미 PQ로 줬는데 왜 따로 만들어서 써 등신아
// 12MB면 그냥 배열로 처리해야됨. 1500^2이면 2250000, int 배열로 구현해야 딱 맞는 메모리 용량임


//int board[1501][1501];
//int board_index[1501]; // board[board[j]][j]로 사용한다.



int main() {
    FastIO;
    int N;
    cin >> N;
//tlqkf
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        priorityQueue.push(tmp);
        if (priorityQueue.size() > N) priorityQueue.pop();
    }
    for (int i = 0; i < N * (N - 1); ++i) {
        int tmp;
        cin >> tmp;
        priorityQueue.push(tmp); priorityQueue.pop();
    }
    // 최소 큐로 만들어서 사이즈를 N으로 유지시키면, 작은 놈들부터 나가니까 최대부터 시작해서 총 N개가 남게 됨.
    cout << priorityQueue.top();

    /*for (int i = 0; i < N; ++i) {
        board_index[i] = N-1;
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j]; // 거꾸로 받는게 맘편하긴 한데, cache hit rate을 고려하면 그냥 받는게 나을 듯 -> 개소리엿고,,
        }
    }

    int max_;
    int maxIndex;
    for (int i = 0; i < N; ++i) {
        max_ = -2100000000;
        maxIndex = -1;
        for (int j = N-1; j >= 0; --j) {
            if(board[board_index[j]][j] > max_) {
                max_ = board[board_index[j]][j];
                maxIndex = j;
            }
        }
        board_index[maxIndex]--;
    }
    cout << max_;*/

}