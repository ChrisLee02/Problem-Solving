/*
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다.
 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데,
 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 부수고 이동하여도 된다.

한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000), K(1 ≤ K ≤ 10)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.
 */

// 벽이 없다고 생각하고 경로를 쭉 구한 후에 지나친 벽의 개수가 1인 경로 중 최솟값을 찾아준다.
// 첫 BFS에서 마주친 벽들만 테스트 대상이다.


// 경로를 문자열 형태로 저장해주면 될 듯? 안 될 것 같다. 씨@발

#include <bits/stdc++.h>

#define X first
#define Y second
#define Pair pair<int,int>
using namespace std;

int Board[1001][1001];
int newBoard[1001][1001];
int Visit[1001][1001][11];
int Dist[1001][1001][11];
// 이 Board 정보를 담는 배열의 구조부터 수정해야함. (최단 거리, 벽을 깨부신 횟수)의 형태로 데이터를 저장하면 되겠다.
// visit도 마찬가지로?
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, tmp,K;
    string tmpstr;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> tmpstr;
        for (int j = 1; j <= M; ++j) {
            tmp = tmpstr[j - 1] - '0';
            Board[i][j] = tmp;
        }
    }



//벽이 1이다.
    Pair prev(0, 0);
    vector<int> dist_vec;
    queue<Pair> Q;
    queue<int> Q_tracking; // 벽 통과 횟수에 관한 정보를 담는다
    Q.push(Pair(1, 1));
    Q_tracking.push(0);
    Visit[1][1][0] = 1;
    Dist[1][1][0] = 1;
    while (!Q.empty()) {

        Pair cur = Q.front();
        int count = Q_tracking.front();
        Q_tracking.pop();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && Board[nx][ny] == 0 && Visit[nx][ny][count] == 0) {
                Q.push(Pair(nx, ny));
                Q_tracking.push(count);
                Visit[nx][ny][count] = 1;
                Dist[nx][ny][count] = Dist[cur.X][cur.Y][count] + 1;
            }

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && Board[nx][ny] == 1 && count<=9 && Visit[nx][ny][count+1] == 0) {
                Q.push(Pair(nx, ny));
                Q_tracking.push(count+1);
                Visit[nx][ny][count + 1] = 1;
                Dist[nx][ny][count+1] = Dist[cur.X][cur.Y][count] + 1;
            }

        }

    }
    int min = 9999999;

    for(int i = 0; i<=K; i++) {
        if(Dist[N][M][i] == 0) continue;
        if(Dist[N][M][i] < min ) min = Dist[N][M][i];
    }
    if(min == 9999999) cout << -1;
    else cout << min;

}