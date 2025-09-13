/*
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다.
 (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

출력
첫째 줄에 연결 요소의 개수를 출력한다.

*/
#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int **graph = new int *[N + 1];
    for (int i = 0; i < N + 1; ++i) {
        graph[i] = new int[N + 1];
        memset(graph[i], 0, sizeof(int) * (N + 1));
    }

    /*for (int i = 1; i < N + 1; ++i) {
        for (int j = 1; j < N + 1; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }*/

    set<int> unVisited = set<int>();

    for (int i = 1; i < N + 1; ++i) {
        unVisited.insert(i);
    }


    int u, v;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    int count = 0;
    while (!unVisited.empty()) {
        stack<int> stack = std::stack<int>();
        stack.push(*unVisited.begin());
        while (!stack.empty()) {
            int index = stack.top();
            unVisited.erase(index);
            stack.pop();
            for (int i = 1; i <= N; i++) {
                if (graph[index][i] == 1 && unVisited.find(i) != unVisited.end()) { //i가 unVisited에 있다면.
                    stack.push(i);
                }
            }
        }
        count++;
    }
    cout << count;


}