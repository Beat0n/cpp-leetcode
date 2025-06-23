
#include "../common.hh"

class Solution {
public:
  int countCornerRectangles(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int x1 = 0; x1 < m; ++x1) {
      for (int y1 = 0; y1 < n; ++y1) {
        if (grid[x1][y1] == 1) {
          for (int x2 = m - 1; x2 > x1; --x2) {
            for (int y2 = n - 1; y2 > y1; --y2) {
              if (grid[x2][y2] == 1) {
                int h = x2 - x1;
                int w = y2 - y1;
                if (grid[x1][y1 + w] == 1 && grid[x1 + h][y1] == 1) {
                  ans += 1;
                }
              }
            }
          }
        }
      }
    }
    return ans;
  }
};