// 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

// 差值是一个正数，其数值等于两值之差的绝对值。
#include <climits>

#include "../common.hh"

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
  int ans = INT_MAX;
  int pre = 1e6;

  void helper(TreeNode *root) {
    if (root == nullptr) return;
    helper(root->left);
    ans = min(ans, root->val - pre);
    pre = root->val;
    helper(root->right);
  }

 public:
  int getMinimumDifference(TreeNode *root) {
    helper(root);
    return ans;
  }
};