#include "impl_133.hh"

int main() {
  auto node1 = new Node(1);
  auto node2 = new Node(2);
  auto node3 = new Node(3);
  auto node4 = new Node(4);
  node1->neighbors.push_back(node2);
  node1->neighbors.push_back(node4);
  node2->neighbors.push_back(node1);
  node2->neighbors.push_back(node3);
  node3->neighbors.push_back(node2);
  node3->neighbors.push_back(node4);
  node4->neighbors.push_back(node1);
  node4->neighbors.push_back(node3);
  Solution().cloneGraph(node1);
}