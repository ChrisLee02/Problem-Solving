/*
사무실의 크기와 상태, 그리고 CCTV의 정보가 주어졌을 때, CCTV의 방향을 적절히 정해서, 사각 지대의 최소 크기를 구하는 프로그램을 작성하시오.
https://www.acmicpc.net/problem/15683
입력
첫째 줄에 사무실의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 8)

둘째 줄부터 N개의 줄에는 사무실 각 칸의 정보가 주어진다. 0은 빈 칸, 6은 벽, 1~5는 CCTV를 나타내고, 문제에서 설명한 CCTV의 종류이다.

CCTV의 최대 개수는 8개를 넘지 않는다.

출력
첫째 줄에 사각 지대의 최소 크기를 출력한다.
 */

#include <bits/stdc++.h>

#define Pair pair<int,int>
#define X first
#define Y second
using namespace std;

int Board[9][9];
int Board_copied[9][9];
int N, M;
int cctv_cnt = 0;
int Min = 99999999;
int cur;
int cnt_blacked;
int spot_X[100];
int spot_Y[100];
int spot_cctv[100];
int rotate_cctv[100];
vector<int> one = {0};
vector<int> two = {0, 2};
vector<int> three= {0, 1};
vector<int> four = {0, 1, 2};
vector<int> five = {0, 1, 2, 3};
vector<int> cctv_directions[6] = { {},one, two, three, four, five };

// ->에서부터 반시계 방향으로 0, 1, 2, 3를 부여한다. 그러면 90도 회전은 (a + 1)%4로 표현 가능

void process_watch_one_direction(int direction, int pos_X, int pos_Y) {
    int i;
    switch (direction) {
        case 0:
            i = 1;
            while(pos_X + i  <= N && Board_copied[pos_X + i][pos_Y] != 6 ) {
                Board_copied[pos_X + i][pos_Y] = '#';
                i++;
            }
            break;
        case 1:
            i = 1;
            while(pos_Y + i  <= M && Board_copied[pos_X][pos_Y+i] != 6 ) {
                Board_copied[pos_X][pos_Y+i] = '#';
                i++;
            }
            break;
        case 2:
            i = 1;
            while(pos_X - i  >= 1 && Board_copied[pos_X - i][pos_Y] != 6 ) {
                Board_copied[pos_X - i][pos_Y] = '#';
                i++;
            }
            break;
        case 3:
            i = 1;
            while(pos_Y - i  >= 1 && Board_copied[pos_X][pos_Y-i] != 6 ) {
                Board_copied[pos_X][pos_Y-i] = '#';
                i++;
            }
            break;

    }
}

void process() {
    cnt_blacked = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            Board_copied[i][j] = Board[i][j];
        }
    }

    for (int i = 1; i <= cctv_cnt; ++i) {
        for (int d: cctv_directions[spot_cctv[i]]) {
            process_watch_one_direction((d + rotate_cctv[i])%4 , spot_X[i], spot_Y[i]);
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if(Board_copied[i][j] == 0) {
                cnt_blacked++;
            }
        }
    }
    if(cnt_blacked < Min) Min = cnt_blacked;


}

void fun() {
    if (cur > cctv_cnt) {
        process();
        return;
    }

    for (int i = 0; i < 4; ++i) {
        rotate_cctv[cur] = i;
        cur++;
        fun();
        cur--;
    }

}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> Board[i][j];

            if (Board[i][j] != 0 && Board[i][j] != 6) {
                cctv_cnt++;
                spot_X[cctv_cnt] = i;
                spot_Y[cctv_cnt] = j;
                spot_cctv[cctv_cnt] = Board[i][j];
            }


        }
    }
    cur = 1;
    fun();
    cout << Min;


}
