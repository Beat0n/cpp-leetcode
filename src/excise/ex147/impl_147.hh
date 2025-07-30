// 给定单个链表的头 head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。

// 插入排序 算法的步骤:

// 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
// 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
// 重复直到所有输入数据插入完为止。
// 下面是插入排序算法的一个图形示例。部分排序的列表(黑色)最初只包含列表中的第一个元素。每次迭代时，从输入数据中删除一个元素(红色)，并就地插入已排序的列表中。

// 对链表进行插入排序。
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
 private:
  ListNode* insert(ListNode* head, ListNode* new_node) {
    if (head == nullptr) {
      return new_node;
    }
    auto node = head;
    if (new_node->val <= head->val) {
      new_node->next = head;
      return new_node;
    }
    while (node != nullptr && node->next != nullptr && node->next->val < new_node->val) {
      node = node->next;
    }
    auto next = node->next;
    node->next = new_node;
    new_node->next = next;
    return head;
  }

 public:
  ListNode* insertionSortList(ListNode* head) {
    ListNode* dummy = new ListNode;
    auto node = head;
    while (node != nullptr) {
      auto next = node->next;
      node->next = nullptr;
      dummy->next = insert(dummy->next, node);
      node = next;
    }
    head = dummy->next;
    delete dummy;
    return head;
  }
};