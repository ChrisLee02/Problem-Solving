/*
입력
첫째 줄부터 25줄에 걸쳐 판이 주어진다. 각 판은 5줄에 걸쳐 주어지며 각 줄에는 5개의 숫자가 빈칸을 사이에 두고 주어진다. 0은 참가자가 들어갈 수 없는 칸,
 1은 참가자가 들어갈 수 있는 칸을 의미한다.

출력
첫째 줄에 주어진 판으로 설계된 미로를 탈출하는 가장 적은 이동 횟수를 출력한다. 단, 어떻게 설계하더라도 탈출이 불가능할 경우에는 -1을 출력한다.
 */

#include <bits/stdc++.h>

#define Pair pair<int,int>
#define X first
#define Y second
#define INF 99999999

using namespace std;

int Board[5][5][5];
int tmp[5][5][5];
int Visit[5][5][5];
int Dist[5][5][5];
int cube[5][5][5];

int isUsed[5];
int Min = INF;
int cur;
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

bool isValidCoordinate(int a, int b, int c) {
    return a >= 0 && a < 5 && b >= 0 && b < 5 && c >= 0 && c < 5;
}
//판 쌓는 순서에 대해 백트래킹, 판 회전에 대해서 백트래킹, 입구 출구에 대해 백트래킹


void BFS(Pair init_XY, int init_Z) {
   // cout<<"BFS S"<<endl;
    if(cube[init_XY.X][init_XY.Y][init_Z] == 0) return;
    queue<Pair> Q1{};
    queue<int> Q2{};
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                Visit[i][j][k] = 0;
            }
        }
    }
    Q1.push(init_XY);
    Q2.push(init_Z);
    Visit[init_XY.X][init_XY.Y][init_Z] = 1;
    Dist[init_XY.X][init_XY.Y][init_Z] = 0;

    while(!Q1.empty()) {
       // cout<<"BFS E"<<endl;

        Pair curXY = Q1.front();
        int curZ = Q2.front();
        Q1.pop();
        Q2.pop();
        for (int i = 0; i < 6; ++i) {
            int nx = curXY.X + dx[i];
            int ny = curXY.Y + dy[i];
            int nz = curZ + dz[i];
            if(isValidCoordinate(nx,ny,nz) && Visit[nx][ny][nz] == 0 && cube[nx][ny][nz] == 1) {
               // cout << nx << " "<<ny << " " << nz << " " << Visit[nx][ny][nz];
                Q1.emplace(nx,ny);
                Q2.push(nz);
                Visit[nx][ny][nz] = 1;
               // cout << " "<< Visit[nx][ny][nz] << endl;
                Dist[nx][ny][nz] = Dist[curXY.X][curXY.Y][curZ] + 1;
            }
        }

    }

    if(Visit[4-init_XY.X][4-init_XY.Y][4-init_Z] && Dist[4-init_XY.X][4-init_XY.Y][4-init_Z] < Min) {
        Min = Dist[4-init_XY.X][4-init_XY.Y][4-init_Z];
    }
}

void rotate(int index) {
    int Board_tmp[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            Board_tmp[i][j] = Board[index][4-j][i];
        }
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            Board[index][i][j] = Board_tmp[i][j];
        }
    }

}

void Board_copy(int (*original)[5], int (*copied)[5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            copied[i][j] = original[i][j];
        }
    }
}

void fun() {
    //cout<<"fun"<<endl;

    if(cur == 5) {
        BFS(Pair(0,0), 0);
        BFS(Pair(0,0), 4);
        BFS(Pair(0,4), 0);
        BFS(Pair(0,4), 4);
        return;
    }

    for (int i = 0; i < 5; ++i) {
        if(!isUsed[i]) {
            isUsed[i] = 1;
            for (int j = 0; j < 4; ++j) {
                rotate(i);
                Board_copy(Board[i], cube[cur]);
                cur++;
                fun();
                cur--;
            }
            isUsed[i] = 0;
        }
    }


}


int main() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                cin >> Board[i][j][k];
            }
        }
    }
    rotate(0);

    /*for (int j = 0; j < 5; ++j) {
        for (int k = 0; k < 5; ++k) {
            cout << Board[0][j][k] << " ";
        }
        cout<<endl;
    }*/
    cur = 0;
    fun();
    if(Min == INF) cout << -1;
    else cout << Min;

}
