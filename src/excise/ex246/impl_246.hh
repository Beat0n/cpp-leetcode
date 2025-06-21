// 中心对称数是指一个数字在旋转了 180
// 度之后看起来依旧相同的数字（或者上下颠倒地看）。

// 请写一个函数来判断该数字是否是中心对称数，其输入将会以一个字符串的形式来表达数字。

// 示例 1:

// 输入: num = "69"
// 输出: true
// 示例 2:

// 输入: num = "88"
// 输出: true
// 示例 3:

// 输入: num = "962"
// 输出: false
// 示例 4：

// 输入：num = "1"
// 输出：true
#include "../common.hh"

// 0 <-> 0
// 1 <-> 1
// 6 <-> 9
// 8 <-> 8
class Solution {
public:
  bool isStrobogrammatic(string num) {
    int left = 0;
    int right = num.size() - 1;
    while (left <= right) {
      if (num[left] == '0') {
        if (num[right] != '0') {
          return false;
        }
      } else if (num[left] == '1') {
        if (num[right] != '1') {
          return false;
        }
      } else if (num[left] == '6') {
        if (num[right] != '9') {
          return false;
        }
      } else if (num[left] == '8') {
        if (num[right] != '8') {
          return false;
        }
      } else if (num[left] == '9') {
        if (num[right] != '6') {
          return false;
        }
      } else {
        return false;
      }
      ++left;
      --right;
    }
    return true;
  }
};