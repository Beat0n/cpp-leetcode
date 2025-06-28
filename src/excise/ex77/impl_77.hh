// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

// 你可以按 任何顺序 返回答案。

// 示例 1：

// 输入：n = 4, k = 2
// 输出：
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
// 示例 2：

// 输入：n = 1, k = 1
// 输出：[[1]]
#include "../common.hh"

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    function<void(int, vector<int> &)> dfs = [&](int num, vector<int> &path) {
      if (path.size() == k) {
        ans.push_back(path);
        return;
      }
      for (int i = num; i <= n; i++) {
        path.push_back(i);
        dfs(i + 1, path);
        path.pop_back();
      }
    };
    vector<int> path;
    dfs(1, path);
    return ans;
  }
};