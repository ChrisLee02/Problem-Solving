/*
상근이는 빈 공간과 벽으로 이루어진 건물에 갇혀있다. 건물의 일부에는 불이 났고, 상근이는 출구를 향해 뛰고 있다.
매 초마다, 불은 동서남북 방향으로 인접한 빈 공간으로 퍼져나간다. 벽에는 불이 붙지 않는다. 상근이는 동서남북 인접한 칸으로 이동할 수 있으며,
 1초가 걸린다. 상근이는 벽을 통과할 수 없고, 불이 옮겨진 칸 또는 이제 불이 붙으려는 칸으로 이동할 수 없다. 상근이가 있는 칸에 불이
 옮겨옴과 동시에 다른 칸으로 이동할 수 있다.

빌딩의 지도가 주어졌을 때, 얼마나 빨리 빌딩을 탈출할 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 최대 100개이다.

각 테스트 케이스의 첫째 줄에는 빌딩 지도의 너비와 높이 w와 h가 주어진다. (1 ≤ w,h ≤ 1000)

다음 h개 줄에는 w개의 문자, 빌딩의 지도가 주어진다.

'.': 빈 공간
'#': 벽
'@': 상근이의 시작 위치
'*': 불
각 지도에 @의 개수는 하나이다.

출력
각 테스트 케이스마다 빌딩을 탈출하는데 가장 빠른 시간을 출력한다. 빌딩을 탈출할 수 없는 경우에는 "IMPOSSIBLE"을 출력한다.
 */


#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
char Board[1001][1001];
int Visit_Jihun[1001][1001];
int Visit_fire[1001][1001];
int dist_Jihun[1001][1001];
int dist_fire[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int loop = 0; loop < T; ++loop) {
        int N, M, tmp;
        string tmpstr;
        queue<pair<int,int>> Q_Jihun;
        queue<pair<int,int>> Q_fire;
        cin >> M >> N;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                dist_fire[i][j] = 9999999;
                dist_Jihun[i][j] = 9999999;
                Visit_Jihun[i][j] = 0;
                Visit_fire[i][j] = 0;
            }
        }
        for (int i = 1; i <= N; ++i) {
            cin >> tmpstr;
            for (int j = 1; j <= M; ++j) {
                if(tmpstr[j-1] == '@') {
                    Q_Jihun.push(pair<int,int>(i,j));
                    Visit_Jihun[i][j] = 1;
                    dist_Jihun[i][j] = 1;
                    Board[i][j] = '.';
                    continue;
                }
                if(tmpstr[j-1] == '*') {
                    Q_fire.push(pair<int,int>(i,j));
                    Visit_fire[i][j] = 1;
                    dist_fire[i][j] = 1;
                    Board[i][j] = '*';
                    continue;
                }
                Board[i][j] = tmpstr[j-1];
            }
        }


        while(!Q_fire.empty()) {
            pair<int,int> cur = Q_fire.front();
            Q_fire.pop();
            for(int i = 0; i<4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 1 || nx > N || ny < 1 || ny>M) continue;
                if(Board[nx][ny] == '.' && Visit_fire[nx][ny] == 0) {
                    Visit_fire[nx][ny] = 1;
                    dist_fire[nx][ny] = dist_fire[cur.X][cur.Y] + 1;
                    Q_fire.push(pair<int,int>(nx, ny));
                }
            }
        }



        while(!Q_Jihun.empty()) {
            pair<int,int> cur = Q_Jihun.front();
            Q_Jihun.pop();
            for(int i = 0; i<4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 1 || nx > N || ny < 1 || ny>M) continue;
                if(Board[nx][ny] == '.' && Visit_Jihun[nx][ny] == 0 && dist_fire[nx][ny] > dist_Jihun[cur.X][cur.Y] + 1  ) {
                    // fire 전역변수의 기본값이 0이라서 아예 불이 안닿는데도 방문불가하도록 처리되었었다.
                    Visit_Jihun[nx][ny] = 1;
                    dist_Jihun[nx][ny] = dist_Jihun[cur.X][cur.Y] + 1;
                    Q_Jihun.push(pair<int,int>(nx, ny));
                }
            }
        }

        bool success = false;
        int min = 999999;

        for (int i = 1; i <= N; ++i) {
            if(Visit_Jihun[i][1] == 1 && dist_Jihun[i][1] < min) {
                success = true;
                min = dist_Jihun[i][1];
            }
            if(Visit_Jihun[i][M] == 1 && dist_Jihun[i][M] < min) {
                success = true;
                min = dist_Jihun[i][M];
            }
        }

        for (int j = 1; j <= M; ++j) {
            if(Visit_Jihun[1][j] == 1 && dist_Jihun[1][j] < min) {
                success = true;
                min = dist_Jihun[1][j];
            }
            if(Visit_Jihun[N][j] == 1 && dist_Jihun[N][j] < min) {
                success = true;
                min = dist_Jihun[N][j];
            }
        }

        if(success) {
            cout << min << '\n';
        }
        else {
            cout << "IMPOSSIBLE" << '\n';
        }
    }



}