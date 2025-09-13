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

vector<int> adj[51];
int score[51];
bool Visit[51];

int N,M;
void BFS(int start) {
    int Dist[51];
    for (int i = 1; i <= N; ++i) {
        Visit[i] = false;

    }

    queue<int> Q{};
    Q.push(start);
    Visit[start] = true;
    Dist[start] = 0;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (int i: adj[cur]) {
            if(Visit[i]) continue;

            Q.push(i);
            Visit[i] = true;
            Dist[i] = Dist[cur] + 1;
        }
    }

    for (int i = 1; i <= N; ++i) {
        score[start] += Dist[i];
    }

}

int main() {
    FastIO;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }


    for (int i = 1; i <= N; ++i) {
        BFS(i);
    }

    int min_person = 1;
    int min_score = score[1];
    for (int i = 2; i <= N; ++i) {
        if(score[i] < min_score) {
            min_person = i;
            min_score = score[i];
        }
    }
    cout << min_person;

}