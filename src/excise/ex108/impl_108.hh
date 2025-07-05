// 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。
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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
      return nullptr;
    } else if (n == 1) {
      return new TreeNode(nums[0]);
    } else {
      auto left = vector<int>(nums.begin(), nums.begin() + n / 2);
      auto right = vector<int>(nums.begin() + n / 2 + 1, nums.end());
      return new TreeNode(nums[n / 2], sortedArrayToBST(left), sortedArrayToBST(right));
    }
  }
};