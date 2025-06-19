// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序
// 的方式存储的，并且每个节点只能存储 一位 数字。

// 请你将两个数相加，并以相同形式返回一个表示和的链表。

// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

// 示例 1：

// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[7,0,8]
// 解释：342 + 465 = 807.
// 示例 2：

// 输入：l1 = [0], l2 = [0]
// 输出：[0]
// 示例 3：

// 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// 输出：[8,9,9,9,0,0,0,1]
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
  ListNode *addTwoNumbers_(ListNode *l1, ListNode *l2, bool plus) {
    if (l1 == nullptr && l2 == nullptr) {
      if (plus) {
        return new ListNode(1);
      } else {
        return nullptr;
      }
    } else if (l1 == nullptr && l2 != nullptr) {
      return addTwoNumbers_(l2, l1, plus);
    } else if (l1 != nullptr && l2 == nullptr) {
      if (plus) {
        l1->val += 1;
        if (l1->val >= 10) {
          l1->val -= 10;
          l1->next = addTwoNumbers_(l1->next, nullptr, true);
        }
      }
      return l1;
    }
    l1->val += l2->val;
    if (plus) {
      l1->val += 1;
    }
    if (l1->val >= 10) {
      l1->val -= 10;
      l1->next = addTwoNumbers_(l1->next, l2->next, true);
    } else {
      l1->next = addTwoNumbers_(l1->next, l2->next, false);
    }
    return l1;
  }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    return addTwoNumbers_(l1, l2, false);
  }
};