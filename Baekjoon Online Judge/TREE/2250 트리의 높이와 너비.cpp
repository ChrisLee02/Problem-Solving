/*
첫째 줄에 노드의 개수를 나타내는 정수 N(1 ≤ N ≤ 10,000)이 주어진다. 다음 N개의 줄에는 각 줄마다 노드 번호와 해당 노드의 왼쪽 자식 노드와
 오른쪽 자식 노드의 번호가 순서대로 주어진다. 노드들의 번호는 1부터 N까지이며, 자식이 없는 경우에는 자식 노드의 번호에 -1이 주어진다.

출력
첫째 줄에 너비가 가장 넓은 레벨과 그 레벨의 너비를 순서대로 출력한다. 너비가 가장 넓은 레벨이 두 개 이상 있을 때에는 번호가 작은 레벨을 출력한다.
 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

// 중위순회한다.

using namespace std;

int N, M;

int parent[10001];
int SIZE[10001];
int Left[10001];
int Right[10001];
int height[10001];
int xval[10001];

int max_height = 1;

set<int> height_to_xval[10001];

int get_size_and_height(int node) {
    height[node] = height[parent[node]] + 1;
    max_height = max(max_height, height[node]);
    SIZE[node] = 1;
    if(Left[node] != -1) {
        SIZE[node] += get_size_and_height(Left[node]);
    }
    if(Right[node] != -1) {
        SIZE[node] += get_size_and_height(Right[node]);
    }

    return SIZE[node];

}

void get_xval_by_right_parent(int node);
void get_xval_by_left_parent(int node);

void get_xval_by_right_parent(int node) {
    int pos = xval[parent[node]] - 1 - SIZE[Right[node]];
    xval[node] = pos;
    height_to_xval[height[node]].insert(pos);

    if(Left[node] != -1) {
        get_xval_by_right_parent(Left[node]);
    }
    if(Right[node] != -1) {
        get_xval_by_left_parent(Right[node]);
    }
}

void get_xval_by_left_parent(int node) {
    int pos = xval[parent[node]] + 1 + SIZE[Left[node]];
    xval[node] = pos;
    height_to_xval[height[node]].insert(pos);

    if(Left[node] != -1) {
        get_xval_by_right_parent(Left[node]);
    }
    if(Right[node] != -1) {
        get_xval_by_left_parent(Right[node]);
    }
}

void get_xval_root(int root) {
    int pos = 1 + SIZE[Left[root]];
    xval[root] = pos;
    height_to_xval[1].insert(pos);

    if(Left[root] != -1) {
        get_xval_by_right_parent(Left[root]);
    }
    if(Right[root] != -1) {
        get_xval_by_left_parent(Right[root]);
    }

}






int main()
{
    FastIO;
    cin >> N;
    int root = 0;
    for (int i = 0; i < N; ++i) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        Left[tmp1] = tmp2;
        Right[tmp1] = tmp3;
        parent[tmp2] = tmp1;
        parent[tmp3] = tmp1;
    }

    for(int i = 1; i <= N; i++) {
        if(parent[i] == 0) {
            root = i;
            break;
        }
    }

    get_size_and_height(root);

    get_xval_root(root);
    int ans_height = 0;
    int ans_width = 0;

    for (int i = 1; i <= max_height; ++i) {
        int width = *height_to_xval[i].rbegin() - *height_to_xval[i].begin() + 1;
        if(ans_width < width) {
            ans_height = i;
            ans_width = width;
        }
    }

    cout << ans_height << " " << ans_width;


}