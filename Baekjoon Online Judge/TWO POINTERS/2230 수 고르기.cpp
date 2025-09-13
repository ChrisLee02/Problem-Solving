/*
N개의 정수로 이루어진 수열 A[1], A[2], …, A[N]이 있다. 이 수열에서 두 수를 골랐을 때(같은 수일 수도 있다),
 그 차이가 M 이상이면서 제일 작은 경우를 구하는 프로그램을 작성하시오.

예를 들어 수열이 {1, 2, 3, 4, 5}라고 하자. 만약 M = 3일 경우, 1 4, 1 5, 2 5를 골랐을 때 그 차이가 M 이상이 된다.
 이 중에서 차이가 가장 작은 경우는 1 4나 2 5를 골랐을 때의 3이 된다.

입력
첫째 줄에 두 정수 N, M이 주어진다. 다음 N개의 줄에는 차례로 A[1], A[2], …, A[N]이 주어진다.

출력
첫째 줄에 M 이상이면서 가장 작은 차이를 출력한다. 항상 차이가 M이상인 두 수를 고를 수 있다.

제한
1 ≤ N ≤ 100,000     0 ≤ M ≤ 2,000,000,000    0 ≤ |A[i]| ≤ 1,000,000,000
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> seq{};
int N, M;


void TP_sol() {
    //init i, j
    int i = 0;
    int j = 0;
    int ans = 2100000000;

    while (j < N && i < N ) {
        if (seq[j] - seq[i] >= M) {
            ans = min(ans, seq[j] - seq[i]);
            i++;
        } else j++;
    }
    cout << ans;

}

void BS_sol() {
    int ans = 2100000000;
    for (int i = 0; i < N; ++i) {
        int target = seq[i] + M; // +M만 따져도 충분하다.
        auto p = std::lower_bound(seq.begin() + i, seq.end(), target); // N=1일 수도 있어서, 인덱스 중복 허용하도록 코드 짜야함.
        if (p == seq.end()) {
            break; // 여기부턴 더 안해도 된다.
        } else {
            ans = min(ans, *p - seq[i]);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        seq.push_back(tmp);
    }
    std::sort(seq.begin(), seq.end());

    //BS_sol();
    TP_sol();

}