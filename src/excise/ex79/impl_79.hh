
#include "../common.hh"

class Solution {
private:
  pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
  bool exist(vector<vector<char>> &board, string word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    auto check = [&](int x, int y, int pos) {
      return x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] &&
             board[x][y] == word[pos];
    };
    function<bool(int, int, int)> dfs = [&](int x, int y, int pos) {
      if (pos == word.size() - 1) {
        return true;
      }
      visited[x][y] = true;
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dir[i].first;
        int y2 = y + dir[i].second;
        if (check(x2, y2, pos + 1)) {
          if (dfs(x2, y2, pos + 1)) {
            return true;
          }
        }
      }
      visited[x][y] = false;
      return false;
    };
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (check(i, j, 0)) {
          if (dfs(i, j, 0)) {
            return true;
          }
        }
      }
    }
    return false;
  }
};