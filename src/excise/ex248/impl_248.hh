// 给定两个字符串 low 和 high 表示两个整数 low 和 high ，其中 low <= high ，返回
// 范围 [low, high] 内的 「中心对称数」总数  。

// 中心对称数 是一个数字在旋转了 180
// 度之后看起来依旧相同的数字（或者上下颠倒地看）。

// 示例 1:

// 输入: low = "50", high = "100"
// 输出: 3
// 示例 2:

// 输入: low = "0", high = "0"
// 输出: 1

// 提示:

// 1 <= low.length, high.length <= 15
// low 和 high 只包含数字
// low <= high
// low and high 不包含任何前导零，除了零本身。
#include "../common.hh"

class Solution {
public:
  int strobogrammaticInRange(string low, string high) {
    int low_num = stoi(low);
    int high_num = stoi(high);
    int ans = 0;
    int n = high.size();
    function<void(int, int, string)> dfs = [&](int left, int right,
                                               string cur) {
      int num;
      if (left == right) {
        cur[left] = '0';
        num = stoi(cur);
        if (num >= low_num && num <= high_num) {
          ++ans;
        }
        if (num > high_num) {
          return;
        }
        cur[left] = '1';
        num = stoi(cur);
        if (num >= low_num && num <= high_num) {
          ++ans;
        }
        if (num > high_num) {
          return;
        }
        cur[left] = '8';
        num = stoi(cur);
        if (num >= low_num && num <= high_num) {
          ++ans;
        }
        if (num > high_num) {
          return;
        }
        return;
      }
      if (left > right) {
        return;
      }
      if (left != 0) {
        cur[left] = '0';
        cur[right] = '0';
        num = stoi(cur.substr(0, left + 1) + cur.substr(right, n - right));
        if (num >= low_num && num <= high_num) {
          ++ans;
        }
        if (num > high_num) {
          return;
        }
        dfs(left + 1, right - 1, cur);
      }
      cur[left] = '1';
      cur[right] = '1';
      num = stoi(cur.substr(0, left + 1) + cur.substr(right, n - right));
      if (num >= low_num && num <= high_num) {
        ++ans;
      }
      if (num > high_num) {
        return;
      }
      dfs(left + 1, right - 1, cur);

      cur[left] = '6';
      cur[right] = '9';
      num = stoi(cur.substr(0, left + 1) + cur.substr(right, n - right));
      if (num >= low_num && num <= high_num) {
        ++ans;
      }
      if (num > high_num) {
        return;
      }
      dfs(left + 1, right - 1, cur);

      cur[left] = '8';
      cur[right] = '8';
      num = stoi(cur.substr(0, left + 1) + cur.substr(right, n - right));
      if (num >= low_num && num <= high_num) {
        ++ans;
      }
      if (num > high_num) {
        return;
      }
      dfs(left + 1, right - 1, cur);

      cur[left] = '9';
      cur[right] = '6';
      num = stoi(cur.substr(0, left + 1) + cur.substr(right, n - right));
      if (num >= low_num && num <= high_num) {
        ++ans;
      }
      if (num > high_num) {
        return;
      }
      dfs(left + 1, right - 1, cur);
    };
    dfs(0, n - 1, string(n, ' '));
    if (low_num < 10 && high_num >= 10) {
      dfs(0, 0, string(1, ' '));
    }
    return ans;
  }
};