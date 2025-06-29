// 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

// 你应当 保留 两个分区中每个节点的初始相对位置。
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
  ListNode* partition(ListNode* head, int x) {
    ListNode* front_head = nullptr;
    ListNode* front_last = nullptr;
    ListNode* behind_head = nullptr;
    ListNode* behind_last = nullptr;
    auto cur = head;
    while (cur != nullptr) {
      if (cur->val < x) {
        if (front_head == nullptr) {
          front_head = cur;
          front_last = cur;
        } else {
          front_last->next = cur;
          front_last = cur;
        }
      } else {
        if (behind_head == nullptr) {
          behind_head = cur;
          behind_last = cur;
        } else {
          behind_last->next = cur;
          behind_last = cur;
        }
      }
      cur = cur->next;
    }
    if (front_last != nullptr) {
      front_last->next = behind_head;
    }
    if (behind_last != nullptr) {
      behind_last->next = nullptr;
    }
    return front_head != nullptr ? front_head : behind_head;
  }
};