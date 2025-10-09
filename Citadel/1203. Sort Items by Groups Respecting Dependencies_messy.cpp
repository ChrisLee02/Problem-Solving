#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  inline vector<int> topologicalSort(vector<set<int>>& edges,
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

  inline vector<int> topologicalSort(unordered_map<int, set<int>>& edges,
                                     unordered_map<int, int>& in_degree_map) {
    queue<int> Q;

    for (const auto& [node, in_degree] : in_degree_map) {
      if (in_degree == 0) Q.push(node);
    }

    vector<int> sorted;
    while (!Q.empty()) {
      int node = Q.front();
      Q.pop();
      sorted.push_back(node);

      for (int neighbor : edges[node]) {
        in_degree_map[neighbor]--;
        if (in_degree_map[neighbor] == 0) Q.push(neighbor);
      }
    }
    return sorted;
  }

 public:
  vector<int> sortItems(int n, int m, vector<int>& group,
                        vector<vector<int>>& beforeItems) {
    int m_expanded = m;

    for (int i = 0; i < n; i++) {
      if (group[i] == -1) {
        group[i] = m_expanded;
        m_expanded++;
      }
    }

    vector<set<int>> edges_between_groups(m_expanded, set<int>());
    vector<int> degree_of_groups(m_expanded, 0);
    vector<set<int>> degree_of_groups_set(m_expanded, set<int>());

    vector<unordered_map<int, set<int>>> edges_within_groups(
        m_expanded, unordered_map<int, set<int>>());
    vector<unordered_map<int, int>> degree_within_groups(
        m_expanded, unordered_map<int, int>());

    for (int i = 0; i < n; i++) {
      degree_within_groups[group[i]][i] = 0;
      for (int beforeItem : beforeItems[i]) {
        if (group[i] == group[beforeItem]) {
          edges_within_groups[group[i]][beforeItem].insert(i);
          degree_within_groups[group[i]][i]++;
        } else {
          edges_between_groups[group[beforeItem]].insert(group[i]);
          degree_of_groups_set[group[i]].insert(group[beforeItem]);
          degree_of_groups[group[i]] = degree_of_groups_set[group[i]].size();
        }
      }
    }

    vector<int> sorted_groups =
        topologicalSort(edges_between_groups, degree_of_groups);

    if (sorted_groups.size() != m_expanded) return {};

    vector<int> ans;
    for (int group : sorted_groups) {
      vector<int> sorted_elements = topologicalSort(
          edges_within_groups[group], degree_within_groups[group]);
      ans.insert(ans.end(), sorted_elements.begin(), sorted_elements.end());
    }

    if (ans.size() == n) return ans;
    return {};
  }
};