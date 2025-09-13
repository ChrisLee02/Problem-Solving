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

vector<int> adj[20001];
int score[20001];
bool Visit[20001];

int N,M;
void BFS(int start) {
    int Dist[20001];
    for (int i = 1; i <= N; ++i) {
        Visit[i] = false;
    }

    queue<int> Q{};
    Q.push(start);
    Visit[start] = true;
    Dist[start] = 0;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        score[start]++;
        for (int i: adj[cur]) {
            if(Visit[i]) continue;

            Q.push(i);
            Visit[i] = true;
            Dist[i] = Dist[cur] + 1;
        }
    }
    int ans_score;
    vector<int> ans_candidate{};

    ans_score = *max_element(Dist + 1, Dist + N + 1);
    for (int i = 1; i <= N; ++i) {
        if(Dist[i] == ans_score) ans_candidate.push_back(i);
    }
    cout << ans_candidate[0] << " " << ans_score  << " " << ans_candidate.size();

}

int main() {
    FastIO;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp2].push_back(tmp1);
        adj[tmp1].push_back(tmp2);
    }


    BFS(1);
}