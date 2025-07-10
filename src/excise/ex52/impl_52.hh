// n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。

// 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
#include "../common.hh"

class Solution {
 private:
  int ans = 0;
  vector<int> curr;
  int n;

  void helper(int row) {
    if (row == n) {
      ++ans;
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (check(row, col)) {
        curr.push_back(col);
        helper(row + 1);
        curr.pop_back();
      }
    }
  }

  bool check(int row, int col) {
    for (int i = 0; i < curr.size(); ++i) {
      int j = curr[i];
      if (row == i || col == j || abs(row - i) == abs(col - j)) {
        return false;
      }
    }
    return true;
  }

 public:
  int totalNQueens(int n) {
    this->n = n;
    helper(0);
    return ans;
  }
};