// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto fast = head;
    auto slow = head;
    ListNode *prev = nullptr;
    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }
    while (fast != nullptr) {
      fast = fast->next;
      prev = slow;
      slow = slow->next;
    }
    if (slow == head) {
      return slow->next;
    } else {
      prev->next = slow->next;
      return head;
    }
  }
};