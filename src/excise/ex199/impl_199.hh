// 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

// 示例 1：

// 输入：root = [1,2,3,null,5,null,4]

// 输出：[1,3,4]
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
  vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    vector<TreeNode *> prev{root};
    vector<int> ans;
    while (!prev.empty()) {
      vector<TreeNode *> cur;
      int last_val;
      for (auto node : prev) {
        last_val = node->val;
        if (node->left) {
          cur.push_back(node->left);
        }
        if (node->right) {
          cur.push_back(node->right);
        }
      }
      prev = cur;
      ans.push_back(last_val);
    }
    return ans;
  }
};