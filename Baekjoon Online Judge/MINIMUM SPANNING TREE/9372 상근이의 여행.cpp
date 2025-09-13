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

int N, M;

vector<pii > adj[100001];
int parent[100001]; // 유니온 파인드에서는, 루트노드의 parent가 rank가 된다.
bool chk[100001];

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> PQ{};

void prim() {
    int ans = 0;
    int cnt_edge = 0;
    chk[1] = true;
    for (pii tmp: adj[1]) {
        PQ.emplace(tmp.second, 1, tmp.first); // 추가하는 노드를 앞쪽으로 보낸다.
    }
    while (cnt_edge != N - 1) {
        auto [cost, a, b] = PQ.top(); PQ.pop();
        if (chk[b]) continue; //기존에 추가된 노드가 무조건 앞이므로 b만 체크하면 됨.

        chk[b] = true;
        cnt_edge++;
        ans += cost;
        for(pii next: adj[b]) {
            if(chk[next.first]) continue;
            PQ.emplace(next.second, b, next.first); // 추가하는 노드를 앞쪽으로 보낸다.
        }
    }

    cout << ans;

}

int find(int x) {
    if(parent[x] < 0) return x;

    parent[x] = find(parent[x]); // 경로 압축에 해당하는 파트
    return parent[x];
}

void union_node(int a, int b) {
    a = find(a);
    b = find(b);
    if(parent[a] == parent[b]) {
        parent[a]--;
    }

    if(parent[a] < parent[b]) { // a가 b보다 깊은 트리면, b를 a에 붙인다.
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}



void kruskal() {
    int cnt = 0;
    int ans = 0;
    while(cnt < N-1) {
        auto [cost, a, b] = PQ.top(); PQ.pop();
        if(find(a) == find(b)) continue;

        cnt++;
        ans+=cost;
        union_node(a, b);
    }

    cout << ans;
}

int main() {
    FastIO;
    int T; cin >> T;
    while(T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; ++i) {
            parent[i] = -1;
        }
        for (int i = 0; i < M; ++i) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;

        }
        cout << N-1 << endl;
    }


}