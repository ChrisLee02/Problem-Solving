/*

 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

// DFS를 이용해 서브트리에 대해 리프노드까지의 거리를 모두 저장한다. 이때 서브트리의 지름을 큰 순서의 두 값을 더한걸로 구할 수 있음.
//

using namespace std;

int N;

vector<pii> adj[100001];
vector<pii> child[100001];

int parent[100001];
multiset<int, greater<>> distances_one_way[100001];

int ans = 0;

void BFS(int start) {
    queue<int> Q{};
    Q.push(start);

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(pii next: adj[cur]) {
            if(parent[cur] == next.first) continue;
            Q.push(next.first);
            parent[next.first] = cur;
            child[cur].push_back(next);
        }
    }
}

void DFS(int root) {
    distances_one_way[root].insert(0);
    if(child[root].empty()) {
        return;
    }
    for (pii chd: child[root]) {
        DFS(chd.first);
        distances_one_way[root].insert(chd.second + *distances_one_way[chd.first].begin());
    }
   // cout << "root: " << root << " " << *distances_one_way[root].begin() << " " << *next(distances_one_way[root].begin()) << endl;
    ans = max(ans, *distances_one_way[root].begin() + *next(distances_one_way[root].begin()) );
}


int main()
{
    FastIO;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp1; cin >> tmp1;
        while(true) {
            int tmp2, d; cin >> tmp2;
            if(tmp2 == -1) break;
            cin >> d;
            adj[tmp1].emplace_back(tmp2, d);
        }
    }

    BFS(1);

    DFS(1);

    cout << ans;

}