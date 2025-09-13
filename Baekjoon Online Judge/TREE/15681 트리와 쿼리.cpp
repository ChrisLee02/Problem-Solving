/*
간선에 가중치와 방향성이 없는 임의의 루트 있는 트리가 주어졌을 때, 아래의 쿼리에 답해보도록 하자.
정점 U를 루트로 하는 서브트리에 속한 정점의 수를 출력한다.
만약 이 문제를 해결하는 데에 어려움이 있다면, 하단의 힌트에 첨부한 문서를 참고하자.

입력
트리의 정점의 수 N과 루트의 번호 R, 쿼리의 수 Q가 주어진다. (2 ≤ N ≤ 105, 1 ≤ R ≤ N, 1 ≤ Q ≤ 105)
이어 N-1줄에 걸쳐, U V의 형태로 트리에 속한 간선의 정보가 주어진다. (1 ≤ U, V ≤ N, U ≠ V)
이는 U와 V를 양 끝점으로 하는 간선이 트리에 속함을 의미한다. 이어 Q줄에 걸쳐, 문제에 설명한 U가 하나씩 주어진다. (1 ≤ U ≤ N)
입력으로 주어지는 트리는 항상 올바른 트리임이 보장된다.

출력
Q줄에 걸쳐 각 쿼리의 답을 정수 하나로 출력한다.
 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

using namespace std;
//연결요소를 찾기 위해 BFS를 실시한다. 이때 간선에 대한 for문에서 visited인 놈을 방문하는 간선이 존재하면 해당 연결요소는 트리가 아니다.


int N, R, Q_num;

vector<int> adj[100001];
int parent[100001];
int Size[100001];

void make_tree(int root) {
    queue<int> Q{};
    Q.push(root);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int next: adj[cur]) {
            if(parent[cur] == next) continue;
            Q.push(next);
            parent[next] = cur;
        }
    }
}

int get_Size(int root) { // 재귀 버전
    Size[root] = 1;
    for(int next: adj[root]) {
        if(parent[root] == next) continue;
        Size[root] += get_Size(next);
    }
    return Size[root];
}

void get_size_without_recursion(int root) { // 비재귀버전
    int Visit[100001];
    for (int i = 1; i <= N; ++i) {
        Visit[i] = 0;
    }
    stack<int> Q{};
    Q.push(root);
    while(!Q.empty()) {
        int cur = Q.top();
        int count_Unvisited = 0;
        for(int next: adj[cur]) {
            if(parent[cur] == next || Visit[next]) continue;
            Q.push(next);
            Visit[next] = 1;
            count_Unvisited++;
        }
        if(count_Unvisited == 0) {
            //리프노드 혹은 자식으로부터 다 받은 ㅅㄲ면 여기 도착임
            Size[cur]++;
            Size[parent[cur]] += Size[cur];
            Q.pop();
        }


    }
}

int main()
{
    FastIO;
    cin >> N >> R >> Q_num;
    for (int i = 0; i < N-1; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
    make_tree(R);
    get_size_without_recursion(R);
    for (int i = 0; i < Q_num; ++i) {
        int tmp; cin >> tmp;
        cout << Size[tmp] << endl;
    }



}