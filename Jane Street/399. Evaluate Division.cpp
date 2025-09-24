#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  // what if,, we need to detect contradiction???
  // detect it when unite called!
  struct UnionfindWithRatio {
    vector<int> parents;

    // ratios[i] = i / parents[i];
    vector<double> ratios;

    UnionfindWithRatio(int n) {
      parents.resize(n);
      ratios.resize(n);

      for (int i = 0; i < n; i++) {
        parents[i] = i;
        ratios[i] = 1.0;
      }
    }

    // i / root = (i / parent[i]) * (parent[i] / parent[parent[i]]) * ...
    pair<int, double> find(int node) {
      int root = node;
      double node_root_ratio = 1.0;
      while (parents[root] != root) {
        node_root_ratio = node_root_ratio * ratios[root];
        root = parents[root];
      }

      pair<int, double> find_result = {root, node_root_ratio};

      while (node != root) {
        int tmp_node = parents[node];
        double tmp_ratio = ratios[node];
        parents[node] = root;
        ratios[node] = node_root_ratio;
        node = tmp_node;
        node_root_ratio = node_root_ratio / tmp_ratio;
      }

      return find_result;
    }

    void unite(int nodeA, int nodeB, double ratio) {
      auto [rootA, ratioA] = find(nodeA);
      auto [rootB, ratioB] = find(nodeB);

      // nodeA / nodeB = ratio
      // nodeA / rootA = ratioA, nodeB / rootB = ratioB
      // rootA / rootB = (rootA / nodeA) * (nodeB / rootB) * (nodeA / nodeB) =
      // (ratioB / ratioA) * ratio

      if (rootA != rootB) {
        parents[rootA] = rootB;
        ratios[rootA] = (ratioB / ratioA) * ratio;
      }
      // ratio of nodeA and nodeB is already defined
      // then that ratio should me equal to ratio

      /* else {
        if abs (ratio - ratioA / ratioB) < 1e-8 then raise exception;
      } */
    }

    // b a = 3  c a = 2
    // b c = b a / c a  = 3 / 2
    double getRatio(int nodeA, int nodeB) {
      auto [rootA, ratioA] = find(nodeA);
      auto [rootB, ratioB] = find(nodeB);

      if (rootA == rootB)
        return ratioA / ratioB;
      else
        return -1.0;
    }
  };

 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    int N = equations.size();
    int M = queries.size();

    unordered_map<string, int> var_to_id;
    int increment_id = 0;

    UnionfindWithRatio uf = UnionfindWithRatio(50);

    for (int i = 0; i < N; i++) {
      const vector<string>& equation = equations[i];
      const double value = values[i];

      if (var_to_id.count(equation[0]) == 0)
        var_to_id[equation[0]] = increment_id++;
      if (var_to_id.count(equation[1]) == 0)
        var_to_id[equation[1]] = increment_id++;

      uf.unite(var_to_id[equation[0]], var_to_id[equation[1]], value);
    }

    vector<double> ans;
    for (const vector<string>& query : queries) {
      auto itA = var_to_id.find(query[0]);
      auto itB = var_to_id.find(query[1]);

      if (itA == var_to_id.end() || itB == var_to_id.end())
        ans.push_back(-1.0);
      else {
        ans.push_back(uf.getRatio(itA->second, itB->second));
      }
    }

    return ans;
  }
};