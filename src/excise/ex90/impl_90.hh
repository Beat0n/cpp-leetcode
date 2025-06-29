// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。

// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

// 示例 1：

// 输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 示例 2：

// 输入：nums = [0]
// 输出：[[],[0]]

#include <functional>
#include <vector>

#include "../common.hh"

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> cur;
    int n = nums.size();
    vector<bool> used(n, false);
    function<void(int)> dfs = [&](int pos) {
      ans.push_back(cur);
      for (int i = pos; i < n; ++i) {
        if (i > 0 && !used[i - 1] && nums[i - 1] == nums[i]) {
          continue;
        }
        if (!used[i]) {
          used[i] = true;
          cur.push_back(nums[i]);
          dfs(i + 1);
          cur.pop_back();
          used[i] = false;
        }
      }
    };
    dfs(0);
    return ans;
  }
};