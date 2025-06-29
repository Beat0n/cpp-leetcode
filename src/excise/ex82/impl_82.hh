
// 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。

#include "../common.hh"

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    auto cur = head;
    ListNode* new_head = nullptr;
    ListNode* last = nullptr;
    while (cur != nullptr) {
      auto fast = cur->next;
      while (fast != nullptr && fast->val == cur->val) {
        fast = fast->next;
      }
      if (fast == cur->next) {
        if (new_head == nullptr) {
          new_head = cur;
          last = cur;
        } else {
          last->next = cur;
          last = cur;
        }
      }
      cur = fast;
    }
    if (last != nullptr) last->next = nullptr;
    return new_head;
  }
};