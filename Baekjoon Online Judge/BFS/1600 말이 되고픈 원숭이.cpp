/*
동물원에서 막 탈출한 원숭이 한 마리가 세상구경을 하고 있다. 그 녀석은 말(Horse)이 되기를 간절히 원했다. 그래서 그는 말의 움직임을 유심히 살펴보고
 그대로 따라 하기로 하였다. 말은 말이다. 말은 격자판에서 체스의 나이트와 같은 이동방식을 가진다. 다음 그림에 말의 이동방법이 나타나있다.
 x표시한 곳으로 말이 갈 수 있다는 뜻이다. 참고로 말은 장애물을 뛰어넘을 수 있다.

근데 원숭이는 한 가지 착각하고 있는 것이 있다. 말은 저렇게 움직일 수 있지만 원숭이는 능력이 부족해서 총 K번만 위와 같이 움직일 수 있고,
 그 외에는 그냥 인접한 칸으로만 움직일 수 있다. 대각선 방향은 인접한 칸에 포함되지 않는다.

이제 원숭이는 머나먼 여행길을 떠난다. 격자판의 맨 왼쪽 위에서 시작해서 맨 오른쪽 아래까지 가야한다. 인접한 네 방향으로 한 번 움직이는 것,
 말의 움직임으로 한 번 움직이는 것, 모두 한 번의 동작으로 친다. 격자판이 주어졌을 때, 원숭이가 최소한의 동작으로 시작지점에서 도착지점까지
 갈 수 있는 방법을 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 정수 K가 주어진다. 둘째 줄에 격자판의 가로길이 W, 세로길이 H가 주어진다. 그 다음 H줄에 걸쳐 W개의 숫자가 주어지는데,
 0은 아무것도 없는 평지, 1은 장애물을 뜻한다. 장애물이 있는 곳으로는 이동할 수 없다. 시작점과 도착점은 항상 평지이다. W와 H는 1이상 200이하의 자연수이고,
 K는 0이상 30이하의 정수이다.

출력
첫째 줄에 원숭이의 동작수의 최솟값을 출력한다. 시작점에서 도착점까지 갈 수 없는 경우엔 -1을 출력한다.
 */

#include <bits/stdc++.h>

#define X first
#define Y second
#define Pair pair<int,int>
using namespace std;

int Board[201][201];
int Visit[201][201][31];
int Dist[201][201][31];
// 이 Board 정보를 담는 배열의 구조부터 수정해야함. (최단 거리, 벽을 깨부신 횟수)의 형태로 데이터를 저장하면 되겠다.
// visit도 마찬가지로?
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dx_knight[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy_knight[8] = {2, 1, -1, -2, -2, -1, 1, 2};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, tmp, K;
    string tmpstr;
    cin >> K >> M >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> tmp;
            Board[i][j] = tmp;
        }
    }
    //0이 평지, 1이 장애물

    queue<Pair> Q{};
    queue<int> Q2{};
    Q.push(Pair(1,1));
    Q2.push(0);
    Visit[1][1][0] = 1;
    Dist[1][1][0] = 0;
    while(!Q.empty()) {
        Pair cur = Q.front();
        int cur_jump = Q2.front();
        Q.pop();
        Q2.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && Board[nx][ny] == 0 && Visit[nx][ny][cur_jump] == 0) {
                Q.push(Pair(nx, ny));
                Q2.push(cur_jump);
                Visit[nx][ny][cur_jump] = 1;
                Dist[nx][ny][cur_jump] = Dist[cur.X][cur.Y][cur_jump] + 1;
            }
        }

        if(cur_jump<30) {
            for (int i = 0; i < 8; i++) {
                int nx = cur.X + dx_knight[i];
                int ny = cur.Y + dy_knight[i];
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && Board[nx][ny] == 0 && Visit[nx][ny][cur_jump + 1] == 0) {
                    Q.push(Pair(nx, ny));
                    Q2.push(cur_jump + 1);
                    Visit[nx][ny][cur_jump + 1] = 1;
                    Dist[nx][ny][cur_jump + 1] = Dist[cur.X][cur.Y][cur_jump] + 1;
                }
            }
        }
    }
    int min = 9999999;
    for (int i = 0; i <= K; ++i) {
        if(Visit[N][M][i] == 1 && Dist[N][M][i] < min  ) {
            min = Dist[N][M][i];
        }
    }
    if(min == 9999999) {
        cout << -1;
    }
    else {
        cout << min;
    }
    /*for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cout << Dist[i][j][0] << " ";
        }
        cout << endl;
    }
    cout<<endl;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cout << Dist[i][j][1] << " ";
        }
        cout << endl;
    }*/





}
