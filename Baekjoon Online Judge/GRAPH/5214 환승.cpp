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

int N, M, K;
int Visit[100001];
int Dist[100001];
vector<int> hyperLoop[1001];
vector<int> station_to_hyperLoopIndex[100001];

void BFS(int start) {
    queue<int> Q{};
    Q.push(start);
    Visit[start] = true;
    Dist[start] = 1;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int hyperLoopIndex: station_to_hyperLoopIndex[cur]) {
            for(int next: hyperLoop[hyperLoopIndex]) {
                if (!Visit[next]) {
                    Q.push(next);
                    Visit[next] = 1;
                    Dist[next] = Dist[cur] + 1;
                }
            }
        }
    }


}
int main()
{
    FastIO;
    cin >> N >> K >> M;
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j < K; ++j) {
            int tmp; cin >> tmp;
            hyperLoop[i].push_back(tmp);
            station_to_hyperLoopIndex[tmp].push_back(i);
        }
    }

    BFS(1);

    if(Visit[N]) cout << Dist[N];
    else cout << -1;

}