/*
여러 섬으로 이루어진 나라가 있다. 이 나라의 대통령은 섬을 잇는 다리를 만들겠다는 공약으로 인기몰이를 해 당선될 수 있었다.
 하지만 막상 대통령에 취임하자, 다리를 놓는다는 것이 아깝다는 생각을 하게 되었다. 그래서 그는, 생색내는 식으로 한 섬과 다른 섬을 잇는 다리 하나만을 만들기로 하였고,
 그 또한 다리를 가장 짧게 하여 돈을 아끼려 하였다.

이 나라는 N×N크기의 이차원 평면상에 존재한다. 이 나라는 여러 섬으로 이루어져 있으며, 섬이란 동서남북으로 육지가 붙어있는 덩어리를 말한다.
 다음은 세 개의 섬으로 이루어진 나라의 지도이다.

위의 그림에서 색이 있는 부분이 육지이고, 색이 없는 부분이 바다이다. 이 바다에 가장 짧은 다리를 놓아 두 대륙을 연결하고자 한다.
 가장 짧은 다리란, 다리가 격자에서 차지하는 칸의 수가 가장 작은 다리를 말한다. 다음 그림에서 두 대륙을 연결하는 다리를 볼 수 있다.

물론 위의 방법 외에도 다리를 놓는 방법이 여러 가지 있으나, 위의 경우가 놓는 다리의 길이가 3으로 가장 짧다(물론 길이가 3인 다른 다리를 놓을 수 있는 방법도 몇 가지 있다).

지도가 주어질 때, 가장 짧은 다리 하나를 놓아 두 대륙을 연결하는 방법을 찾으시오.

입력
첫 줄에는 지도의 크기 N(100이하의 자연수)가 주어진다. 그 다음 N줄에는 N개의 숫자가 빈칸을 사이에 두고 주어지며, 0은 바다, 1은 육지를 나타낸다.
 항상 두 개 이상의 섬이 있는 데이터만 입력으로 주어진다.

출력
첫째 줄에 가장 짧은 다리의 길이를 출력한다.
 */


#include <bits/stdc++.h>

#define X first
#define Y second
#define Pair pair<int,int>
using namespace std;

int Board[101][101];
int Board_separated[101][101];
int Visit[101][101];
int Count[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, tmp;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> tmp;
            Board[i][j] = tmp;
        }
    }
    int team = 0;
    int min_Dist = 9999999;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if(Board[i][j] == 1 && Visit[i][j] == 0 ) {
                team++;
                queue<Pair > Q{};
                Q.push(Pair(i, j));
                Visit[i][j] = 1;
                Board_separated[i][j] = team;
                while (!Q.empty()) {
                    Pair cur = Q.front();
                    Q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];

                        if(nx >= 1 && nx <= N && ny >= 1 && ny <= N && Board[nx][ny] != 0 && Visit[nx][ny] == 0) {
                            Q.push(Pair(nx, ny));
                            Visit[nx][ny] = 1;
                            Board_separated[nx][ny] = team;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            Visit[i][j] = 0;
           // cout << Board_separated[i][j] << " ";
        }
        // cout << endl;
    }
    int time = 1;
    // team 나눔
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if(Board_separated[i][j] != 0 && Visit[i][j] != time ) {
               // cout << i << ","<<j <<endl;
                int team_color = Board_separated[i][j];
                queue<Pair > Q{};
                Q.push(Pair(i, j));
                Visit[i][j] = time;
                Count[i][j] = 0;
                while(!Q.empty()) {
                    Pair cur = Q.front();
                    Q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];

                        if(nx >= 1 && nx <= N && ny >= 1 && ny <= N && Board_separated[nx][ny] == 0 && Visit[nx][ny] != time) {
                            Q.push(Pair(nx, ny));
                            Visit[nx][ny] = time;
                            Count[nx][ny] = Count[cur.X][cur.Y] + 1;
                        }
                        if(nx >= 1 && nx <= N && ny >= 1 && ny <= N && Board_separated[nx][ny] != 0
                        && Board_separated[nx][ny] != team_color && Visit[nx][ny] != time) {
                            Visit[nx][ny] = time;
                            if(Count[cur.X][cur.Y] < min_Dist) {
                                min_Dist = Count[cur.X][cur.Y];
                               // cout << min_Dist << endl;
                            }
                        }

                    }
                }
                time++;
            }
        }
    }
    cout << min_Dist;


}