/*
입력 데이터는 표준 입력을 사용한다. 입력은 1개의 테스트 데이터로 구성된다. 입력의 첫 번째 줄에는 건물의 개수 N(1 ≤ N ≤ 1,000)과
 도로의 개수 M(1 ≤ M ≤ N(N-1)/2) 이 주어진다. 입력의 두 번째 줄부터 M+1개의 줄에는 A, B(1 ≤ A, B ≤ N), C 가 주어진다.
 이는 A와 B 건물에 연결된 도로가 있다는 뜻이며, C는 0(오르막길) 또는 1(내리막길)의 값을 가진다. 같은 경로 상에 2개 이상의 도로가 주어지는 경우는 없으며,
 입구는 항상 1번 건물과 연결되어 있다. 입구와 1번 도로 간의 연결 관계는 항상 2번째 줄에 주어진다. 입구에서 모든 건물로 갈 수 있음이 보장된다.

출력
출력은 표준 출력을 사용한다. 입력받은 데이터에 대해, 주어진 조건을 만족하는 최악의 경로에서의 피로도와 최적의 경로 간 피로도의 차이를 출력한다.
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
    while(cnt < N-2) {
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
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        parent[i] = -1;
    }
    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        PQ.push({tmp3, tmp1, tmp2});
    }

    kruskal();

}