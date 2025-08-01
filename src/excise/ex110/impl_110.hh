// 给定一个二叉树，判断它是否是 平衡二叉树
#include <cstdlib>

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
 private:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }

 public:
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) return true;
    return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1;
  }
};