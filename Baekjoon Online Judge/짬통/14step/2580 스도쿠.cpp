#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isAble(int dot, int **Board, int a, int b) { // dot = 해당 칸의 값, a,b는 좌표
    int i,j;
    int k = a - a%3;
    int l = b - b%3;
    for (i = 0; i<9; i++) {
        if(i==b) continue; 
        if(dot == Board[a][i]) return false;
    }

    for (i = 0; i<9; i++) {
        if(i==a) continue;
        if(dot == Board[i][b]) return false;
    }

    for(i = k; i < k+3; i++) {
        for(j = l; j < l+3; j++) {

            if(i==a && j==b) continue;
            if(dot == Board[i][j]) return false;

        }
    }
    return true;
}

void sudoku(int **Board, vector<pair<int,int>> zeroDots) { 
    // row랑 column은 간단함. 점이 속한 구획을 따지는 로직은? -> 1차원 배열로 펴서 find함수로 판별
    // 1차원 배열로 피지말고, (a,b)에 대해 a%3, b%3을 따지면 될 듯.
    // 각 pair에 대해서 순회, 그리고 pair에 대해서는 1~9의 숫자로 순회
    // 백을 하는 과정은 해당 dot의 값을 0으로 만든 뒤, dot index--로 백을 하면 될 듯, 그 이전 dot의 값++한 뒤 다시 탐색
    // 1~9까지 해봤는데 안된다?
    // 한 칸이 빈걸 먼저 체크하면 성능을 개선할 수 있겠다.

    int dotIndex = 0;
    int i = 1;
    while(dotIndex < zeroDots.size()) {
        for(; i<=9; i++) {
            if( isAble(i, Board, zeroDots[dotIndex].first, zeroDots[dotIndex].second) ) {
                Board[zeroDots[dotIndex].first][zeroDots[dotIndex].second] = i;
                //cout << dotIndex << "th dot:" << endl;
                i=0;
                dotIndex++;
                if(dotIndex==zeroDots.size()) break;
                // for (int i = 0; i < 9; i++)
                // {
                //     for (int j = 0; j < 9; j++)
                //     {
                //         if(zeroDots[dotIndex].first == i && j  == zeroDots[dotIndex].second) {
                //             cout << "    " << Board[i][j] << "    ";
                //         }
                //         else cout << Board[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                
                
            }
        }
        if(dotIndex==zeroDots.size()) break; // 인덱싱 문제였네 씨팔
        if(i>9) {
            Board[zeroDots[dotIndex].first][zeroDots[dotIndex].second] = 0;
            dotIndex--;
            i = Board[zeroDots[dotIndex].first][zeroDots[dotIndex].second] + 1;
        }
    }
}



int main(void)
{
    int N;
    int tmp;
    //cin >> N;
    N=9;
    int **Board;
    vector<pair<int,int>> zeroDots;
    Board = new int*[N];
    for(int j = 0; j < N; j++) {
        Board[j] = new int[N];
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> tmp;
            if(tmp == 0) {
                zeroDots.push_back(make_pair(i,j));
            }
            Board[i][j] = tmp;
        }
    }
    // for(int i = 0; i < zeroDots.size(); i++) {
    //     cout << zeroDots[i].first << " " << zeroDots[i].second << endl;
    // }
    sudoku(Board, zeroDots);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << Board[i][j] << " ";
        }
        cout << endl;
    }

}