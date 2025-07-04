// 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

// 假设二叉树中至少有一个节点。
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
  int findBottomLeftValue(TreeNode *root) {
    vector<TreeNode *> prev{root};
    int ans;
    while (!prev.empty()) {
      vector<TreeNode *> cur;
      bool first = true;
      for (auto node : prev) {
        if (first) {
          first = false;
          ans = node->val;
        }
        if (node->left) {
          cur.push_back(node->left);
        }
        if (node->right) {
          cur.push_back(node->right);
        }
      }
      prev = cur;
    }
    return ans;
  }
};