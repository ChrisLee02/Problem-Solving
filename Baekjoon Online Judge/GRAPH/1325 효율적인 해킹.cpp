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

vector<int> adj[10001];
int score[10001];
bool Visit[10001];

int N,M;
void BFS(int start) {
    int Dist[10001];
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
}

int main() {
    FastIO;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp2].push_back(tmp1);
    }


    for (int i = 1; i <= N; ++i) {
        BFS(i);
    }

    int ans_score;
    vector<int> ans_candidate{};

    ans_score = *max_element(score + 1, score + N + 1);
    for (int i = 1; i <=N; ++i) {
        if(score[i] == ans_score) ans_candidate.push_back(i);
    }
    for(int i: ans_candidate) {
        cout << i << " ";
    }

}