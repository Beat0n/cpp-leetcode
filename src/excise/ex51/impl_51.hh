// 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
#include <vector>

#include "../common.hh"

class Solution {
 private:
  vector<vector<string>> ans;
  vector<int> curr;
  int n;

  void helper(int row) {
    if (row == n) {
      auto grid = vector<string>(n, string(n, '.'));
      for (int i = 0; i < n; ++i) {
        grid[i][curr[i]] = 'Q';
      }
      ans.push_back(grid);
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
  vector<vector<string>> solveNQueens(int n) {
    this->n = n;
    helper(0);
    return ans;
  }
};