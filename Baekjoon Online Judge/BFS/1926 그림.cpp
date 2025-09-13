/*
어떤 큰 도화지에 그림이 그려져 있을 때, 그 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라.
 단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자. 가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다.
 그림의 넓이란 그림에 포함된 1의 개수이다.

입력
첫째 줄에 도화지의 세로 크기 n(1 ≤ n ≤ 500)과 가로 크기 m(1 ≤ m ≤ 500)이 차례로 주어진다.
 두 번째 줄부터 n+1 줄 까지 그림의 정보가 주어진다. (단 그림의 정보는 0과 1이 공백을 두고 주어지며, 0은 색칠이 안된 부분, 1은 색칠이 된 부분을 의미한다)

출력
첫째 줄에는 그림의 개수, 둘째 줄에는 그 중 가장 넓은 그림의 넓이를 출력하여라. 단, 그림이 하나도 없는 경우에는 가장 넓은 그림의 넓이는 0이다.
 */


#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int Board[1000][1000];
int Visit[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> scores;
    scores.push_back(0);
    int N, M, height, tmp;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> tmp;
            Board[i][j] = tmp;
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if(Board[i][j] == 1 && Visit[i][j] == 0 ) {
                int area = 0;
                queue<pair<int,int>> Q;
                Q.push(pair<int,int>(i,j));
                Visit[i][j] = 1;
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front();
                    Q.pop();
                    area++;
                    for(int k = 0; k<4; k++) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];

                        if(Board[nx][ny] == 1 && Visit[nx][ny] == 0) {
                            Q.push(pair<int,int>(nx, ny));
                            Visit[nx][ny] = 1;
                        }

                    }
                }
                scores.push_back(area);
            }

        }
    }



    cout << scores.size() - 1 << endl << *std::max_element(scores.begin(), scores.end());
}