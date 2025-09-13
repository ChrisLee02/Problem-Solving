/*
이 도시에 있는 치킨집은 모두 같은 프랜차이즈이다. 프렌차이즈 본사에서는 수익을 증가시키기 위해 일부 치킨집을 폐업시키려고 한다.
 오랜 연구 끝에 이 도시에서 가장 수익을 많이 낼 수 있는  치킨집의 개수는 최대 M개라는 사실을 알아내었다.

도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업시켜야 한다. 어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)이 주어진다.

둘째 줄부터 N개의 줄에는 도시의 정보가 주어진다.

도시의 정보는 0, 1, 2로 이루어져 있고, 0은 빈 칸, 1은 집, 2는 치킨집을 의미한다. 집의 개수는 2N개를 넘지 않으며, 적어도 1개는 존재한다.
 치킨집의 개수는 M보다 크거나 같고, 13보다 작거나 같다.

출력
첫째 줄에 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때, 도시의 치킨 거리의 최솟값을 출력한다.
 */

#include <bits/stdc++.h>

#define Pair pair<int,int>
#define X first
#define Y second
using namespace std;

int Board[51][51];
int Board_copied[51][51];
int chicken_X[14];
int chicken_Y[14];
int chicken_isPicked[14];
int home_X[101];
int home_Y[101];

int chosen_chicken_X[14];
int chosen_chicken_Y[14];

int chicken_cnt;
int home_cnt;
int Min = 99999999;
int N, M, cur, chicken_index;


void process() {
    int sum = 0;
    /*for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            Board_copied[i][j] = Board[i][j];
            if (Board_copied[i][j] == 1) Board_copied[i][j] = 0;
        }
    }
    for (int i = 1; i <= M; ++i) {
        Board_copied[chosen_chicken_X[i]][chicken_Y[i]] = 1;
    }*/
    for (int i = 1; i <= home_cnt; ++i) {
        int Min_chicken_Dist = 99999999;

        for (int j = 1; j <= M; ++j) {
            if (Min_chicken_Dist > (abs(home_X[i] - chosen_chicken_X[j]) + abs(home_Y[i] - chosen_chicken_Y[j])))
                Min_chicken_Dist = abs(home_X[i] - chosen_chicken_X[j]) + abs(home_Y[i] - chosen_chicken_Y[j]);
        }

        sum = sum + Min_chicken_Dist;
    }

    if (sum < Min) Min = sum;


}

void fun() {
    if(cur > M) {
        /*for (int i = 1; i <= M; ++i) {
            cout << chosen_chicken_X[i] << " " << chosen_chicken_Y[i] << endl;
        }
        cout << endl;*/
        process();
        return;
    }

    if(chicken_index>chicken_cnt) return;

    chicken_index++;
    fun();
    chicken_index--;

    chosen_chicken_X[cur] = chicken_X[chicken_index];
    chosen_chicken_Y[cur] = chicken_Y[chicken_index];
    cur++;
    chicken_index++;
    fun();
    cur--;
    chicken_index--;


}

int main() {
    cin >> N >> M;
    chicken_cnt = 0;
    home_cnt = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> Board[i][j];

            if (Board[i][j] == 1) {
                home_cnt++;
                home_X[home_cnt] = i;
                home_Y[home_cnt] = j;
            }

            if (Board[i][j] == 2) {
                chicken_cnt++;
                chicken_X[chicken_cnt] = i;
                chicken_Y[chicken_cnt] = j;
            }
        }
    }

    cur = 1;
    chicken_index = 1;
    fun();
    cout << Min;


}
