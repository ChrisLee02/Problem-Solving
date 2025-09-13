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

//vector<int> adj[100001];
int parent[100001];
int Right[100001];
int Left[100001];

int cnt = 0;
bool isEnd = false;
int end_node_height = 0;

void find_end_node(int root) {
    int node = root;
    while (Right[node] != -1) {
        end_node_height++;
        node = Right[node];
    }
}

void pseudo_inorder(int Node) {
    if (Left[Node] != -1) {
        cnt++;
        pseudo_inorder(Left[Node]);
    }

    if (Right[Node] != -1) {
        cnt++;
        pseudo_inorder(Right[Node]);
    }

    cnt++;
    return;
}

int main() {
    FastIO;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        Left[tmp1] = tmp2;
        Right[tmp1] = tmp3;
        parent[tmp2] = tmp1;
        parent[tmp3] = tmp1;
    }
    find_end_node(1);
    pseudo_inorder(1);

    cout << cnt - end_node_height - 1;


}