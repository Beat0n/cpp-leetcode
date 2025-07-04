// 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    // 左中右 左右中
    if (postorder.empty()) return nullptr;
    int root_val = postorder.back();
    int left_size = ranges::find(inorder, root_val) - inorder.begin();
    auto left_inorder = vector<int>(inorder.begin(), inorder.begin() + left_size);
    auto right_inorder = vector<int>(inorder.begin() + left_size + 1, inorder.end());
    auto left_postorder = vector<int>(postorder.begin(), postorder.begin() + left_size);
    auto right_postorder = vector<int>(postorder.begin() + left_size, postorder.end() - 1);
    return new TreeNode(root_val, buildTree(left_inorder, left_postorder), buildTree(right_inorder, right_postorder));
  }
};