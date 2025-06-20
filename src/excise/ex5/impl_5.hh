// 给你一个字符串 s，找到 s 中最长的 回文 子串。

// 示例 1：

// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案。
// 示例 2：

// 输入：s = "cbbd"
// 输出："bb"
#include "../common.hh"

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    auto helper = [&](int left, int right) {
      while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
      }
      return right - left - 1;
    };
    int len = 1;
    int pos = 0;
    for (int i = 0; i < n - 1; ++i) {
      int len1 = helper(i, i);
      if (len1 > len) {
        pos = i - len1 / 2;
        len = len1;
      }
      int len2 = helper(i, i + 1);
      if (len2 > len) {
        pos = i + 1 - len2 / 2;
        len = len2;
      }
    }
    return s.substr(pos, len);
  }
};