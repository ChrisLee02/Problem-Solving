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

vector<int> adj[1000001];
int parent[1000001];
int height[1000001];
vector<int> height_to_nodes[1000001];

/* unordered_set<int> leaf_nodes{};
unordered_set<int> parent_of_leaf_nodes{}; */

/*auto comp = [](int a, int b) {
    if(adj[a].size() == adj[b].size()) {
        return a>b;
    }
    return adj[a].size() > adj[b].size();
};

set<int, decltype(comp)> nodes_aligned_by_degree(comp);*/

// 짝수 height를 다 더하거나, 홀수 height를 다 더하는게 답임..
// -> 이건 루트를 뭘로 잡든간에 총합은 변하지 않는다.
// height는 루트로부터의 거리랑 같은 개념인데,
// u,v의 거리가 짝수냐 홀수냐랑 동치기 때문에, 루트가 무엇이냐랑은 관련없다.
// 아니엇고,,,,

// degree를 기준으로 정렬하는 set을 이용해보자,,
// degree가 큰 놈을 greedy하게 골라가면 될 듯.
// 씨발

// 리프노드부터 쭉쭉 위로 올라가는 방식을 취해보자.
// 리프노드들의 부모를 칠하고, 부모의 부모들을 새로운 리프노드로 만든다.

unordered_set<int> ans_set{};
int max_height = 0;
void BFS(int start) {
    queue<int> Q{};
    Q.push(start);

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        height[cur] = height[parent[cur]] + 1;
        height_to_nodes[height[cur]].push_back(cur);
        max_height = max(max_height, height[cur]);
        for(int next: adj[cur]) {
            if(parent[cur] == next) continue;

            Q.push(next);
            parent[next] = cur;
        }
    }
}

bool isLeaf(int node) {
    int cnt = 0;
    for(int i: adj[node]){
        if(i == parent[node] || ans_set.find(i) != ans_set.end()) continue;
        cnt++;
    }
    return cnt == 0;

}

int main()
{
    FastIO;
    cin >> N;
    for (int i = 0; i < N-1; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }

    BFS(1);

    for(int i = max_height; i >= 1; i--) {
        for(int node: height_to_nodes[i]) {
             //cout << node <<" " << parent[node] <<endl;
            if(isLeaf(node)) {
               //  cout << "CEX" << endl;
                ans_set.insert(parent[node]);
            }
        }
    }
    if(ans_set.find(0) == ans_set.end()) {
        cout << ans_set.size();
    }
    else cout << ans_set.size() - 1;


}