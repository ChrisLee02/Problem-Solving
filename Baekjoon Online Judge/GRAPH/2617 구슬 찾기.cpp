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
// a>b를 a->b로 저장하면, 연결요소(a) = a보다 작은 구슬의 개수 -> 사이즈가 N+1/2보다 크거나 같으면 얘는 중간값이 될 수 없음
//      b->a로 저장하면,             a보다 큰 구슬의 개수 -> 사이즈가 N+2/2보다 크거나 같으면 불가함.
// count를 -1부터 시작해야함.
vector<int> adj1[100];
vector<int> adj2[100];
int score[100];
bool Visit[100];

int N, M;
int ans = 0;

void BFS(int start, vector<int> adj[100], bool state) {
    for (int i = 1; i <= N; ++i) {
        Visit[i] = false;
    }

    queue<int> Q{};
    Q.push(start);
    Visit[start] = true;
    int count = -1;
    while (!Q.empty()) {
        int cur = Q.front();
        count++;
        Q.pop();
        for (int next: adj[cur]) {
            if (!Visit[next]) {
                Q.push(next);
                Visit[next] = 1;
            }
        }
    }


    if (state) { // 작은 케이스
        if ((int) (N + 1) / 2 <= count) ans++;
    } else {
        if ((int) (N + 2) / 2 <= count) ans++;
    }

}

int main() {
    FastIO;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj1[tmp1].push_back(tmp2);
        adj2[tmp2].push_back(tmp1);
    }


    for (int i = 1; i <= N; ++i) {
        BFS(i, adj1, true);
        BFS(i, adj2, false);
    }
    cout << ans;


}