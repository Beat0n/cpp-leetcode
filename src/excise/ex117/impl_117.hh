// 给定一个二叉树：

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。

// 初始状态下，所有 next 指针都被设置为 NULL 。
#include "../common.hh"

// Definition for a Node.
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    Node* front = root;
    while (front != nullptr) {
      Node* last = nullptr;
      auto cur = front;
      front = nullptr;
      while (cur != nullptr) {
        if (cur->left != nullptr) {
          if (front == nullptr) {
            front = cur->left;
          }
          if (last == nullptr) {
            last = cur->left;
          } else {
            last->next = cur->left;
            last = last->next;
          }
        }
        if (cur->right != nullptr) {
          if (front == nullptr) {
            front = cur->right;
          }
          if (last == nullptr) {
            last = cur->right;
          } else {
            last->next = cur->right;
            last = last->next;
          }
        }
        cur = cur->next;
      }
    }
    return root;
  }
};