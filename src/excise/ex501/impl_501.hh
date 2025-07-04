// 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。

// 如果树中有不止一个众数，可以按 任意顺序 返回。

// 假定 BST 满足如下定义：

// 结点左子树中所含节点的值 小于等于 当前节点的值
// 结点右子树中所含节点的值 大于等于 当前节点的值
// 左子树和右子树都是二叉搜索树
#include <vector>

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
  vector<int> ans;
  int pre = INT_MIN;
  int max_cnt = 0;
  int cur_cnt = 0;

  void helper(TreeNode *root) {
    if (root == nullptr) return;
    helper(root->left);
    if (root->val == pre) {
      cur_cnt++;
    } else {
      cur_cnt = 1;
    }
    if (cur_cnt > max_cnt) {
      max_cnt = cur_cnt;
      if (root->val != pre || ans.size() != 1) {
        ans.clear();
        ans.push_back(root->val);
      }
    } else if (cur_cnt == max_cnt) {
      ans.push_back(root->val);
    }
    pre = root->val;
    helper(root->right);
  }

 public:
  vector<int> findMode(TreeNode *root) {
    helper(root);
    return ans;
  }
};