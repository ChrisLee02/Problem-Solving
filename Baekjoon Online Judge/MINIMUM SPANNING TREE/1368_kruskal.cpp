/*

 */

#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

// 가상의 수원인 노드 X를 두고, 나머지 노드를 전부 연결 비용으로 취급해준다.

using namespace std;

int N, M;

vector<pii > adj[302];
int parent[302]; // 유니온 파인드에서는, 루트노드의 parent가 rank가 된다.
bool chk[302];

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> PQ{};

int find(int x) {
    if (parent[x] < 0) return x;

    parent[x] = find(parent[x]); // 경로 압축에 해당하는 파트
    return parent[x];
}

void union_node(int a, int b) {
    a = find(a);
    b = find(b);
    if (parent[a] == parent[b]) {
        parent[a]--;
    }

    if (parent[a] < parent[b]) { // a가 b보다 깊은 트리면, b를 a에 붙인다.
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}


void kruskal() {
    int cnt = 0;
    int ans = 0;
    while (cnt < N) {
        auto [cost, a, b] = PQ.top();
        PQ.pop();
        if (find(a) == find(b)) continue;

        cnt++;
        ans += cost;
        union_node(a, b);
    }

    cout << ans;
}

int main() {
    FastIO;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        parent[i] = -1;
        int tmp; cin >> tmp;
        PQ.push({tmp, i, N+1});
    }
    parent[N+1] = -1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int tmp; cin >> tmp;
            if(i>=j) continue;
            PQ.push({tmp, i, j});
        }
    }

    kruskal();

}