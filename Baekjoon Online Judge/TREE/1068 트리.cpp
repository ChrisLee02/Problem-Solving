/*
첫째 줄에 트리의 노드의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄에는 0번 노드부터 N-1번 노드까지, 각 노드의 부모가 주어진다.
 만약 부모가 없다면 (루트) -1이 주어진다. 셋째 줄에는 지울 노드의 번호가 주어진다.

출력
첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력한다.
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
int parent[100001];
int leaf_cnt[100001];
int cnt = 0;

int count_LEAF(int node) {
    if(adj[node].empty()) {
        leaf_cnt[node] = 1;
        return 1;
    }

    for(int i: adj[node]) {
        leaf_cnt[node] += count_LEAF(i);
    }

    return leaf_cnt[node];

}

int main()
{
    FastIO;
    cin >> N;
    int root;
    for (int i = 0; i < N; ++i) {
        int tmp; cin >> tmp;
        parent[i] = tmp;
        if(tmp==-1) {
            root = i;
        } else adj[tmp].push_back(i);
    }
    int tmp; cin >> tmp;
    adj[parent[tmp]].erase(std::remove(adj[parent[tmp]].begin(), adj[parent[tmp]].end(),tmp), adj[parent[tmp]].end());
    count_LEAF(root);



    cout << (leaf_cnt[root] - leaf_cnt[tmp]);

}