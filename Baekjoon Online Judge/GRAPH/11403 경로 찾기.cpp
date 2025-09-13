/*

 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

// SCC 쓰면 좀 더 편할 것 같은데,,시발
using namespace std;

vector<int> adj[101];
int N;
void BFS(int start) {
    int Visit[101];
    for (int i = 1; i <= N; ++i) {
        Visit[i] = 0;
    }

    queue<int> Q{};
    Q.push(start);

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (int i: adj[cur]) {
            if(Visit[i]) continue;

            Q.push(i);
            Visit[i] = true;
        }

    }

    for (int i = 1; i <= N; ++i) {
        if(Visit[i]) cout << 1 << " ";
        else cout << 0 << " ";
    }
    cout << endl;
}

int main()
{
    FastIO;
     cin >>N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int tmp; cin >> tmp;
            if(tmp) {
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        BFS(i);
    }



}