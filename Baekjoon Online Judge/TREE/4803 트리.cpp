/*
그래프는 정점과 간선으로 이루어져 있다. 두 정점 사이에 경로가 있다면, 두 정점은 연결되어 있다고 한다.
 연결 요소는 모든 정점이 서로 연결되어 있는 정점의 부분집합이다. 그래프는 하나 또는 그 이상의 연결 요소로 이루어져 있다.
트리는 사이클이 없는 연결 요소이다. 트리에는 여러 성질이 있다. 예를 들어, 트리는 정점이 n개, 간선이 n-1개 있다. 또, 임의의 두 정점에 대해서 경로가 유일하다.
그래프가 주어졌을 때, 트리의 개수를 세는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 n ≤ 500과 m ≤ n(n-1)/2을 만족하는 정점의 개수 n과 간선의 개수 m이 주어진다.
 다음 m개의 줄에는 간선을 나타내는 두 개의 정수가 주어진다. 같은 간선은 여러 번 주어지지 않는다. 정점은 1번부터 n번까지 번호가 매겨져 있다.
 입력의 마지막 줄에는 0이 두 개 주어진다.

출력
입력으로 주어진 그래프에 트리가 없다면 "No trees."를, 한 개라면 "There is one tree."를, T개(T > 1)라면 "A forest of T trees."를 테스트
 케이스 번호와 함께 출력한다.
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


int N, M;

vector<int> adj[501];
int Visit[501];
int parent[501];

bool BFS(int start) {
    queue<int> Q{};
    Q.push(start);
    Visit[start]=1;
    bool result = true;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int next: adj[cur]) {
            if(Visit[next]) {
                if(parent[cur] != next) result = false;
                continue;
            }
            Q.push(next);
            Visit[next] = 1;
            parent[next] = cur;
        }
    }
    //cout << result << endl;
    return result;
}

int main()
{
    FastIO;
    int case_num = 1;
    while(true) {
        cin >> N >> M;
        int ans = 0;
        if(N == 0 && M == 0) break;

        for (int i = 1; i <= N; ++i) {
            adj[i].clear();
            Visit[i] = 0;
            parent[i] = 0;
        }

        for (int i = 0; i < M; ++i) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            adj[tmp1].push_back(tmp2);
            adj[tmp2].push_back(tmp1);
        }

        for (int i = 1; i <= N; ++i) {
            if(Visit[i]) continue;
            ans += BFS(i);
        }



        cout << "Case " << case_num << ": ";
        if(ans == 0) {
            cout << "No trees." << endl;
        } else if(ans == 1) {
            cout << "There is one tree." << endl;
        } else {
            cout<<"A forest of "<< ans <<" trees." <<endl;
        }

        case_num++;

    }

}