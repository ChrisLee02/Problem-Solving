#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

using namespace std;

set<int> adj[1001];
int Visit1[1001];
int Visit2[1001];

int main()
{
    FastIO;
    int N, M, start;
    cin >> N >> M >> start;
    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        adj[tmp1].insert(tmp2);
        adj[tmp2].insert(tmp1);
    }
    stack<int> S{};
    S.push(start);

    while(!S.empty()) {
        int cur = S.top(); S.pop();
        if(Visit1[cur]) continue;
        cout << cur << endl;
        Visit1[cur] = 1;
        for(auto p = adj[cur].rbegin();
            p!=adj[cur].rend(); p++)
        {
            int next = *p;
            if(!Visit1[next]) S.push(next);
        }
    }

    queue<int> Q{};
    Q.push(start);
    Visit2[start]=1;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cout << cur << endl;
        for(int next: adj[cur]) {
            if(Visit2[next]) continue;
            Q.push(next);
            Visit2[next] = 1;

        }

    }
}