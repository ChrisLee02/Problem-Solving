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
//연결요소를 찾기 위해 BFS를 실시한다. 이때 간선에 대한 for문에서 visited인 놈을 방문하는 간선이 존재하면 해당 연결요소는 트리가 아니다.


int N, M;

vector<pii> adj[1001];

pii parent[1001];

void make_tree(int root) {
    for (int i = 1; i <= N; ++i) {
        parent[i] = pii(0,0);
    }
    queue<int> Q{};
    Q.push(root);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (pii next: adj[cur]) {
            if (parent[cur].first == next.first) continue;
            Q.push(next.first);
            parent[next.first] = pii(cur, next.second);
        }
    }
}

int distance(int A, int B) {
    make_tree(A);
    int node = B;
    int ans = 0;
    while(node != A) {
        //cout <<"node: " << node << endl;
        ans += parent[node].second;
        node = parent[node].first;
    }
    return ans;
}


int main() {
    FastIO;
    cin >> N >> M;
    for (int i = 0; i < N-1; ++i) {
        int tmp1, tmp2, tmp3; cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp1].emplace_back(tmp2, tmp3);
        adj[tmp2].emplace_back(tmp1,tmp3);
    }
    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        cout << distance(tmp1, tmp2) << endl;
    }
}