// 给你一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间
// intervals[i] = [starti, endi] ，返回 所需会议室的最小数量 。

// 示例 1：

// 输入：intervals = [[0,30],[5,10],[15,20]]
// 输出：2
// 示例 2：

// 输入：intervals = [[7,10],[2,4]]
// 输出：1

#include "../common.hh"
#include <cstdint>

class Solution {
public:
  int minMeetingRooms(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &lhs, const vector<int> &rhs) {
           if (lhs[0] == rhs[0]) {
             return lhs[1] < rhs[1];
           }
           return lhs[0] < rhs[0];
         });
    int ans = 1;
    int start = intervals[0][1];
    int end = INT32_MAX;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][1] <= start) {
        
      } else if (intervals[i])
    }
    return ans;
  }
};