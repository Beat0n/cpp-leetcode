// 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
#include <algorithm>

#include "../common.hh"

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    if (root == nullptr) {
      return {{}};
    }
    vector<TreeNode *> prev{root};
    vector<vector<int>> ans;
    while (!prev.empty()) {
      vector<TreeNode *> cur;
      vector<int> cur_val;
      for (auto node : prev) {
        cur_val.push_back(node->val);
        if (node->left) {
          cur.push_back(node->left);
        }
        if (node->right) {
          cur.push_back(node->right);
        }
      }
      prev = cur;
      ans.push_back(cur_val);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};