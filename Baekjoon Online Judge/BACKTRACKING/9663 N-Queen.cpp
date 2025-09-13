/*
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
 */


#include <bits/stdc++.h>

#define Pair pair<int,int>
#define X first
#define Y second
using namespace std;

int sum = 0;

void NQueen(vector<Pair > &queens, int N, int a) {

    /*cout << "===========" << endl;
    for (Pair queen: queens) {
        cout << queen.X << " " << queen.Y << endl;
    }
    cout << "===========" << endl;*/
    if (queens.size() == N) {
        sum++;
        // cout << sum;
        return;
    }

    //어차피 무조건 한줄에 한 놈씩만 와야댐

    int i = a + 1;
    for (int j = 1; j <= N; ++j) {
        bool success = true;
        for (Pair queen: queens) {
            if (queen.Y == j || queen.X - i == queen.Y - j || i - queen.X == queen.Y - j) {
                success = false;
                break;
            }
        }
        if (success) {
            queens.emplace_back(i, j);
            NQueen(queens, N, i);
            queens.pop_back();
        }

    }


}

int main() {
    int N;
    cin >> N;
    vector<Pair > queens{};
    NQueen(queens, N, 0);
    cout << sum;
}