// // 给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。

// // 构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random
// // 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。

// // 例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。

// // 返回复制链表的头节点。

// // 用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

// // val：一个表示 Node.val 的整数。
// // random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
// // 你的代码 只 接受原链表的头节点 head 作为传入参数。
// #include <unordered_map>

// #include "../common.hh"

// // Definition for a Node.
// class Node {
//  public:
//   int val;
//   Node* next;
//   Node* random;

//   Node(int _val) {
//     val = _val;
//     next = NULL;
//     random = NULL;
//   }
// };

// class Solution {
//  public:
//   Node* copyRandomList(Node* head) {
//     if (head == nullptr) return nullptr;
//     unordered_map<Node*, Node*> old2new;
//     auto old_node = head;
//     Node* new_head = new Node(head->val);
//     auto new_node = new_head;
//     old2new[head] = new_head;
//     while (old_node != nullptr) {
//       auto old_next = old_node->next;
//       auto old_random = old_node->random;
//       Node* new_next = nullptr;
//       Node* new_random = nullptr;
//       if (old_next != nullptr) {
//         if (old2new.find(old_next) == nullptr) {
//           new_next = new Node(old_next->val);
//           old2new[old_next] = new_next;
//         } else {
//           new_next = old2new[old_next];
//         }
//       }
//       if (old_random != nullptr) {
//         if (old2new.find(old_random) == nullptr) {
//           new_random = new Node(old_random->val);
//           old2new[old_random] = new_random;
//         } else {
//           new_random = old2new[old_random];
//         }
//       }
//       new_node->next = new_next;
//       new_node->random = new_random;
//       new_node = new_next;
//       old_node = old_node->next;
//     }
//     return new_head;
//   }
// };