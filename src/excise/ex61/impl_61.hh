// 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

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
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    auto node = head;
    int n = 0;
    while (node != nullptr) {
      ++n;
      node = node->next;
    }
    k %= n;
    if (k == 0) {
      return head;
    }
    auto fast = head;
    auto slow = head;
    for (int i = 0; i < k; ++i) {
      fast = fast->next;
    }
    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }
    fast->next = head;
    auto new_head = slow->next;
    slow->next = nullptr;
    return new_head;
  }
};