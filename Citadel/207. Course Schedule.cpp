#include <bits/stdc++.h>
using namespace std;

/*
There are a total of numCourses courses you have to take, labeled from 0 to
numCourses - 1. You are given an array prerequisites where prerequisites[i] =
[ai, bi] indicates that you must take course bi first if you want to take course
ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first
take course 1. Return true if you can finish all courses. Otherwise, return
false.
*/

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> sorted_vertexes;
    vector<int> edges[2001];
    int in_degree[2001];
    memset(in_degree, 0, sizeof(in_degree));

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
      int V = Q.front();
      Q.pop();

      sorted_vertexes.push_back(V);

      for (int neighbor : edges[V]) {
        in_degree[neighbor]--;
        if (in_degree[neighbor] == 0) Q.push(neighbor);
      }
    }

    return sorted_vertexes.size() == numCourses;
  }
};