// 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

// 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要
// 使用另一个矩阵来旋转图像。
#include "../common.hh"
#include <algorithm>
#include <utility>

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    reverse(matrix.begin(), matrix.end());
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < i; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};