// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且
// 有效的 括号组合。

// 示例 1：

// 输入：n = 3
// 输出：["((()))","(()())","(())()","()(())","()()()"]
// 示例 2：

// 输入：n = 1
// 输出：["()"]

#include "../common.hh"

class Solution {
private:
  vector<string> ans;

  void dfs(int left, int right, string cur) {
    if (left == 0 && right == 0) {
      ans.push_back(cur);
      return;
    }
    if (left > 0) {
      auto tmp = cur;
      tmp.push_back('(');
      dfs(left - 1, right, tmp);
    }
    if (left < right) {
      auto tmp = cur;
      tmp.push_back(')');
      dfs(left, right - 1, tmp);
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    dfs(n, n, "");
    return ans;
  }
};
