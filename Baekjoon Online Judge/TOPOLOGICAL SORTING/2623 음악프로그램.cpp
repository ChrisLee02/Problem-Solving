/*
첫째 줄에는 가수의 수 N과 보조 PD의 수 M이 주어진다. 가수는 번호 1, 2,…,N 으로 표시한다. 둘째 줄부터 각 보조 PD가 정한 순서들이 한 줄에 하나씩 나온다.
 각 줄의 맨 앞에는 보조 PD가 담당한 가수의 수가 나오고, 그 뒤로는 그 가수들의 순서가 나온다. N은 1이상 1,000이하의 정수이고, M은 1이상 100이하의 정수이다.

출력
출력은 N 개의 줄로 이뤄지며, 한 줄에 하나의 번호를 출력한 다. 이들은 남일이가 정한 가수들의 출연 순서를 나타낸다. 답이 여럿일 경우에는 아무거나 하나를 출력 한다.
 만약 남일이가 순서를 정하는 것이 불가능할 경우에는 첫째 줄에 0을 출력한다.
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
int in_degree[100001];
vector<int> result{};

void top_sort() {
    queue<int> Q{};
    for (int i = 1; i <= N; ++i) {
        if(in_degree[i] == 0) Q.push(i);
    }

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        result.push_back(cur);
        for(int next: adj[cur]) {
            if(--in_degree[next] == 0) {
                Q.push(next);
            }
        }
    }
    if(result.size() == N) {
        for(int i: result) {
            cout << i << " ";
        }
    }
    else cout << 0;
}

int main()
{
    FastIO;
    cin >> N >> M;
    string delimiter = " ";
    for (int i = 0; i < M; ++i) {
        vector<int> tmpvec{};
        int tmp; cin >> tmp;
        for (int j = 0; j < tmp; ++j) {
            int tmp2; cin >> tmp2;
            tmpvec.push_back(tmp2);
        }

        for(int j = 0; j< (int)tmpvec.size() - 1; j++) {
            adj[tmpvec[j]].push_back(tmpvec[j+1]);
            in_degree[tmpvec[j+1]]++;
        }
    }

    top_sort();
}