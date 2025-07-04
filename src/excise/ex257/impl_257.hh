// 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

// 叶子节点 是指没有子节点的节点。
#include <functional>
#include <string>

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
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    function<void(TreeNode *, string)> dfs = [&](TreeNode *node, string cur) {
      if (cur.empty()) {
        cur = to_string(node->val);
      } else {
        cur.append("->");
        cur.append(to_string(node->val));
      }
      if (node->left == nullptr && node->right == nullptr) {
        ans.push_back(cur);
        return;
      }
      if (node->left) {
        dfs(node->left, cur);
      }
      if (node->right) {
        dfs(node->right, cur);
      }
    };
    dfs(root, "");
    return ans;
  }
};
