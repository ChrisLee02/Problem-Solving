/*

 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()



// 임의의 노드에서 최장거리에 있는 노드는 반드시 지름의 한 쪽 끝이 된다.

using namespace std;

int N;


vector<pii> adj[100001];
int Visit[100001];

int ans = 0;

int max_node = 0;
int max_dist = 0;

void DFS(int node, int dist) {
    Visit[node] = 1;

    if(max_dist < dist) {
        max_dist = dist;
        max_node = node;
    }

    for(pii next: adj[node]) {
        if(Visit[next.first]) continue;
        DFS(next.first, dist + next.second);
    }

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

    DFS(1, 0);
    for (int i = 1; i <= N; ++i) {
        Visit[i] = 0;
    }
    DFS(max_node, 0);
    cout << max_dist;

}