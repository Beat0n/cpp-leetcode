// 给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中
// intervals[i] = [starti, endi] 表示第 i 个区间的开始和结束，并且 intervals
// 按照 starti 升序排列。同样给定一个区间 newInterval = [start, end]
// 表示另一个区间的开始和结束。

// 在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti
// 升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。

// 返回插入之后的 intervals。

// 注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。

// 示例 1：

// 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
// 输出：[[1,5],[6,9]]
// 示例 2：

// 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// 输出：[[1,2],[3,10],[12,16]]
// 解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
#include "../common.hh"

class Solution {
private:
  static bool cmp(const vector<int> &lhs, const vector<int> &rhs) {
    if (lhs[0] == rhs[0])
      return lhs[1] < rhs[1];
    return lhs[0] < rhs[0];
  }

public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    if (intervals.empty()) {
      return {newInterval};
    }
    sort(intervals.begin(), intervals.end(), cmp);
    vector<vector<int>> ans;
    if (newInterval[1] < intervals[0][0]) {
      ans.push_back(newInterval);
      ans.insert(ans.end(), intervals.begin(), intervals.end());
      return ans;
    } else if (newInterval[0] > intervals.back()[1]) {
      ans = intervals;
      ans.push_back(newInterval);
      return ans;
    } else {
      int i = 0;
      int n = intervals.size();
      while (intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        i++;
      }
      int begin = newInterval[0];
      int end = newInterval[1];
      while (i < n && newInterval[1] >= intervals[i][0]) {
        begin = min(begin, intervals[i][0]);
        end = max(end, intervals[i][1]);
        ++i;
      }
      ans.push_back({begin, end});
      while (i < n) {
        ans.push_back(intervals[i]);
        i++;
      }
      return ans;
    }
  }
};