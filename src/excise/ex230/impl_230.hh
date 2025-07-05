// 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。
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
  int nth = 1;

 public:
  int kthSmallest(TreeNode *root, int k) {
    if (root == nullptr) return -1;
    int left = kthSmallest(root->left, k);
    if (nth == k) return left;
    nth++;
    if (nth == k) return root->val;
    return kthSmallest(root->right, k);
  }
};