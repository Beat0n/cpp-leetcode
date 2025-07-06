// 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
#include "../common.hh"

class Solution {
 private:
  vector<vector<string>> ans;
  vector<vector<bool>> left;
  vector<string> grid;
  int n;

  void helper(int row) {
    if (row == n) {
      ans.push_back(grid);
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (left[row][col]) {
        auto tmp = left;
        grid[row][col] = 'Q';
        set_left(row, col);
        helper(row + 1);
        grid[row][col] = '.';
        left = tmp;
      }
    }
  }

  void set_left(int x, int y) {
    for (int i = 0; i < n; ++i) {
      left[x][i] = false;
    }
    for (int i = 0; i < n; ++i) {
      left[i][y] = false;
    }
    for (int i = 1; i < n; ++i) {
      if (x + i >= n || y + i >= n) break;
      left[x + i][y + i] = false;
    }
    for (int i = 1; i < n; ++i) {
      if (x - i >= n || y - i >= n) break;
      left[x - i][y - i] = false;
    }
  }

 public:
  vector<vector<string>> solveNQueens(int n) {
    this->n = n;
    left = vector<vector<bool>>(n, vector<bool>(n, true));
    grid = vector<string>(n, string(n, '.'));
    helper(0);
    return ans;
  }
};