#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
};

class Codec {
 public:
  // regard nil as size 1 (full binary tree)
  int treeSize(TreeNode* root) {
    if (root == nullptr)
      return 1;
    else
      return 1 + treeSize(root->left) + treeSize(root->right);
  }

  vector<string> serializeToVec(TreeNode* root) {
    int root_size = treeSize(root);
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    vector<string> serailized_vec = serializeToVec(root);
    string serailized_str = "";
    for (int i = 0; i < serailized_vec.size() - 1; i++) {
      serailized_str += serailized_vec[i];
      serailized_str += ",";
    }
    serailized_str += serailized_vec.back();
    return serailized_str;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));