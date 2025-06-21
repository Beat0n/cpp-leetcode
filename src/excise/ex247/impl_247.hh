// 给定一个整数 n ，返回所有长度为 n 的 中心对称数 。你可以以 任何顺序
// 返回答案。

// 中心对称数 是一个数字在旋转了 180
// 度之后看起来依旧相同的数字（或者上下颠倒地看）。

// 示例 1:

// 输入：n = 2
// 输出：["11","69","88","96"]
// 示例 2:

// 输入：n = 1
// 输出：["0","1","8"]

#include "../common.hh"

class Solution {
public:
  vector<string> findStrobogrammatic(int n) {
    vector<string> ans;
    function<void(int, int, string)> dfs = [&](int left, int right,
                                               string cur) {
      if (left == right) {
        cur[left] = '0';
        ans.push_back(cur);
        cur[left] = '1';
        ans.push_back(cur);
        cur[left] = '8';
        ans.push_back(cur);
        return;
      }
      if (left > right) {
        ans.push_back(cur);
        return;
      }
      if (left != 0) {
        cur[left] = '0';
        cur[right] = '0';
        dfs(left + 1, right - 1, cur);
      }
      cur[left] = '1';
      cur[right] = '1';
      dfs(left + 1, right - 1, cur);

      cur[left] = '6';
      cur[right] = '9';
      dfs(left + 1, right - 1, cur);

      cur[left] = '8';
      cur[right] = '8';
      dfs(left + 1, right - 1, cur);

      cur[left] = '9';
      cur[right] = '6';
      dfs(left + 1, right - 1, cur);
    };
    dfs(0, n - 1, string(n, ' '));
    return ans;
  }
};