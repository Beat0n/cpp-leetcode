// 给定二叉树的根节点 root ，返回所有左叶子之和。
#include <functional>

#include "../common.hh"

//  Definition for a binary tree node.
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
  int sumOfLeftLeaves(TreeNode *root) {
    int ans = 0;
    function<void(TreeNode *)> dfs = [&](TreeNode *node) {
      if (node == nullptr) return;
      auto left = node->left;
      if (left != nullptr && left->left == nullptr && left->right == nullptr) {
        ans += left->val;
      }
      dfs(left);
      dfs(node->right);
    };
    dfs(root);
    return ans;
  }
};