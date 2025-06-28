// 给你一个正整数 n ，生成一个包含 1 到 n2
// 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
#include "../common.hh"

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int left = 0, right = n - 1;
    int top = 0, bottom = n - 1;
    int num = 1;
    while (true) {
      for (int i = left; i <= right; ++i) {
        ans[top][i] = num;
        ++num;
      }
      ++top;
      if (top > bottom) {
        break;
      }
      for (int i = top; i <= bottom; ++i) {
        ans[i][right] = num;
        ++num;
      }
      --right;
      if (left > right) {
        break;
      }
      for (int i = right; i >= left; --i) {
        ans[bottom][i] = num;
        ++num;
      }
      --bottom;
      if (top > bottom) {
        break;
      }
      for (int i = bottom; i >= top; --i) {
        ans[i][left] = num;
        ++num;
      }
      ++left;
      if (left > right) {
        break;
      }
    }
    return ans;
  }
};