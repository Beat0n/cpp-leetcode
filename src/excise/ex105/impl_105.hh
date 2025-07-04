
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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty()) return nullptr;
    int root_val = preorder[0];
    int left_size = ranges::find(inorder, root_val) - inorder.begin();
    auto left_preorder = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + left_size);
    auto right_preorder = vector<int>(preorder.begin() + 1 + left_size, preorder.end());
    auto left_inorder = vector<int>(inorder.begin(), inorder.begin() + left_size);
    auto right_inorder = vector<int>(inorder.begin() + 1 + left_size, inorder.end());
    return new TreeNode(root_val, buildTree(left_preorder, left_inorder), buildTree(right_preorder, right_inorder));
  }
};