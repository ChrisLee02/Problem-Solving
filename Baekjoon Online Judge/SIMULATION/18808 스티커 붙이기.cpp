/*
혜윤이는 스티커를 다 붙인 후의 노트북의 모습이 궁금해졌다.
 노트북의 크기와 스티커들이 주어졌을 때 스티커들을 차례대로 붙이고 난 후 노트북에서 몇 개의 칸이 채워졌는지 구해보자.
https://www.acmicpc.net/problem/18808

입력
첫째 줄에 노트북의 세로와 가로 길이를 나타내는 N(1 ≤ N ≤ 40)과 M(1 ≤ M ≤ 40), 그리고 스티커의 개수 K(1 ≤ K ≤ 100)이 한 칸의 빈칸을 사이에 두고 주어진다.

그 다음 줄부터는 K개의 스티커들에 대한 정보가 주어진다. 각 스티커는 아래와 같은 형식으로 주어진다.

먼저 i번째 스티커가 인쇄된 모눈종이의 행의 개수와 열의 개수를 나타내는 Ri(1 ≤ Ri ≤ 10)와 Ci(1 ≤ Ci ≤ 10)가 한 칸의 빈칸을 사이에 두고 주어진다.

다음 Ri개의 줄에는 각 줄마다 모눈종이의 각 행을 나타내는 Ci개의 정수가 한 개의 빈칸을 사이에 두고 주어진다. 각 칸에 들어가는 값은 0, 1이다.
 0은스티커가 붙지 않은 칸을, 1은 스티커가 붙은 칸을 의미한다.

문제에서 설명한 것과 같이 스티커는 모두 올바른 모눈종이에 인쇄되어 있다. 구체적으로 스티커의 각 칸은 상하좌우로 모두 연결되어 있고,
 모눈종이의 크기는 스티커의 크기에 꼭 맞아서 상하좌우에 스티커에 전혀 포함되지 않는 불필요한 행이나 열이 존재하지 않는다.

출력
첫째 줄에 주어진 스티커들을 차례대로 붙였을 때 노트북에서 스티커가 붙은 칸의 수를 출력한다.
 */

#include <bits/stdc++.h>

#define Pair pair<int,int>
#define X first
#define Y second
using namespace std;
int Board[41][41];
int Board_copied[41][41];


int stickers[101][11][11];
int stickers_W[101];
int stickers_H[101];
int stickers_area[101];
int N, M, K;
int cur;


bool attach(int rotate) {
    int rotated_stickers[11][11];
    int rotated_W = rotate % 2 == 0 ? stickers_W[cur] : stickers_H[cur];
    int rotated_H = rotate % 2 == 0 ? stickers_H[cur] : stickers_W[cur];

    switch (rotate) {
        case 0:
            for (int j = 1; j <= rotated_W; ++j) {
                for (int k = 1; k <= rotated_H; ++k) {
                    rotated_stickers[j][k] = stickers[cur][j][k];
                }
            }
            break;
        case 1:
            for (int j = 1; j <= rotated_W; ++j) {
                for (int k = 1; k <= rotated_H; ++k) {
                    rotated_stickers[j][k] = stickers[cur][stickers_W[cur] - k + 1][j];
                }
            }
            break;
        case 2:
            for (int j = 1; j <= rotated_W; ++j) {
                for (int k = 1; k <= rotated_H; ++k) {
                    rotated_stickers[j][k] = stickers[cur][stickers_W[cur] - j + 1][stickers_H[cur] - k + 1];
                }
            }
            break;
        case 3:
            for (int j = 1; j <= rotated_W; ++j) {
                for (int k = 1; k <= rotated_H; ++k) {
                    rotated_stickers[j][k] = stickers[cur][k][stickers_H[cur] - j + 1];
                }
            }
            break;
    }

    for (int i = 0; i + rotated_W <= N; ++i) {
        for (int j = 0; j + rotated_H <= M; ++j) {
            bool success = true;
            for (int k = 1; k <= rotated_W; ++k) {
                for (int l = 1; l <= rotated_H; ++l) {
                    if(rotated_stickers[k][l] == 1 && Board[k+i][l+j] == 1) {
                        success = false;
                    }
                }
            }
            if(success) {
                for (int k = 1; k <= rotated_W; ++k) {
                    for (int l = 1; l <= rotated_H; ++l) {
                        if(Board[k+i][l+j] == 0 && rotated_stickers[k][l] == 1) Board[k+i][l+j] = rotated_stickers[k][l];
                    }
                }
                return true;
            }

        }
    }




    return false;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= K; ++i) {
        cin >> stickers_W[i] >> stickers_H[i];
        for (int j = 1; j <= stickers_W[i]; ++j) {
            for (int k = 1; k <= stickers_H[i]; ++k) {
                cin >> stickers[i][j][k];
                if (stickers[i][j][k] == 1) stickers_area[i]++;
            }
        }
    }
    int sum = 0;
    for (cur = 1; cur <= K; ++cur) {
        for (int rotate = 0; rotate < 4; ++rotate) {
            if (attach(rotate)) {
                sum = sum + stickers_area[cur];
                break;
            }
        }
    }


    cout << sum;

}
