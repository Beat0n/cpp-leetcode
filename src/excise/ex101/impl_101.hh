// 给你一个二叉树的根节点 root ， 检查它是否轴对称。
#include <functional>

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
  bool isSymmetric(TreeNode *root) {
    function<bool(TreeNode *, TreeNode *)> helper = [&helper](TreeNode *left, TreeNode *right) {
      if (left == nullptr && right == nullptr) {
        return true;
      } else if (left != nullptr && right != nullptr) {
        return left->val == right->val && helper(left->left, right->right) && helper(left->right, right->left);
      } else {
        return false;
      }
    };
    return helper(root->left, root->right);
  }
};