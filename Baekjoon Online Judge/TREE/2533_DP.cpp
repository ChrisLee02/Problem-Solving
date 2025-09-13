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
vector<int> child[1000001];
int parent[1000001];
int dp[1000001][2]; // 트리에서의 dp -> 부모의 최적해가 자식의 최적해로 구성되는 경우 사용할 수 있다.
// dp[i][0] = i를 택하지 않았을 때 i의 서브트리 최적해, dp[i][1] = i를 택했을 때 i의 서브트리 최적해

// dp[i][0] = sum(dp[child[i]][1]) , dp[i][1] = sum(min(dp[child[i]][1],dp[child[i]][0])로 정의된다.

void BFS(int start) {
    queue<int> Q{};
    Q.push(start);

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for(int next: adj[cur]) {
            if(parent[cur] == next) continue;

            Q.push(next);
            parent[next] = cur;
            child[cur].push_back(next);
        }
    }
}

void DFS(int root) {
    dp[root][0] = 0; dp[root][1] = 1;

    for(int next: child[root]) {
        DFS(next);
        dp[root][0] += dp[next][1];
        dp[root][1] += min(dp[next][0], dp[next][1]);
    }


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

    DFS(1);

    cout << min(dp[1][0], dp[1][1]);

}