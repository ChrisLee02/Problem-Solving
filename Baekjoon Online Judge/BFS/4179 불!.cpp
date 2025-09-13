/*
지훈이는 미로에서 일을 한다. 지훈이를 미로에서 탈출하도록 도와주자!

미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부, 그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.

지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다) 이동한다.

불은 각 지점에서 네 방향으로 확산된다.

지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.

지훈이와 불은 벽이 있는 공간은 통과하지 못한다.

입력
입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1000 이다. R은 미로 행의 개수, C는 열의 개수이다.

다음 입력으로 R줄동안 각각의 미로 행이 주어진다.

각각의 문자들은 다음을 뜻한다.

#: 벽
.: 지나갈 수 있는 공간
J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
F: 불이 난 공간
J는 입력에서 하나만 주어진다.

출력
지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는 경우 IMPOSSIBLE 을 출력한다.

지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다.

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


void print_board(int **board, int N, int M) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cout <<Board[i][j]<<" ";
        }
        cout << endl;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, tmp;
    string tmpstr;
    queue<pair<int,int>> Q_Jihun;
    queue<pair<int,int>> Q_fire;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> tmpstr;
        for (int j = 1; j <= M; ++j) {
            if(tmpstr[j-1] == 'J') {
                Q_Jihun.push(pair<int,int>(i,j));
                Visit_Jihun[i][j] = 1;
                dist_Jihun[i][j] = 1;
                Board[i][j] = '.';
                continue;
            }
            if(tmpstr[j-1] == 'F') {
                Q_fire.push(pair<int,int>(i,j));
                Visit_fire[i][j] = 1;
                dist_fire[i][j] = 1;
                Board[i][j] = 'F';
                continue;
            }
            Board[i][j] = tmpstr[j-1];
            dist_fire[i][j] = 9999999;
        }
    }
    /*for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cout <<Board[i][j]<<" ";
        }
        cout << endl;
    }*/

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

    /*for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cout <<dist_Jihun[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cout <<dist_fire[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    */

    if(success) {
        cout << min;
    }
    else {
        cout << "IMPOSSIBLE";
    }


}