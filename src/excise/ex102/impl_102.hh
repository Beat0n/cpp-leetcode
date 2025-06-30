// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
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
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) {
      return {};
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
    return ans;
  }
};