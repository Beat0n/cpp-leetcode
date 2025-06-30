// 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
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
  vector<int> largestValues(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    vector<TreeNode *> prev{root};
    vector<int> ans;
    while (!prev.empty()) {
      vector<TreeNode *> cur;
      int max_val = 0;
      for (auto node : prev) {
        max_val = max(max_val, node->val);
        if (node->left) {
          cur.push_back(node->left);
        }
        if (node->right) {
          cur.push_back(node->right);
        }
      }
      prev = cur;
      ans.push_back(max_val);
    }
    return ans;
  }
};