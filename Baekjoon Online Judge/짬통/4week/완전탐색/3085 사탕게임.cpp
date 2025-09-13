/* https://www.acmicpc.net/problem/3085
상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.

가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다. 상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 그 다음 고른 칸에 들어있는 사탕을 서로 교환한다. 이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)

다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.

사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.

출력
첫째 줄에 상근이가 먹을 수 있는 사탕의 최대 개수를 출력한다.*/

#include <iostream>
#include <string>


using namespace std;

int lineMax(string *Board, int i, bool isRowLine) { //i는 i번째 열 또는 행을 가리킴.
    int cont = 1;
    int max=0;
    if(isRowLine) { //가로줄 받는 경우라면.
        for(int j = 0 ; j<Board[i].size() - 1; j++ ) {
             if(Board[i][j] == Board[i][j+1]) {
                 cont++;
                 if(max<cont) max =cont;
             }
             else {
                 cont = 1;
             }
        }
        return max;
    }
    else { //세로줄 받는 경우라면
        for(int j = 0 ; j < Board[i].size() - 1; j++ ) {
             if(Board[j][i] == Board[j+1][i]) {
                 cont++;
                 if(max<cont) max = cont;
             }
             else {
                 cont = 1;
             }
        }
        return max;
    }
}

void swap(char *a, char*b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int N, Max = 0;
    int tmp;
    string *Board;
    cin >> N;
    Board = new string[N];
    for (int i = 0; i < N; i++)
    {
        cin >> Board[i];
    }
    
    for (int i = 0; i < N; i++)
    {
        for(int j=0; j< N; j++) {
            if(j!=N-1){
                if(Board[i][j] != Board[i][j+1]) { // 끝부분 생각
                swap( &Board[i][j], &Board[i][j+1]);
                for(int k = 0; k<N; k++) {
                    tmp = lineMax(Board, k, true);
                    if(tmp>Max) Max = tmp;
                    tmp = lineMax(Board, k, false);
                    if(tmp>Max) Max = tmp;
                }
                swap( &Board[i][j], &Board[i][j+1]);
            }
            }
            if(i!=N-1){
                if(Board[i][j] != Board[i+1][j]) { // 끝부분 생각
                swap( &Board[i][j], &Board[i+1][j]);
                for(int k = 0; k<N; k++) {
                    tmp = lineMax(Board, k, true);
                    if(tmp>Max) Max = tmp;
                    tmp = lineMax(Board, k, false);
                    if(tmp>Max) Max = tmp;
                }
                swap( &Board[i][j], &Board[i+1][j]);
            }
            }
            
        }
    }

    cout << Max;
}
