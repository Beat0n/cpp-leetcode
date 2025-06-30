// 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
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
  vector<int> inorderTraversal(TreeNode *root) {
    auto cur = root;
    stack<TreeNode *> st;
    vector<int> ans;
    while (!st.empty() || cur != nullptr) {
      if (cur != nullptr) {
        st.push(cur);
        cur = cur->left;
      } else {
        cur = st.top();
        st.pop();
        ans.push_back(cur->val);
        cur = cur->right;
      }
    }
    return ans;
  }
};