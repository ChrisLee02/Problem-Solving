/*
무한 수열 A는 다음과 같다.
A_0 = 1
A_i = A⌊i/P⌋ + A⌊i/Q⌋ (i ≥ 1)
N, P와 Q가 주어질 때, AN을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 3개의 정수 N, P, Q가 주어진다.
0 ≤ N ≤ 10^12    2 ≤ P, Q ≤ 10^9

출력
첫째 줄에 A_N을 출력한다.
 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

using namespace std;

unordered_map<long long, long long> A_i{};
long long N, P, Q;

long long fun(long long i) {
    if(A_i.find(i) == A_i.end()) {
        A_i[i] = fun(i/P) + fun(i/Q);
    }

    return A_i[i];
}

int main()
{
    FastIO;
    A_i[0] = 1;

    cin >> N >> P >> Q;

    cout << fun(N);


}