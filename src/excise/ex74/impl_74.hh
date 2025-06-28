// 给你一个满足下述两条属性的 m x n 整数矩阵：

// 每行中的整数从左到右按非严格递增顺序排列。
// 每行的第一个整数大于前一行的最后一个整数。
// 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
#include "../common.hh"

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0, right = m * n - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      int x = mid / n;
      int y = mid - x * n;
      if (matrix[x][y] == target) {
        return true;
      } else if (matrix[x][y] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
};