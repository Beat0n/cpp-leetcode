// 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序
// ，返回矩阵中的所有元素。
#include "../common.hh"

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans;
    int left = 0, right = n - 1;
    int top = 0, bottom = m - 1;
    while (true) {
      for (int i = left; i <= right; ++i) {
        ans.push_back(matrix[top][i]);
      }
      ++top;
      if (top > bottom) {
        break;
      }
      for (int i = top; i <= bottom; ++i) {
        ans.push_back(matrix[i][right]);
      }
      --right;
      if (left > right) {
        break;
      }
      for (int i = right; i >= left; --i) {
        ans.push_back(matrix[bottom][i]);
      }
      --bottom;
      if (top > bottom) {
        break;
      }
      for (int i = bottom; i >= top; --i) {
        ans.push_back(matrix[i][left]);
      }
      ++left;
      if (left > right) {
        break;
      }
    }
    return ans;
  }
};