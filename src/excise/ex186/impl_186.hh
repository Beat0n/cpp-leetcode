// 给你一个字符数组 s ，反转其中 单词 的顺序。

// 单词 的定义为：单词是一个由非空格字符组成的序列。s
// 中的单词将会由单个空格分隔。

// 必须设计并实现 原地 解法来解决此问题，即不分配额外的空间。

// 示例 1：

// 输入：s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
// 输出：["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
// 示例 2：

// 输入：s = ["a"]
// 输出：["a"]
#include "../common.hh"
#include <utility>

class Solution {
public:
  void reverseWords(vector<char> &s) {
    auto reverse = [&s](int left, int right) {
      while (left < right) {
        swap(s[left], s[right]);
        ++left;
        --right;
      }
    };
    int n = s.size();
    int left = 0;
    int right = 0;
    reverse(0, n - 1);
    while (right < n) {
      while (right < n && s[right] != ' ') {
        ++right;
      }
      reverse(left, right - 1);
      left = right + 1;
      ++right;
    }
  }
};