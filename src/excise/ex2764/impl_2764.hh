// 给定一个以 0 为起始索引的整数 二维数组 nodes ，你的任务是确定给定的数组是否表示某个 二叉 树的 前序 遍历。

// 对于每个索引 i ，nodes[i] = [id, parentId] ，其中 id 是索引 i 处节点的 id，parentId 是其在树中的父节点 id（如果该节点没有父节点，则 parentId = -1
// ）。

// 如果给定的数组表示某个树的前序遍历，则返回 true ，否则返回 false 。

// 注意：树的 前序 遍历是一种递归的遍历方式，它首先访问当前节点，然后对左子节点进行前序遍历，最后对右子节点进行前序遍历。

#include "../common.hh"

class Solution {
 public:
  bool isPreorder(vector<vector<int>>& nodes) {
    if (nodes.empty()) return true;
    if (nodes[0][1] != -1) return false;
    stack<int> tree;
    tree.push(nodes[0][0]);
    for (int i = 1; i < nodes.size(); ++i) {
      if (nodes[i][1] != nodes[i - 1][0]) {
        while (!tree.empty() && tree.top() != nodes[i][1]) {
          tree.pop();
        }
        if (tree.empty()) {
          return false;
        }
      }
      tree.push(nodes[i][0]);
    }
    return true;
  }
};