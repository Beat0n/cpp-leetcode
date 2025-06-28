// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

// 示例 1：

// 输入：nums = [1,1,2]
// 输出：
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
// 示例 2：

// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
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
      if (used[i] || (i > 0 && !used[i - 1] && nums[i] == nums[i - 1])) {
        continue;
      }
      used[i] = true;
      cur.push_back(nums[i]);
      dfs(nums);
      cur.pop_back();
      used[i] = false;
    }
  }

public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    int n = nums.size();
    used.resize(n, false);
    sort(nums.begin(), nums.end());
    dfs(nums);
    return ans;
  }
};
