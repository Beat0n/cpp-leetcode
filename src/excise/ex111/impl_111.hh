
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
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    vector<TreeNode *> prev{root};
    int ans = 1;
    while (!prev.empty()) {
      vector<TreeNode *> cur;
      vector<int> cur_val;
      for (auto node : prev) {
        cur_val.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
          return ans;
        }
        if (node->left) {
          cur.push_back(node->left);
        }
        if (node->right) {
          cur.push_back(node->right);
        }
      }
      prev = cur;
      ++ans;
    }
    return ans;
  }
};