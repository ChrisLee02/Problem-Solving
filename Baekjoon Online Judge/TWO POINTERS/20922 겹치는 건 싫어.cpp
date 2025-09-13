/*
https://www.acmicpc.net/problem/20922
 */

#include <bits/stdc++.h>

using namespace std;

int N, K;

int seq[200001]; // 1 to N
int num_to_index[100001]; // 0은 존재하지 않는 것을 의미
int num_to_count[100001];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> seq[i];
    }
    int i = 1;
    int j = 1;
    num_to_count[seq[i]] = 1;
    int ans = 1;
    while(j < N) {
        j++;

        if(num_to_count[seq[j]] == K) {
            ans = max(ans, j-i);
            int find_seq_j = find(seq + i, seq + 1 + N, seq[j]) - seq;

            for (int k = i; k < find_seq_j; ++k) {
                num_to_count[seq[k]]--;
            }

            i = find_seq_j + 1;

        } else {
            num_to_count[seq[j]]++;
            ans = max(ans, j-i+1);
        }

    }

    cout << ans;

}