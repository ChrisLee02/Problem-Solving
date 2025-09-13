/*
길고 길었던 겨울이 끝나고 BOJ 마을에도 봄이 찾아왔다. BOJ 마을에서는 꽃을 마을 소유의 정원에 피우려고 한다.
 정원은 땅과 호수로 이루어져 있고 2차원 격자판 모양이다.
인건비 절감을 위해 BOJ 마을에서는 직접 사람이 씨앗을 심는 대신 초록색 배양액과 빨간색 배양액을 땅에 적절하게 뿌려서 꽃을 피울 것이다.
 이 때 배양액을 뿌릴 수 있는 땅은 미리 정해져있다.
배양액은 매 초마다 이전에 배양액이 도달한 적이 없는 인접한 땅으로 퍼져간다.
아래는 초록색 배양액 2개를 뿌렸을 때의 예시이다. 하얀색 칸은 배양액을 뿌릴 수 없는 땅을, 황토색 칸은 배양액을 뿌릴 수 있는 땅을, 하늘색 칸은 호수를 의미한다.
초록색 배양액과 빨간색 배양액이 동일한 시간에 도달한 땅에서는 두 배양액이 합쳐져서 꽃이 피어난다. 꽃이 피어난 땅에서는 배양액이 사라지기 때문에
 더 이상 인접한 땅으로 배양액을 퍼트리지 않는다.
배양액은 봄이 지나면 사용할 수 없게 되므로 주어진 모든 배양액을 남김없이 사용해야 한다. 예를 들어 초록색 배양액 2개와 빨간색 배양액 2개가 주어졌는데
 초록색 배양액 1개를 땅에 뿌리지 않고, 초록색 배양액 1개와 빨간색 배양액 2개만을 사용하는 것은 불가능하다.
또한 모든 배양액은 서로 다른 곳에 뿌려져야 한다.
정원과 두 배양액의 개수가 주어져있을 때 피울 수 있는 꽃의 최대 개수를 구해보자.

입력
첫째 줄에 정원의 행의 개수와 열의 개수를 나타내는 N(2 ≤ N ≤ 50)과 M(2 ≤ M ≤ 50),
 그리고 초록색 배양액의 개수 G(1 ≤ G ≤ 5)와 빨간색 배양액의 개수 R(1 ≤ R ≤ 5)이 한 칸의 빈칸을 사이에 두고 주어진다.
그 다음 N개의 줄에는 각 줄마다 정원의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다. 각 칸에 들어가는 값은 0, 1, 2이다.
 0은 호수, 1은 배양액을 뿌릴 수 없는 땅, 2는 배양액을 뿌릴 수 있는 땅을 의미한다.
 (-1을 꽃으로 두고 코딩하자.)

배양액을 뿌릴 수 있는 땅의 수는 R+G개 이상이고 10개 이하이다.

출력
첫째 줄에 피울 수 있는 꽃의 최대 개수를 출력한다.
 */



//




#include <bits/stdc++.h>

#define Pair pair<int,int>
#define X first
#define Y second
#define INF 9999999
using namespace std;


int Board[51][51];
int Board_copied[51][51];
int Dist_R[51][51];
int Dist_G[51][51];
int spot_X[2501];
int spot_Y[2501];
int N, M, G, R;
int cur;
int cnt_R;
int cnt_G;
int cnt;
int Max = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> List_X{};
vector<int> List_Y{};
vector<int> List_RG{};

void process() {
    //최단거리가 같은 지점에서 꽃이 생김.
    int flowers = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; ++j) {
            Dist_G[i][j] = INF;
            Dist_R[i][j] = INF;
        }
    }

    queue<Pair > Q{};
    queue<int> Q_tracking{};

    for (int i = 0; i < List_X.size(); ++i) {
        Q.emplace(List_X[i], List_Y[i]);
        Q_tracking.push(List_RG[i]);
        if(List_RG[i] == 'R'){
            Dist_R[List_X[i]][List_Y[i]] = 0;
        }
        else {
            Dist_G[List_X[i]][List_Y[i]] = 0;
        }
    }

    while (!Q.empty()) {
        Pair current = Q.front();
        int cur_tracking = Q_tracking.front();
        Q.pop();
        Q_tracking.pop();
        if(Dist_R[current.X][current.Y] != INF && Dist_R[current.X][current.Y] == Dist_G[current.X][current.Y] ) continue;
        for (int i = 0; i < 4; i++) {
            int nx = current.X + dx[i];
            int ny = current.Y + dy[i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && Board[nx][ny] != 0) {
                //cout << cur_tracking << " ";
                if(cur_tracking == 'R' && Dist_R[nx][ny] == INF) {
                    //cout<< "R"<<" ";
                    Dist_R[nx][ny] = Dist_R[current.X][current.Y] + 1;
                    if(Dist_G[nx][ny] == INF) {
                        Q.emplace(nx, ny);
                        Q_tracking.push('R');
                    }
                }

                if(cur_tracking == 'G' && Dist_G[nx][ny] == INF) {
                  //  cout<< "G"<<" ";
                    Dist_G[nx][ny] = Dist_G[current.X][current.Y] + 1;
                    if(Dist_R[nx][ny] == INF) {
                        Q.emplace(nx, ny);
                        Q_tracking.push('G');
                    }
                }


            }
        }

    }


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; ++j) {
            if (Dist_G[i][j] != INF && Dist_G[i][j] == Dist_R[i][j]) {
                flowers++;
            }
        }
    }


    if (Max < flowers) {
        /*for (int i = 0; i < List_X.size(); ++i) {
            cout << List_X[i] << " " << List_Y[i] << " " << List_RG[i] << endl;
        }
        cout << endl;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; ++j) {
                cout << Dist_G[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; ++j) {
                cout << Dist_R[i][j] << " ";
            }
            cout << endl;
        }
        cout<<endl;*/

        Max = flowers;
    }


}


void fun() {
    if (List_X.size() == R + G) {
        process();
        return;
    }
    if (cur > cnt) {
        return;
    }

    cur++;
    fun();
    cur--;


    if (cnt_R < R) {
        List_X.push_back(spot_X[cur]);
        List_Y.push_back(spot_Y[cur]);
        List_RG.push_back('R');
        cur++;
        cnt_R++;
        fun();
        cur--;
        cnt_R--;
        List_X.pop_back();
        List_Y.pop_back();
        List_RG.pop_back();
    }
    if (cnt_G < G) {
        List_X.push_back(spot_X[cur]);
        List_Y.push_back(spot_Y[cur]);
        List_RG.push_back('G');
        cnt_G++;
        cur++;
        fun();
        cur--;
        cnt_G--;
        List_X.pop_back();
        List_Y.pop_back();
        List_RG.pop_back();
    }


}

int main() {
    cin >> N >> M >> G >> R;
    cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; ++j) {
            cin >> Board[i][j];
            if (Board[i][j] == 2) {
                cnt++;
                spot_X[cnt] = i;
                spot_Y[cnt] = j;
            }
        }
    }
    cur = 1;
    cnt_G = 0;
    cnt_R = 0;
    fun();
    cout << Max;

}