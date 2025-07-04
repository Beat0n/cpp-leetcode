// 给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:

// 创建一个根节点，其值为 nums 中的最大值。
// 递归地在最大值 左边 的 子数组前缀上 构建左子树。
// 递归地在最大值 右边 的 子数组后缀上 构建右子树。
// 返回 nums 构建的 最大二叉树 。
#include <algorithm>
#include <vector>

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
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    if (nums.empty()) return nullptr;
    auto max_pos = ranges::max_element(nums);
    auto left = vector<int>(nums.begin(), max_pos);
    auto right = vector<int>(max_pos + 1, nums.end());
    return new TreeNode(*max_pos, constructMaximumBinaryTree(left), constructMaximumBinaryTree(right));
  }
};