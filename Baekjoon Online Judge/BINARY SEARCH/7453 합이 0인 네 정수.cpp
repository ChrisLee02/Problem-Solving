/*
정수로 이루어진 크기가 같은 배열 A, B, C, D가 있다.

A[a], B[b], C[c], D[d]의 합이 0인 (a, b, c, d) 쌍의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 배열의 크기 n (1 ≤ n ≤ 4000)이 주어진다. 다음 n개 줄에는 A, B, C, D에 포함되는 정수가 공백으로 구분되어져서 주어진다.
 배열에 들어있는 정수의 절댓값은 최대 2^28이다.

출력
합이 0이 되는 쌍의 개수를 출력한다.
 */

#include <bits/stdc++.h>

using namespace std;

int A[4001];
int B[4001];
int C[4001];
int D[4001];
int N;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    vector<int> A_plus_B{};
    vector<int> C_plus_D{};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A_plus_B.push_back(A[i] + B[j]);
            C_plus_D.push_back(C[i] + D[j]);
        }
    }
    std::sort(A_plus_B.begin(), A_plus_B.end());
    std::sort(C_plus_D.begin(), C_plus_D.end());
    long long ans = 0;
    for(int i: A_plus_B) {
        int target = -1*i;
        ans += std::upper_bound(C_plus_D.begin(), C_plus_D.end(),target) -
                std::lower_bound(C_plus_D.begin(), C_plus_D.end(), target);
    }
    cout << ans;

}