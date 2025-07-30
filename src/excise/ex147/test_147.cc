#include "impl_147.hh"

int main() {
  Solution s;
  ListNode* head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3, new ListNode))));
  head = s.insertionSortList(head);
  while (head != nullptr) {
    std::cout << head->val << std::endl;
    head = head->next;
  }
}