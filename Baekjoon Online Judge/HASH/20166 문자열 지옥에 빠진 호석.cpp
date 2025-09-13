/*
첫번째 줄에 격자의 크기 N, M과 신이 좋아하는 문자열의 개수 K 가 주어진다.
다음에 N개의 줄에 걸쳐서 M개의 알파벳 소문자가 공백없이 주어진다. 여기서의 첫 번째 줄은 1행의 정보이며, N 번째 줄은 N행의 정보이다.
이어서 K개의 줄에 걸쳐서 신이 좋아하는 문자열이 주어진다. 모두 알파벳 소문자로 이루어져 있다.

출력
K개의 줄에 걸쳐서, 신이 좋아하는 문자열을 만들 수 있는 경우의 수를 순서대로 출력한다.

제한
3 ≤ N, M ≤ 10, N과 M은 자연수이다. 1 ≤ K ≤ 1,000, K는 자연수이다. 1 ≤ 신이 좋아하는 문자열의 길이 ≤ 5
신이 좋아하는 문자열은 중복될 수도 있다.
 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

using namespace std;

// 깊이 5짜리의 중복을 허용한 깊이우선탐색을 시행한다. map에 저장하면 될듯

int N, M, K;
char char_map[11][11];

unordered_map<string, int> str2count{};

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
void fun(string str, int x, int y) {
    str = str + char_map[x][y];

    str2count[str]++;
    if(str.size() == 5) {
        return;
    }
    else {
        for (int i = 0; i < 8; ++i) {
            int nx = (x + dx[i] + N) % N;
            int ny = (y + dy[i] + M) % M;
            fun(str, nx, ny);
        }
    }
}

int main()
{
    FastIO;
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> char_map[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            fun("", i, j);
        }
    }

    for (int i = 0; i < K; ++i) {
        string tmp; cin >> tmp;
        cout << str2count[tmp] << endl;
    }
}