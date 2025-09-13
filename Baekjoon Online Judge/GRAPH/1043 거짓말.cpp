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
// 두 번째 줄에 진실을 아는 사람들이 BFS의 start가 된다.
// 그 후 파티장에 오는 사람들이

int N, M;
int truth_size;

vector<int> truth_start{};
set<int> truth_forum{};
vector<int> party_people[51];
set<int> adj[51];
int Visit[51];


void BFS(int start) {
    queue<int> Q{};
    Q.push(start);
    Visit[start] = true;
    while (!Q.empty()) {
        int cur = Q.front();
        truth_forum.insert(cur);
        Q.pop();
        for (int next: adj[cur]) {
            if (!Visit[next]) {
                Q.push(next);
                Visit[next] = 1;
            }
        }
    }


}
int main()
{
    FastIO;
    cin >> N >> M >> truth_size;
    for (int i = 0; i < truth_size; ++i) {
        int tmp; cin >> tmp; truth_start.push_back(tmp);
    }
    for (int i = 1; i <= M; ++i) {
        int party_size; cin >> party_size;
        for (int j = 0; j < party_size; ++j) {
            int tmp; cin >> tmp; party_people[i].push_back(tmp);
        }
        for (int j = 0; j < party_size; ++j) {
            for (int k = j + 1; k < party_size; ++k) {
                int tmp1, tmp2;
                tmp1 = party_people[i][j];
                tmp2 = party_people[i][k];

                adj[tmp1].insert(tmp2);
                adj[tmp2].insert(tmp1);
            }
        }
    }

    for(int i: truth_start) {
        if(Visit[i]) continue;
        BFS(i);
    }
    int ans = 0;
    for (int i = 1; i <= M; ++i) {
        bool success = true;
        for (int j = 0; j < party_people[i].size(); ++j) {
            if(truth_forum.find(party_people[i][j]) != truth_forum.end()) {
                success = false;
                break;
            }
        }
        if(success) ans++;
    }
    cout<<ans;



}