/*
파일의 첫 번째 줄은 노드의 개수 n(1 ≤ n ≤ 10,000)이다. 둘째 줄부터 n-1개의 줄에 각 간선에 대한 정보가 들어온다. \
 간선에 대한 정보는 세 개의 정수로 이루어져 있다. 첫 번째 정수는 간선이 연결하는 두 노드 중 부모 노드의 번호를 나타내고,
 두 번째 정수는 자식 노드를, 세 번째 정수는 간선의 가중치를 나타낸다. 간선에 대한 정보는 부모 노드의 번호가 작은 것이 먼저 입력되고,
 부모 노드의 번호가 같으면 자식 노드의 번호가 작은 것이 먼저 입력된다. 루트 노드의 번호는 항상 1이라고 가정하며, 간선의 가중치는 100보다 크지 않은 양의 정수이다.

출력
첫째 줄에 트리의 지름을 출력한다.
 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

// N = 10000이라 그냥 N^2으로 모든 순서쌍의 거리값을 구해도 됨.
// int 1억개면 400MB라 안댐,,




using namespace std;

int N;

vector<pii> adj[10001];
int parent[10001];
int DIST[10001];

void BFS(int start) {
    for (int i = 1; i <= N; ++i) {
        DIST[i] = 0;
    }

    queue<int> Q{};
    Q.push(start);
    DIST[start] = 1;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (pii next: adj[cur]) {
            if(DIST[next.first] != 0) continue;
            Q.push(next.first);
            DIST[next.first] = DIST[cur] + next.second;
        }
    }
}

int main()
{
    FastIO;
    cin >> N;
    for (int i = 0; i < N-1; ++i) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp1].emplace_back(tmp2, tmp3);
        adj[tmp2].emplace_back(tmp1, tmp3);
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        BFS(i);
        for (int j = 1; j <= N; ++j) {
            ans = max(ans, DIST[j]);
        }
    }

    cout << ans - 1;

}