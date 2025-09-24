#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> parent;

  UnionFind(int n) {
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int find(int node) {
    int root = node;
    while (parent[root] == root) root = parent[root];

    while (node != root) {
      int p = parent[node];
      parent[node] = root;
      node = p;
    }

    return root;
  }

  void unite(int nodeA, int nodeB) {
    int rootA = find(nodeA);
    int rootB = find(nodeB);

    parent[rootA] = rootB;
  }

  int same(int nodeA, int nodeB) { return find(nodeA) == find(nodeB); }
};