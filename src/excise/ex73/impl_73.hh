// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0
// 。请使用 原地 算法。
#include "../common.hh"

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    vector<bool> rows(matrix.size(), false);
    vector<bool> cols(matrix[0].size(), false);
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == 0) {
          cols[j] = true;
          rows[i] = true;
        }
      }
    }
    for (int i = 0; i < matrix.size(); i++) {
      if (rows[i]) {
        for (int j = 0; j < matrix[0].size(); j++) {
          matrix[i][j] = 0;
        }
      }
    }

    for (int j = 0; j < matrix[0].size(); j++) {
      if (cols[j]) {
        for (int i = 0; i < matrix.size(); i++) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};