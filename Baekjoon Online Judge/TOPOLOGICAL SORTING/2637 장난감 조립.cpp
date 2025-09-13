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

vector<pii> adj[101];
map<int, int> part[101];
int in_degree[101];

void top_sort() {
    queue<int> Q{};
    for (int i = 1; i <= N; ++i) {
        if(in_degree[i] == 0) {
            Q.push(i);
            part[i][i] = 1;
        }
    }

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for(pii next: adj[cur]) {
            if(--in_degree[next.first] == 0) {
                Q.push(next.first);
            }
            for(const auto &[basic_part, cnt]: part[cur]) {
                part[next.first][basic_part] += cnt*next.second;
            }

        }
    }
    for(const auto &[basic_part, cnt]: part[N]) {
        cout << basic_part << " " << cnt << endl;
    }
}

int main()
{
    FastIO;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        adj[tmp2].emplace_back(tmp1, tmp3);
        in_degree[tmp1]++;
    }

    top_sort();




}