// 给你一个由 '1'（陆地）和
// '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

// 此外，你可以假设该网格的四条边均被水包围。

// 示例 1：

// 输入：grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// 输出：1
// 示例 2：

// 输入：grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// 输出：3

#include "../common.hh"

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    auto check = [&](int x, int y) {
      return x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] &&
             grid[x][y] == '1';
    };
    function<void(int, int)> dfs = [&](int x, int y) {
      visited[x][y] = true;
      if (check(x - 1, y)) {
        dfs(x - 1, y);
      }
      if (check(x + 1, y)) {
        dfs(x + 1, y);
      }
      if (check(x, y - 1)) {
        dfs(x, y - 1);
      }
      if (check(x, y + 1)) {
        dfs(x, y + 1);
      }
    };
    for (int x = 0; x < m; x++) {
      for (int y = 0; y < n; y++) {
        if (!visited[x][y] && grid[x][y] == '1') {
          ans++;
          dfs(x, y);
        }
      }
    }
    return ans;
  }
};