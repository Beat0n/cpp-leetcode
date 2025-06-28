// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序
// 返回答案。

// 示例 1：

// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 示例 2：

// 输入：nums = [0,1]
// 输出：[[0,1],[1,0]]
// 示例 3：

// 输入：nums = [1]
// 输出：[[1]]
#include "../common.hh"

class Solution {
private:
  vector<bool> used;
  vector<int> cur;
  vector<vector<int>> ans;

  void dfs(vector<int> &nums) {
    int n = nums.size();

    if (cur.size() == n) {
      ans.push_back(cur);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        used[i] = true;
        cur.push_back(nums[i]);
        dfs(nums);
        cur.pop_back();
        used[i] = false;
      }
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums) {
    int n = nums.size();
    used.resize(n, false);
    dfs(nums);
    return ans;
  }
};