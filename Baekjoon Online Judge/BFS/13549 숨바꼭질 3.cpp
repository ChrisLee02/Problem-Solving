/*
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
 */

#include <bits/stdc++.h>

#define X first
#define Y second
#define Pair pair<int,int>
using namespace std;

int Board[100001];
int Visit[100001];
int Dist[100001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K, tmp;
    cin >> N >> K;
    queue<int> Q{};
    Q.push(N);
    Visit[N] = 1;
    Dist[N] = 0;
    if(N!=0) {
        for (int i = 2; N * i <= 100000; i = i * 2) {
            if (Visit[N * i] == 0) {
                Q.push(N * i);
                Visit[N * i] = 1;
                Dist[N * i] = Dist[N];
            }
        }
    }

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        if (cur - 1 >= 0 && Visit[cur - 1] == 0) {
            Q.push(cur-1);
            Visit[cur-1] = 1;
            Dist[cur-1] = Dist[cur] + 1;
            int tmp2 = cur - 1;
            if(tmp2 != 0) {
                for (int i = 2; tmp2 * i <= 100000; i = i * 2) {
                    if (Visit[tmp2 * i] == 0) {
                        Q.push(tmp2 * i);
                        Visit[tmp2 * i] = 1;
                        Dist[tmp2 * i] = Dist[tmp2];
                    }
                }
            }
        }
        if (cur + 1 <= 100000 && Visit[cur + 1] == 0) {
            Q.push(cur+1);
            Visit[cur+1] = 1;
            Dist[cur+1] = Dist[cur] + 1;
            int tmp2 = cur + 1;
            for (int i = 2; tmp2 * i <= 100000; i = i * 2) {
                if (Visit[tmp2 * i] == 0) {
                    Q.push(tmp2 * i);
                    Visit[tmp2 * i] = 1;
                    Dist[tmp2 * i] = Dist[tmp2];
                }
            }
        }
    }
    cout << Dist[K];


}