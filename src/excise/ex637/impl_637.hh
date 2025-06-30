// 给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。
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
  vector<double> averageOfLevels(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    vector<TreeNode *> prev{root};
    vector<double> ans;
    while (!prev.empty()) {
      vector<TreeNode *> cur;
      double sum = 0;
      double n = 0;
      for (auto node : prev) {
        ++n;
        sum += node->val;
        if (node->left) {
          cur.push_back(node->left);
        }
        if (node->right) {
          cur.push_back(node->right);
        }
      }
      prev = cur;
      ans.push_back(sum / n);
    }
    return ans;
  }
};