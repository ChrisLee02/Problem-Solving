/*
서양 장기인 체스에는 대각선 방향으로 움직일 수 있는 비숍(bishop)이 있다.
 < 그림 1 >과 같은 정사각형 체스판 위에 B라고 표시된 곳에 비숍이 있을 때 비숍은 대각선 방향으로 움직여 O로 표시된 칸에 있는 다른 말을 잡을 수 있다.

그런데 체스판 위에는 비숍이 놓일 수 없는 곳이 있다. < 그림 2 >에서 체스판에 색칠된 부분은 비숍이 놓일 수 없다고 하자.
 이와 같은 체스판에 서로가 서로를 잡을 수 없도록 하면서 비숍을 놓는다면 < 그림 3 >과 같이 최대 7개의 비숍을 놓을 수 있다.
 색칠된 부분에는 비숍이 놓일 수 없지만 지나갈 수는 있다.

정사각형 체스판의 한 변에 놓인 칸의 개수를 체스판의 크기라고 한다. 체스판의 크기와 체스판 각 칸에 비숍을 놓을 수 있는지 없는지에 대한 정보가 주어질 때,
 서로가 서로를 잡을 수 없는 위치에 놓을 수 있는 비숍의 최대 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 체스판의 크기가 주어진다. 체스판의 크기는 10이하의 자연수이다. 둘째 줄부터 아래의 예와 같이 체스판의 각 칸에 비숍을 놓을 수 있는지 없는지에
 대한 정보가 체스판 한 줄 단위로 한 줄씩 주어진다. 비숍을 놓을 수 있는 곳에는 1, 비숍을 놓을 수 없는 곳에는 0이 빈칸을 사이에 두고 주어진다.

출력
첫째 줄에 주어진 체스판 위에 놓을 수 있는 비숍의 최대 개수를 출력한다.
 */


//이런 보드류의 문제에선, 어림잡아서 팩토리얼의 연산량임. 그래서 크기 10짜리는 바로 계산불가.
//비숍의 특성 상, 흑 백 으로 보드를 쪼개면 된다. 그러면 5 5 각각 계산하는건 쉽고, 두 개 더해주면 끝.

#include <bits/stdc++.h>

#define Pair pair<int, int>

using namespace std;

int Board[11][11];
int Visit[11][11];
int diag2[100];
int N;
int Max_B = 0;
int Max_W = 0;
int Count;
int cur;

vector<vector<int>> bishop_B_sep_by_diag1{};
vector<vector<int>> bishop_W_sep_by_diag1{};


void fun_B() {
    if(cur > 2*N - 2) {
        if(Count>Max_B) Max_B = Count;
        return;
    }

    cur++;
    fun_B();
    cur--;
    for (int diag2_index: bishop_B_sep_by_diag1[cur]) {
        if(!diag2[diag2_index]) {
            diag2[diag2_index] = 1;
            Count++;
            cur++;
            fun_B();
            Count--;
            cur--;
            diag2[diag2_index] = 0;
        }
    }
}
void fun_W() {
    if(cur > 2*N - 2) {
        if(Count>Max_W) Max_W = Count;
        return;
    }

    cur++;
    fun_W();
    cur--;
    for (int diag2_index: bishop_W_sep_by_diag1[cur]) {
        if(!diag2[diag2_index]) {
            diag2[diag2_index] = 1;
            Count++;
            cur++;
            fun_W();
            Count--;
            cur--;
            diag2[diag2_index] = 0;
        }
    }
}



//대각선 별로 비숍을 집어넣어서 탐색 범위를 좁혀보자
int main() {
    cin >> N;
    for (int i = 0; i <= 2*N-2; ++i) {
        bishop_B_sep_by_diag1.emplace_back();
        bishop_W_sep_by_diag1.emplace_back();
    }

//0~2N-2까지 사용
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> Board[i][j];
            if ((i+j)%2 == 0 && Board[i][j] == 1) {
                bishop_B_sep_by_diag1[i+j-2].push_back(i-j+10);
            }
            if ((i+j)%2 != 0 && Board[i][j] == 1) {
                bishop_W_sep_by_diag1[i+j-2].push_back(i-j+10);
            }

        }
    }
    //1이 놓을 수 있는 곳.
    Count = 0;
    cur = 0;
    fun_B();
    Count = 0;
    cur = 0;
    fun_W();



    cout << Max_B + Max_W;


}