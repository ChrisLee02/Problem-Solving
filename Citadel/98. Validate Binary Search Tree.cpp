#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
};

class Solution {
 private:
  void preorderTraverse(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    preorderTraverse(root->left, result);
    result.push_back(root->val);
    preorderTraverse(root->right, result);
  }

 public:
  bool isValidBST(TreeNode* root) {
    // preorder tree traversal's result should be increasing array
    // (not monotonically)
    vector<int> preorder_traversal;
    preorderTraverse(root, preorder_traversal);

    for (int i = 0; i < preorder_traversal.size() - 1; i++) {
      if (preorder_traversal[i] >= preorder_traversal[i + 1]) {
        return false;
      }
    }
    return true;
  }
};