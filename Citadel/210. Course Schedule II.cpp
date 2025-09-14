#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> in_degree(numCourses);
    vector<vector<int>> edges(numCourses);
    vector<int> topological_order;

    for (const vector<int>& prerequisite : prerequisites) {
      int ai = prerequisite[0];
      int bi = prerequisite[1];

      edges[bi].push_back(ai);
      in_degree[ai]++;
    }

    queue<int> Q;

    for (int i = 0; i < numCourses; i++) {
      if (in_degree[i] == 0) Q.push(i);
    }

    while (!Q.empty()) {
      int vertex = Q.front();
      Q.pop();
      topological_order.push_back(vertex);

      for (int neighbor : edges[vertex]) {
        in_degree[neighbor]--;
        if (in_degree[neighbor] == 0) Q.push(neighbor);
      }
    }

    if (topological_order.size() == numCourses) return topological_order;
    return {};
  }
};