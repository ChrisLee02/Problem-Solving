#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> edges;
    unordered_map<string, unordered_map<string, double>> ratios;
    unordered_set<string> variables;
    vector<double> ans;

    for (int i = 0; i < equations.size(); i++) {
      const vector<string>& equation = equations[i];
      const string& a = equation[0];
      const string& b = equation[1];
      variables.insert({a, b});

      const double value = values[i];

      edges[a][b] = value;
      edges[b][a] = 1 / value;
    }

    for (const string& start : variables) {
      queue<string> Q;
      ratios[start][start] = 1.0;
      Q.push(start);
      while (!Q.empty()) {
        // const string& vertex = Q.front(); // shouldn't use reference here
        const string vertex = Q.front();
        Q.pop();

        for (const auto& [neighbor, weight] : edges[vertex]) {
          if (ratios[start].find(neighbor) == ratios[start].end()) {
            ratios[start][neighbor] = ratios[start][vertex] * weight;
            Q.push(neighbor);
          }
        }
      }
    }

    for (const vector<string>& query : queries) {
      const string& a = query[0];
      const string& b = query[1];

      if (ratios.find(a) != ratios.end() &&
          ratios[a].find(b) != ratios[a].end()) {
        ans.push_back(ratios[a][b]);
      } else {
        ans.push_back(-1.0);
      }
    }
    return ans;
  }
};