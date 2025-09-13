/*
상근이는 자신의 결혼식에 학교 동기 중 자신의 친구와 친구의 친구를 초대하기로 했다. 상근이의 동기는 모두 N명이고,
 이 학생들의 학번은 모두 1부터 N까지이다. 상근이의 학번은 1이다.
상근이는 동기들의 친구 관계를 모두 조사한 리스트를 가지고 있다. 이 리스트를 바탕으로 결혼식에 초대할 사람의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이의 동기의 수 n (2 ≤ n ≤ 500)이 주어진다. 둘째 줄에는 리스트의 길이 m (1 ≤ m ≤ 10000)이 주어진다.
 다음 줄부터 m개 줄에는 친구 관계 ai bi가 주어진다. (1 ≤ ai < bi ≤ n) ai와 bi가 친구라는 뜻이며, bi와 ai도 친구관계이다.

출력
첫째 줄에 상근이의 결혼식에 초대하는 동기의 수를 출력한다.
 */

#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<int> adj[501];
bool Visit[501];
int Dist[501];

int main() {
    FastIO;
    int N, M;
    cin >> N >> M;
    for (int j = 0; j < M; ++j) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }

    queue<int> Q{};
    Q.push(1);
    Visit[1] = true;
    Dist[1] = 0;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (int i: adj[cur]) {
            if(Visit[i]) continue;

            Q.push(i);
            Visit[i] = true;
            Dist[i] = Dist[cur] + 1;
        }

    }
    int ans = 0;
    for (int i = 2; i <= N; ++i) {
        if(Dist[i] == 0 || Dist[i] > 2 ) continue;
        ans++;
    }
    cout << ans;

}