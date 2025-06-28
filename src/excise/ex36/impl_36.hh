// 请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则
// ，验证已经填入的数字是否有效即可。

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）

// 注意：

// 一个有效的数独（部分已被填充）不一定是可解的。
// 只需要根据以上规则，验证已经填入的数字是否有效即可。
// 空白格用 '.' 表示。

#include "../common.hh"

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    vector<vector<bool>> grid(9, vector<bool>(9, false));
    vector<vector<bool>> col(9, vector<bool>(9, false));
    vector<vector<bool>> row(9, vector<bool>(9, false));
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] != '.') {
          int num = board[i][j] - '1';
          if (col[i][num]) {
            return false;
          }
          col[i][num] = true;
          if (row[j][num]) {
            return false;
          }
          row[j][num] = true;
          if (grid[(i / 3) * 3 + j / 3][num]) {
            return false;
          }
          grid[(i / 3) * 3 + j / 3][num] = true;
        }
      }
    }
    return true;
  }
};