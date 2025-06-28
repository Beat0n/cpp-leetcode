
#include "../common.hh"

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverse(ListNode *head) {
    ListNode *new_head = nullptr;
    auto node = head;
    while (node != nullptr) {
      auto next = node->next;
      node->next = new_head;
      new_head = node;
      node = next;
    }
    return new_head;
  }
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *new_head = nullptr;
    auto node = head;
    for (int i = 0; i < k; ++i) {
      if (node == nullptr) {
        new_head = reverse(new_head);
        return new_head;
        ;
      }
      auto next = node->next;
      node->next = new_head;
      new_head = node;
      node = next;
    }
    head->next = reverseKGroup(node, k);
    return new_head;
  }
};