// 编写一个程序，通过填充空格来解决数独问题。

// 数独的解法需 遵循如下规则：

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
// 数独部分空格内已填入了数字，空白格用 '.' 表示。
#include <vector>

#include "../common.hh"

class Solution {
 private:
  vector<vector<bool>> col = vector<vector<bool>>(9, vector<bool>(10, false));
  vector<vector<bool>> rol = vector<vector<bool>>(9, vector<bool>(10, false));
  vector<vector<bool>> grid = vector<vector<bool>>(9, vector<bool>(10, false));

  int grid_idx(int x, int y) { return (x / 3) * 3 + y / 3; }

  bool helper(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') {
          for (int num = 1; num <= 9; ++num) {
            if (!rol[i][num] && !col[j][num] && !grid[grid_idx(i, j)][num]) {
              board[i][j] = num + '0';
              rol[i][num] = col[j][num] = grid[grid_idx(i, j)][num] = true;
              if (helper(board)) {
                return true;
              } else {
                board[i][j] = '.';
                rol[i][num] = col[j][num] = grid[grid_idx(i, j)][num] = false;
              }
            }
          }
          if (board[i][j] == '.') {
            return false;
          }
        }
      }
    }
    return true;
  }

 public:
  void solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          int num = board[i][j] - '0';
          rol[i][num] = col[j][num] = grid[grid_idx(i, j)][num] = true;
        }
      }
    }
    helper(board);
  }
};