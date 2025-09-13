/*

 */

#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

using namespace std;

int N, M, K;
int Visit[101011];
int Dist[101011];
vector<int> adj[101011];

// 각각의 하이퍼튜브를 정점으로 생각한다? 미쳤네 진짜,,
void BFS(int start) {
    queue<int> Q{};
    Q.push(start);
    Visit[start] = true;
    Dist[start] = 1;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int next: adj[cur]) {
            if (!Visit[next]) {
                Q.push(next);
                Visit[next] = 1;
                if(cur<=N) Dist[next] = Dist[cur] + 1;
                else Dist[next] = Dist[cur];
            }
        }

    }


}

int main() {
    FastIO;
    cin >> N >> K >> M;
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j < K; ++j) {
            int tmp;
            cin >> tmp;
            adj[N+i].push_back(tmp);
            adj[tmp].push_back(N+i);
        }
    }

    BFS(1);

    if (Visit[N]) cout << Dist[N];
    else cout << -1;

}