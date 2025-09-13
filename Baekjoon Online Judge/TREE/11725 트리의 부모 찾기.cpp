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

vector<int> adj[100001];
int parent[100001];

void TREE_BFS(int root) {
    queue<int> Q{};
    Q.push(root);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for(int next: adj[cur]) {
            if(parent[cur] == next) continue;

            Q.push(next);
            parent[next] = cur;
        }

    }
}

int main()
{
    FastIO;
    cin >> N;
    for (int i = 0; i < N-1; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
    TREE_BFS(1);
    for (int i = 2; i <= N; ++i) {
        cout << parent[i] << endl;
    }
}