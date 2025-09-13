/*
M개의 우주가 있고, 각 우주에는 1부터 N까지 번호가 매겨진 행성이 N개 있다. 행성의 크기를 알고 있을때, 균등한 우주의 쌍이 몇 개인지 구해보려고 한다.
 구성이 같은데 순서만 다른 우주의 쌍은 한 번만 센다.

두 우주 A와 B가 있고, 우주 A에 있는 행성의 크기는 A1, A2, ..., AN, 우주 B에 있는 행성의 크기는 B1, B2, ..., BN라고 하자.
 두 우주의 행성 크기가 모든 1 ≤ i, j ≤ N에 대해서 아래와 같은 조건을 만족한다면, 두 우주를 균등하다고 한다.
Ai < Aj → Bi < Bj
Ai = Aj → Bi = Bj
Ai > Aj → Bi > Bj

입력
첫째 줄에 우주의 개수 M과 각 우주에 있는 행성의 개수 N이 주어진다. 둘째 줄부터 M개의 줄에 공백으로 구분된 행성의 크기가 한 줄에 하나씩 1번 우주부터 차례대로 주어진다.

출력
첫째 줄에 균등한 우주의 쌍의 개수를 출력한다.
 */

#include <bits/stdc++.h>
#define Pair pair<int,int>
#define num first
#define size second
using namespace std;


int univ_planet_num_to_size[101][10001]; // [i][j] = ith 우주의 j번 행성의 크기를 저장한다.
int univ_planet_num_sorted[101][10001]; // [i] = ith 우주의 행성 번호들을 크기 순으로 정렬해둔 array
int univ_planet_num_to_rank[101][10001];
int selected_univ;
bool comp_planet(int a, int b) { // 한 우주에서 두 행성의 크기를 비교한다.
    return univ_planet_num_to_size[selected_univ][a] < univ_planet_num_to_size[selected_univ][b];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M, N;
    cin >> M >> N;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> univ_planet_num_to_size[i][j];
            univ_planet_num_sorted[i][j] = j;
        }
        selected_univ = i;
        sort(univ_planet_num_sorted[i], univ_planet_num_sorted[i] + N, comp_planet);
        for (int k = 0; k < N; ++k) {
            univ_planet_num_to_rank[i][k] = (lower_bound(univ_planet_num_sorted[i], univ_planet_num_sorted[i] + N, k, comp_planet)
                    - univ_planet_num_sorted[i]);
        }
    }
    int count = 0;
    for (int i = 0; i < M-1; ++i) {
        for (int j = i+1; j < M; ++j) { // 여기서 M^2 말고 M으로 복잡도를 낮출 방법이 존재할거임.. -> ㄴㄴ,, 아래쪽 루프를 NlogN -> N으로 변경
            bool isSame = true;
            for (int k = 0; k < N; ++k) {
                isSame = isSame && (univ_planet_num_to_rank[i][k] == univ_planet_num_to_rank[j][k]);
            }
            if(isSame) count++;
        }
    }

    cout << count;



}