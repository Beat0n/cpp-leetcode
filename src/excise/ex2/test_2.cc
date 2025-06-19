#include "impl_2.hh"

int main() {
    auto l1 = new ListNode(1);
    l1->next = new ListNode(8);
    auto l2 = new ListNode(0);
    Solution().addTwoNumbers(l1, l2);
}