#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    vector<vector<int>> edges(isConnected.size(), vector<int>());

    for (int i = 0; i < isConnected.size(); i++) {
      for (int j = 0; j < isConnected.size(); j++) {
        if (isConnected[i][j]) {
          edges[i].push_back(j);
        }
      }
    }

    vector<bool> visited(isConnected.size(), false);

    int connected_elements = 0;

    for (int i = 0; i < isConnected.size(); i++) {
      if (visited[i]) continue;

      queue<int> Q;
      Q.push(i);
      visited[i] = true;
      connected_elements++;

      while (!Q.empty()) {
        int node = Q.front();
        Q.pop();

        for (int neighbor : edges[node]) {
          if (visited[neighbor]) continue;

          visited[neighbor] = true;
          Q.push(neighbor);
        }
      }
    }

    return connected_elements;
  }
};