// 编写一个函数来查找字符串数组中的最长公共前缀。

// 如果不存在公共前缀，返回空字符串 ""。

// 示例 1：

// 输入：strs = ["flower","flow","flight"]
// 输出："fl"
// 示例 2：

// 输入：strs = ["dog","racecar","car"]
// 输出：""
// 解释：输入不存在公共前缀。
#include "../common.hh"

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    int len = strs[0].size();
    for (int i = 1; i < strs.size(); ++i) {
      int j = 0;
      while (j < strs[i].size() && j < len && strs[i][j] == strs[0][j]) {
        ++j;
      }
      len = j;
    }
    return strs[0].substr(0, len);
  }
};