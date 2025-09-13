#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

class Solution {
 private:
  struct Result {
    int path_sum_connective;      // root or left(path_sum_connective)-root or
                                  // root-right(path_sum_connective)
    int path_sum_non_connective;  // left(max) or right(max) or
                                  // left(path_sum_connective)-root-right(path_sum_connective)
  };

 public:
  Result maxPathSumWithDP(TreeNode *root) {
    if (root == nullptr) return {0, 0};

    Result result;
    Result left_result = maxPathSumWithDP(root->left);
    Result right_result = maxPathSumWithDP(root->right);
    int left_max = max(left_result.path_sum_connective,
                       left_result.path_sum_non_connective);
    int right_max = max(right_result.path_sum_connective,
                        right_result.path_sum_non_connective);

    // root or left(path_sum_connective)-root or
    // root-right(path_sum_connective)
    result.path_sum_connective =
        max(root->val, max(left_result.path_sum_connective + root->val,
                           root->val + right_result.path_sum_connective));
    // left(max) or right(max) or
    // left(path_sum_connective)-root-right(path_sum_connective)
    result.path_sum_non_connective = left_result.path_sum_connective +
                                     root->val +
                                     right_result.path_sum_connective;
    if (root->left) {
      result.path_sum_non_connective =
          max(result.path_sum_non_connective, left_max);
    }

    if (root->right) {
      result.path_sum_non_connective =
          max(result.path_sum_non_connective, right_max);
    }

    return result;
  }

  int maxPathSum(TreeNode *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->val;

    Result result = maxPathSumWithDP(root);

    return max(result.path_sum_non_connective, result.path_sum_connective);
  }
};