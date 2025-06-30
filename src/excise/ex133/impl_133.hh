// 给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。

// 图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
#include "../common.hh"

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;
    Node* new_node = new Node(node->val);
    unordered_map<Node*, Node*> old2new;
    function<void(Node*, Node*)> dfs = [&](Node* old_node, Node* new_node) {
      old2new[old_node] = new_node;
      for (auto neb : old_node->neighbors) {
        auto iter = old2new.find(neb);
        if (iter == old2new.end()) {
          Node* new_neb = new Node(neb->val);
          new_node->neighbors.push_back(new_neb);
          dfs(neb, new_neb);
        } else {
          new_node->neighbors.push_back(iter->second);
        }
      }
    };
    dfs(node, new_node);
    return new_node;
  }
};