// 给定两个字符串 s 和 t ，如果它们的编辑距离为 1 ，则返回 true ，否则返回 false
// 。

// 字符串 s 和字符串 t 之间满足编辑距离等于 1 有三种可能的情形：

// 往 s 中插入 恰好一个 字符得到 t
// 从 s 中删除 恰好一个 字符得到 t
// 在 s 中用 一个不同的字符 替换 恰好一个 字符得到 t

// 示例 1：

// 输入: s = "ab", t = "acb"
// 输出: true
// 解释: 可以将 'c' 插入字符串 s 来得到 t。
// 示例 2:

// 输入: s = "cab", t = "ad"
// 输出: false
// 解释: 无法通过 1 步操作使 s 变为 t。
#include "../common.hh"

class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    int ns = s.size();
    int nt = t.size();
    if (abs(ns - nt) > 1) {
      return false;
    }
    if (ns > nt) {
      return isOneEditDistance(t, s);
    }
    int i = 0;
    while (i < ns && s[i] == t[i]) {
      ++i;
    }
    if (i == ns) {
      return false;
    }
    if (ns == nt) {
      ++i;
      while (i < ns && s[i] == t[i]) {
        ++i;
      }
      return i == ns;
    }
    int j = i + 1;
    while (i < ns && s[i] == t[j]) {
      ++i;
      ++j;
    }
    return i == ns;
  }
};