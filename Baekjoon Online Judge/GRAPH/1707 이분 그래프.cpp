/*
그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때,
 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.
그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 구성되어 있는데, 첫째 줄에 테스트 케이스의 개수 K가 주어진다. 각 테스트 케이스의 첫째 줄에는
 그래프의 정점의 개수 V와 간선의 개수 E가 빈 칸을 사이에 두고 순서대로 주어진다. 각 정점에는 1부터 V까지 차례로 번호가 붙어 있다.
 이어서 둘째 줄부터 E개의 줄에 걸쳐 간선에 대한 정보가 주어지는데, 각 줄에 인접한 두 정점의 번호 u, v (u ≠ v)가 빈 칸을 사이에 두고 주어진다.

출력
K개의 줄에 걸쳐 입력으로 주어진 그래프가 이분 그래프이면 YES, 아니면 NO를 순서대로 출력한다.

제한
2 ≤ K ≤ 5
1 ≤ V ≤ 20,000
1 ≤ E ≤ 200,000
 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
// 임의의 정점 e = {u,v}에 대해 u와 v가 각기 다른 집합에 포함되어야 한다.
// DFS든 BFS든 색 반대로 해가면서 쭉 색칠한 후에, 모든 e를 다 확인해보면 됨
using namespace std;

int V, E;
vector<int> adj[20001];
int color[20001];
int Visit[20001];
vector<pii> edges{};

void BFS(int start) {
    queue<int> Q{};
    Q.push(start);
    Visit[start] = true;
    color[start] = 1;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (int i: adj[cur]) {
            if(Visit[i]) continue;

            Q.push(i);
            Visit[i] = true;
            color[i] = color[cur]*-1;
        }
    }



}


int main()
{
    FastIO;
    int T; cin >> T;
    while(T--) {

        cin >> V >> E;

        for (int i = 1; i <= V; ++i) {
            adj[i].clear();
            Visit[i] = 0;
        }
        edges.clear();

        for (int i = 0; i < E; ++i) {
            int tmp1, tmp2; cin >> tmp1 >> tmp2;
            adj[tmp2].push_back(tmp1);
            adj[tmp1].push_back(tmp2);
            edges.emplace_back(tmp1, tmp2);
        }

        for (int i = 1; i <= V; ++i) {
            if(Visit[i]) continue;
            BFS(i);
        }
        bool success = true;
        for(pii edge: edges) {
            success = success && (color[edge.first] * color[edge.second] == -1);
            if(!success) break;
        }
        if(success) cout << "YES" << endl;
        else cout << "NO"<<endl;




    }




}