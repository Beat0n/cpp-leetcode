
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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *prev = nullptr;
    auto node = head;
    int i = 1;
    while (node != nullptr) {
      if (i == left) {
        break;
      }
      prev = node;
      node = node->next;
      ++i;
    }
    auto reverse = [](ListNode *head, int n) {
      ListNode *new_head = nullptr;
      auto node = head;
      while (n > 0) {
        auto next = node->next;
        node->next = new_head;
        new_head = node;
        node = next;
        --n;
      }
      head->next = node;
      return new_head;
    };
    auto new_head = reverse(node, right - left + 1);
    if (prev == nullptr) {
      return new_head;
    } else {
      prev->next = new_head;
      return head;
    }
  }
};