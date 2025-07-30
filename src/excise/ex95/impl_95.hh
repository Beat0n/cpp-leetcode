// 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
#include <vector>

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
 private:
  TreeNode *add(TreeNode *node, int base) {
    if (node == nullptr) {
      return nullptr;
    }
    auto new_node = new TreeNode(node->val + base);
    new_node->left = add(node->left, base);
    new_node->right = add(node->right, base);
    return new_node;
  }

  TreeNode *combine(TreeNode *left, TreeNode *right, int val) {
    auto root = new TreeNode(val);
    root->left = left;
    root->right = right;
    return root;
  }

 public:
  vector<TreeNode *> generateTrees(int n) {
    vector<vector<TreeNode *>> dp{{nullptr}, {new TreeNode(1)}};
    for (int i = 2; i <= n; ++i) {
      dp.push_back({});
      for (int j = 1; j <= i; ++j) {
        vector<TreeNode *> right;
        for (const auto right_node : dp[i - j]) {
          right.push_back(add(right_node, j));
        }
        for (const auto left_node : dp[j - 1]) {
          for (const auto right_node : right) {
            dp[i].push_back(combine(left_node, right_node, j));
          }
        }
      }
    }
    return dp[n];
  }
};