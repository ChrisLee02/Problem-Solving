/*
첫 번째 줄에 뉴런의 개수 N과 시냅스의 개수 M이 주어진다.
이후 M개의 줄에 걸쳐 시냅스로 연결된 두 뉴런의 번호 u, v가 주어진다.
모든 입력은 공백으로 구분되어 주어진다.

출력
첫 번째 줄에 모든 뉴런을 트리 형태로 연결하기 위하여 필요한 최소 연산 횟수를 출력한다.
 */

#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define FF first
#define SS second
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()

// 연결 요소를 카운팅하면서, 연결 요소에서 중복인 간선의 개수를 더하고,
// 연결 요소들끼리 연결하는 횟수를 더해주면 답이다.

using namespace std;

int N, M;

vector<int> adj[100001];
int Visit[100001];
int parent[100001];

int cnt_of_CC = 0;

int cnt_of_extra_edge = 0;

void BFS(int start) {
    cnt_of_CC++;
    int edges = 0;
    int nodes = 0;
    queue<int> Q{};
    Q.push(start);
    Visit[start] = 1;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        nodes++;
        for(int next: adj[cur]) {
            /*edges++;
            if(Visit[next]) continue;
            Q.push(next);
            Visit[next] = 1;
            parent[next] = cur;*/

            if(parent[cur] == next) continue; // 부모인 경우 패스하지만, 이 간선은 지울 수 없다.

            if(Visit[next]) { // 부모가 아닌 놈인데 이미 방문했다면, 이 간선은 사이클을 만드므로 지워야한다.
                edges++; // 이게 두 번 세지는 문제가 있다.
                continue;
            }

            Q.push(next);
            Visit[next] = 1;
            parent[next] = cur;
        }
    }
    cnt_of_extra_edge += edges/2;

}

int main()
{
    FastIO;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }

    for (int i = 1; i <= N; ++i) {
        if(Visit[i]) continue;

        //cout << i<<endl;
        BFS(i);
        //cout << cnt_of_extra_edge << " " <<  cnt_of_CC <<endl;

    }

    cout << cnt_of_extra_edge + cnt_of_CC - 1;

}