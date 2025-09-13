/* https://www.acmicpc.net/problem/1012
한나가 배추를 재배하는 땅은 고르지 못해서 배추를 군데군데 심어 놓았다. 배추들이 모여있는 곳에는 배추흰지렁이가 한 마리만 있으면 되므로 서로 인접해있는 배추들이 몇 군데에 퍼져있는지 조사하면 총 몇 마리의 지렁이가 필요한지 알 수 있다. 예를 들어 배추밭이 아래와 같이 구성되어 있으면 최소 5마리의 배추흰지렁이가 필요하다. 0은 배추가 심어져 있지 않은 땅이고, 1은 배추가 심어져 있는 땅을 나타낸다.

1	1	0	0	0	0	0	0	0	0
0	1	0	0	0	0	0	0	0	0
0	0	0	0	1	0	0	0	0	0
0	0	0	0	1	0	0	0	0	0
0	0	1	1	0	0	0	1	1	1
0	0	0	0	1	0	0	1	1	1
입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50), 그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다. 그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다. 두 배추의 위치가 같은 경우는 없다.

출력
각 테스트 케이스에 대해 필요한 최소의 배추흰지렁이 마리 수를 출력한다. */
#include <iostream>

using namespace std;

void go(int Board[50][50], int M, int N, int x, int y) {
    if(x>=M || y>=N || x<0 || y<0 || Board[x][y] == 0 || Board[x][y] == 2) return;
    Board[x][y] = 2;
    go(Board, M,N, x+1, y );
    go(Board, M,N, x-1, y );
    go(Board, M,N, x, y+1 );
    go(Board, M,N, x, y-1 );
}



int countBoard(int Board[50][50], int M, int N) {
    int snake = 0; // snake+1 값으로 탐색된 1을 바꿔주는 방식이면, 이미 탐색된 부분을 거를 수 있음.
    for(int j = 0; j<M; j++) {
            for(int k = 0; k<N; k++) {
                if(Board[j][k] == 1) {
                    snake++;
                    go(Board,M,N,j,k);
                }
            }
    }
    return snake;
}


int main(void) 
{
    int T, M, N, K, x, y;
    int Board[50][50];
    cin >> T;
    for(int i = 0; i<T;i++) {
        cin >> M >> N >> K;
        for(int j = 0; j<M; j++) {
            for(int k = 0; k<N; k++) {
                Board[j][k] = 0;
            }
        }
        for(int j = 0; j<K;j++) {
            cin >> x >> y;
            Board[x][y] = 1;
        }
        cout << countBoard(Board, M, N)<<'\n';
    }
}