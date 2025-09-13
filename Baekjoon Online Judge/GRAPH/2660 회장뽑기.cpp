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

int N;
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

    score[start] = *max_element(Dist + 1, Dist + N + 1);

}

int main() {
    FastIO;
    cin >> N;
    while(true){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        if(tmp1 == -1 && tmp2 == -1) break;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }


    for (int i = 1; i <= N; ++i) {
        BFS(i);
    }


    int ans_score;
    vector<int> ans_candidate{};

    ans_score = *min_element(score + 1, score + N + 1);
    for (int i = 1; i <=N; ++i) {
        if(score[i] == ans_score) ans_candidate.push_back(i);
    }
    cout << ans_score << " " << ans_candidate.size() << endl;
    for(int i: ans_candidate) {
        cout << i << " ";
    }


}