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


unordered_map<int, int> map_score{};
vector<int> adj[100001];
int parent[100001];
int score[100001];

// 단순히 접근하면 nm = 100억이라 안됨.
// m개의 입력을 map에 집어넣고, 한 번의 BFS에서 끝낸다.


void compliment(int node, int add) {
    score[node] = add + map_score[node];
    for(int child: adj[node]) {
        compliment(child, score[node]);
    }
}

int main()
{
    FastIO;
    cin >> N >> M;
    int root;
    for (int i = 1; i <= N; ++i) {
        int tmp; cin >> tmp;
        if(tmp == -1) {
            root = i;
        }
        else {
            parent[i] = tmp;
            adj[tmp].push_back(i);
        }
    }
    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        map_score[tmp1] += tmp2;
    }

    compliment(root, 0);

    for (int i = 1; i <= N; ++i) {
        cout << score[i] << " ";
    }
}