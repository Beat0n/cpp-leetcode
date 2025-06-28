// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti,
// endi] 。请你合并所有重叠的区间，并返回
// 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

// 示例 1：

// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2：

// 输入：intervals = [[1,4],[4,5]]
// 输出：[[1,5]]
// 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。

#include "../common.hh"

class Solution {
private:
  static bool cmp(const vector<int> &l, const vector<int> &r) {
    if (l[0] == r[0])
      return l[1] < r[1];
    return l[0] < r[0];
  }

public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    vector<vector<int>> ans{intervals[0]};
    for (int i = 1; i < intervals.size(); ++i) {
      int sz = ans.size();
      if (intervals[i][0] <= ans[sz - 1][1]) {
        ans[sz - 1][1] = max(ans[sz - 1][1], intervals[i][1]);
      } else {
        ans.push_back(intervals[i]);
      }
      //   auto &back = ans.back();
      //   if (intervals[i][0] <= back[1]) {
      //     back[1] = max(back[1], intervals[i][1]);
      //   } else {
      //     ans.push_back(intervals[i]);
      //   }
    }
    return ans;
  }
};