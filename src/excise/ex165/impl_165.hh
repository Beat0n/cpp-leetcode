// 给你两个 版本号字符串 version1 和 version2 ，请你比较它们。版本号由被点 '.'
// 分开的修订号组成。修订号的值 是它 转换为整数 并忽略前导零。

// 比较版本号时，请按 从左到右的顺序
// 依次比较它们的修订号。如果其中一个版本字符串的修订号较少，则将缺失的修订号视为
// 0。

// 返回规则如下：

// 如果 version1 < version2 返回 -1，
// 如果 version1 > version2 返回 1，
// 除此之外返回 0。
#include "../common.hh"

class Solution {
public:
  int compareVersion(string version1, string version2) {
    int n1 = version1.size();
    int n2 = version2.size();
    int i = 0, j = 0;
    unsigned long long num1 = 0, num2 = 0;
    function<int()> dfs = [&]() {
      if (i >= n1 && j >= n2) {
        return 0;
      }
      while (i < n1 && version1[i] == '0') {
        ++i;
      }
      while (i < n1 && version1[i] != '.') {
        num1 = num1 * 10 + version1[i] - '0';
        ++i;
      }
      while (j < n2 && version2[j] == '0') {
        ++j;
      }
      while (j < n2 && version2[j] != '.') {
        num2 = num2 * 10 + version2[j] - '0';
        ++j;
      }
      if (num1 < num2) {
        return -1;
      } else if (num1 > num2) {
        return 1;
      } else {
        ++i;
        ++j;
        num1 = 0;
        num2 = 0;
        return dfs();
      }
    };
    return dfs();
  }
};