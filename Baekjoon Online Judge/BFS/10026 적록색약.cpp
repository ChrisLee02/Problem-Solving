/*
적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.

크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 그림은 몇 개의 구역으로 나뉘어져 있는데,
 구역은 같은 색으로 이루어져 있다. 또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다.
 (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)

예를 들어, 그림이 아래와 같은 경우에

RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)

그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100)

둘째 줄부터 N개 줄에는 그림이 주어진다.

출력
적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력한다.
 */


#include <bits/stdc++.h>

#define X first
#define Y second
#define Pair pair<int,int>
using namespace std;

char Board_normal[1000][1000];
char Board_abnormal[1000][1000];
int Visit_normal[1000][1000];
int Visit_abnormal[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int count_normal = 0;
    int count_abnormal = 0;
    char tmp;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> tmp;
            Board_normal[i][j] = tmp;
            Board_abnormal[i][j] = tmp;
            if (tmp == 'G') {
                Board_abnormal[i][j] = 'R';
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (Visit_normal[i][j] == 0) {
                queue<Pair > Q;
                Q.push(Pair(i, j));
                Visit_normal[i][j] = 1;
                count_normal++;
                while (!Q.empty()) {
                    Pair cur = Q.front();
                    Q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && Visit_normal[nx][ny] == 0 &&
                                Board_normal[nx][ny] == Board_normal[cur.X][cur.Y])
                        {
                            Q.push(Pair(nx,ny));
                            Visit_normal[nx][ny] = 1;
                        }
                    }
                }


            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (Visit_abnormal[i][j] == 0) {
                queue<Pair > Q;
                Q.push(Pair(i, j));
                Visit_abnormal[i][j] = 1;
                count_abnormal++;
                while (!Q.empty()) {
                    Pair cur = Q.front();
                    Q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && Visit_abnormal[nx][ny] == 0 &&
                            Board_abnormal[nx][ny] == Board_abnormal[cur.X][cur.Y])
                        {
                            Q.push(Pair(nx,ny));
                            Visit_abnormal[nx][ny] = 1;
                        }
                    }
                }


            }
        }
    }
    cout << count_normal <<" " << count_abnormal;

}