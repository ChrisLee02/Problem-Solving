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
int in_degree[100001];
vector<int> result{};

void top_sort() {


}

int main()
{
    FastIO;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        in_degree[tmp2]++;
    }

    priority_queue<int, vector<int>, greater<>> Q{};
    for (int i = 1; i <= N; ++i) {
        if(in_degree[i] == 0) Q.push(i);
    }

    while(!Q.empty()) {
        int cur = Q.top(); Q.pop();
        cout << cur << " ";
        for(int next: adj[cur]) {
            if(--in_degree[next] == 0) {
                Q.push(next);
            }
        }
    }




}