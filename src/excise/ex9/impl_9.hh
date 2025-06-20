// 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

// 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

// 例如，121 是回文，而 123 不是。

// 示例 1：

// 输入：x = 121
// 输出：true
// 示例 2：

// 输入：x = -121
// 输出：false
// 解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
// 示例 3：

// 输入：x = 10
// 输出：false
// 解释：从右向左读, 为 01 。因此它不是一个回文数。
#include "../common.hh"
#include <vector>

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    if (x == 0) {
      return true;
    }
    vector<int> nums;
    while (x > 0) {
      nums.push_back(x % 10);
      x /= 10;
    }
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      if (nums[left] != nums[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
};