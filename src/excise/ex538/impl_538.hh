// 给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val
// 的值之和。
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
  int pre_sum = 0;

 public:
  TreeNode *convertBST(TreeNode *root) {
    if (root == nullptr) return nullptr;
    convertBST(root->right);
    root->val += pre_sum;
    pre_sum = root->val;
    convertBST(root->left);
    return root;
  }
};