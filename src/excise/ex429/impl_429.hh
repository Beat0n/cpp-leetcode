
#include "../common.hh"

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  vector<vector<int>> levelOrder(Node *root) {
    if (root == nullptr) {
      return {};
    }
    vector<Node *> prev{root};
    vector<vector<int>> ans;
    while (!prev.empty()) {
      vector<Node *> cur;
      vector<int> values;
      for (auto node : prev) {
        values.push_back(node->val);
        for (auto child : node->children) {
          if (child != nullptr) {
            cur.push_back(child);
          }
        }
      }
      prev = cur;
      ans.push_back(values);
    }
    return ans;
  }
};