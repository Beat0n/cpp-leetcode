// 给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
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
    auto cur = head->next;
    auto last = head;
    while (cur != nullptr) {
      if (last->val != cur->val) {
        last->next = cur;
        last = cur;
      }
      cur = cur->next;
    }
    last->next = nullptr;
    return head;
  }
};