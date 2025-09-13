/*
길이가 N인 수열이 주어질 때, 수열에서 연속한 1개 이상의 수를 뽑았을 때 같은 수가 여러 번 등장하지 않는 경우의 수를 구하는 프로그램을 작성하여라.

입력
첫 번째 줄에는 수열의 길이 N이 주어진다. (1 ≤ N ≤ 100,000)
두 번째 줄에는 수열을 나타내는 N개의 정수가 주어진다. 수열에 나타나는 수는 모두 1 이상 100,000 이하이다.

출력
조건을 만족하는 경우의 수를 출력한다.
*/

#include <bits/stdc++.h>

using namespace std;

long long one_to_n(int n) {
    auto tmp = (long long) n;
    return tmp*(tmp+1)/2;
}

int num_to_index[100001]; // 0은 부분수열에 존재하지 않는 것.
int N;
int seq[100001];


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> seq[i];
    }
    long long ans = 0;
    int i = 1;
    int j = 1;
    num_to_index[seq[j]] = j;
    while (j < N) {
        j++;
        if( num_to_index[seq[j]] != 0 ) {
            int next_i = num_to_index[seq[j]] + 1;
            for (int k = i; k <= num_to_index[seq[j]]; ++k) {
                ans += (j-k);
                //cout << ans << endl;
                num_to_index[seq[k]] = 0;
            }
            i = next_i;
        }
        num_to_index[seq[j]] = j;
    }

    ans += one_to_n(j-i+1);

    cout << ans;

}