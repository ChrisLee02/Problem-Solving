/*
이 문제에서 다루는 2048 게임은 보드의 크기가 N×N 이다. 보드의 크기와 보드판의 블록 상태가 주어졌을 때,
 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 보드의 크기 N (1 ≤ N ≤ 20)이 주어진다. 둘째 줄부터 N개의 줄에는 게임판의 초기 상태가 주어진다.
 0은 빈 칸을 나타내며, 이외의 값은 모두 블록을 나타낸다. 블록에 쓰여 있는 수는 2보다 크거나 같고, 1024보다 작거나 같은 2의 제곱꼴이다. 블록은 적어도 하나 주어진다.

출력
최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록을 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;
int Board[20][20];
int Board_copied[20][20];
int Locked[20][20];
int cur;
int Move[5];
int N;
int Max = 0;
string moveName[5] = {"UP", "DOWN", "RIGHT", "LEFT"};

void process(int Move_direction) {
    //못움직인 경우의 예외처리 -> 0으로 덮어씌워지는 문제 발생
    //이동 시에 루트 순서에 유의해야함.
    switch (Move_direction) {
        case 0: // 위로
            for (int i = 1; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    int tmp = 1;
                    while (i - tmp >= 0 && Board_copied[i - tmp][j] == 0) {
                        tmp++;
                    }

                    if (i - tmp == -1) {
                        Board_copied[i - tmp + 1][j] = Board_copied[i][j];
                        if(tmp!=1) Board_copied[i][j] = 0;
                    } else {
                        if (Board_copied[i - tmp][j] == Board_copied[i][j] && !Locked[i - tmp][j]) {
                            Board_copied[i - tmp][j] = Board_copied[i - tmp][j] << 1;
                            Board_copied[i][j] = 0;
                            Locked[i - tmp][j] = 1;
                        } else {
                            Board_copied[i - tmp + 1][j] = Board_copied[i][j];
                            if(tmp!=1) Board_copied[i][j] = 0;
                        }
                    }

                }
            }
            break;
        case 1: // 아래로
            for (int i = N-2; i >= 0; --i) {
                for (int j = 0; j < N; ++j) {
                    int tmp = 1;
                    while (i + tmp < N && Board_copied[i + tmp][j] == 0) {
                        tmp++;
                    }

                    if (i + tmp == N) {
                        Board_copied[i + tmp - 1][j] = Board_copied[i][j];
                        if(tmp!=1) Board_copied[i][j] = 0;
                    } else {
                        if (Board_copied[i + tmp][j] == Board_copied[i][j] && !Locked[i + tmp][j]) {
                            Board_copied[i + tmp][j] = Board_copied[i + tmp][j] << 1;
                            Board_copied[i][j] = 0;
                            Locked[i + tmp][j] = 1;
                        } else {
                            Board_copied[i + tmp - 1][j] = Board_copied[i][j];
                            if(tmp!=1) Board_copied[i][j] = 0;
                        }
                    }

                }
            }
            break;
        case 2: // ->
            for (int i = 0; i < N; ++i) {
                for (int j = N-2; j >=0; --j) {
                    int tmp = 1;
                    while (j + tmp < N && Board_copied[i][j + tmp] == 0) {
                        tmp++;
                    }

                    if (j + tmp == N) {
                        Board_copied[i][j + tmp - 1] = Board_copied[i][j];
                        if(tmp!=1) Board_copied[i][j] = 0;
                    } else {
                        if (Board_copied[i][j + tmp] == Board_copied[i][j] && !Locked[i][j + tmp]) {
                            Board_copied[i][j + tmp] = Board_copied[i][j + tmp] << 1;
                            Board_copied[i][j] = 0;
                            Locked[i][j + tmp] = 1;
                        } else {
                            Board_copied[i][j + tmp - 1] = Board_copied[i][j];
                            if(tmp!=1) Board_copied[i][j] = 0;
                        }
                    }
                }
            }
            break;
        case 3: // <-
            for (int i = 0; i < N; ++i) {
                for (int j = 1; j < N; ++j) {
                    int tmp = 1;
                    while (j - tmp >= 0 && Board_copied[i][j - tmp] == 0) {
                        tmp++;
                    }

                    if (j - tmp == -1) {
                        Board_copied[i][j - tmp + 1] = Board_copied[i][j];
                        if(tmp!=1) Board_copied[i][j] = 0;
                    } else {
                        if (Board_copied[i][j - tmp] == Board_copied[i][j] && !Locked[i][j - tmp]) {
                            Board_copied[i][j - tmp] = Board_copied[i][j - tmp] << 1;
                            Board_copied[i][j] = 0;
                            Locked[i][j - tmp] = 1;
                        } else {
                            Board_copied[i][j - tmp + 1] = Board_copied[i][j];
                            if(tmp!=1) Board_copied[i][j] = 0;
                        }
                    }
                }
            }
            break;
    }
}

void fun() {
    if (cur == 5) {
        /*cout << "========" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << moveName[Move[i]] << " ";
        }*/

        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                Board_copied[j][k] = Board[j][k];
            }
        }
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    Locked[j][k] = 0;
                }
            }

            process(Move[i]);

        }
        /*cout << endl;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
            cout<<Board_copied[i][j] << " ";
            }
            cout << endl;
        }*/
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (Board_copied[i][j] > Max) {
                    Max = Board_copied[i][j];
                }
            }
        }
        return;
    }

    for (int i = 0; i < 4; ++i) {
        Move[cur] = i;
        cur++;
        fun();
        cur--;
    }

}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> Board[i][j];
        }
    }
    cur = 0;
    fun();
    cout << Max;

}
