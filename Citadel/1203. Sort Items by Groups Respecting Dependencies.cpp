#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  inline vector<int> topologicalSort(vector<vector<int>>& edges,
                                     vector<int>& in_degree) {
    queue<int> Q;
    for (int i = 0; i < in_degree.size(); i++) {
      if (in_degree[i] == 0) Q.push(i);
    }

    vector<int> sorted;
    while (!Q.empty()) {
      int node = Q.front();
      Q.pop();
      sorted.push_back(node);

      for (int neighbor : edges[node]) {
        in_degree[neighbor]--;
        if (in_degree[neighbor] == 0) Q.push(neighbor);
      }
    }
    return sorted;
  }

 public:
  vector<int> sortItems(int n, int m, vector<int>& group,
                        vector<vector<int>>& beforeItems) {
    for (int i = 0; i < n; i++) {
      if (group[i] == -1) {
        group[i] = m;
        m++;
      }
    }

    vector<vector<int>> edges_groupwise(m, vector<int>());
    vector<int> in_degree_groupwise(m, 0);

    vector<vector<int>> edges_nodewise(n, vector<int>());
    vector<int> in_degree_nodewise(n, 0);

    for (int i = 0; i < n; i++) {
      for (int beforeItem : beforeItems[i]) {
        edges_nodewise[beforeItem].push_back(i);
        in_degree_nodewise[i]++;

        if (group[i] != group[beforeItem]) {
          edges_groupwise[group[beforeItem]].push_back(group[i]);
          in_degree_groupwise[group[i]]++;
        }
      }
    }

    vector<int> sorted_groups =
        topologicalSort(edges_groupwise, in_degree_groupwise);
    vector<int> sorted_elements =
        topologicalSort(edges_nodewise, in_degree_nodewise);

    if (sorted_groups.size() != m) return {};
    if (sorted_elements.size() != n) return {};

    vector<int> ans;
    vector<vector<int>> ans_group(m, vector<int>());

    for (int node : sorted_elements) {
      ans_group[group[node]].push_back(node);
    }

    for (int group : sorted_groups) {
      ans.insert(ans.end(), ans_group[group].begin(), ans_group[group].end());
    }

    return ans;
  }
};