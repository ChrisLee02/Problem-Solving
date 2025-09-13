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

vector<int> adj[1001];
int Visit[1001];

int main()
{
    FastIO;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if( !Visit[i] ) {
            count++;
            stack<int> S{};
            S.push(i);
            Visit[i] = 1;
            while(!S.empty()) {
                int cur = S.top(); S.pop();
                for(int next: adj[cur]) {
                    if(Visit[next]) continue;
                    S.push(next);
                    Visit[next] = 1;

                }
            }
        }
    }
    cout << count;
}