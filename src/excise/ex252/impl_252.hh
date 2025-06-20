// 给定一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间
// intervals[i] = [starti, endi] ，请你判断一个人是否能够参加这里面的全部会议。

// 示例 1：

// 输入：intervals = [[0,30],[5,10],[15,20]]
// 输出：false
// 示例 2：

// 输入：intervals = [[7,10],[2,4]]
// 输出：true

#include "../common.hh"

class Solution {
public:
  bool canAttendMeetings(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &lhs, const vector<int> &rhs) {
           if (lhs[0] == rhs[0]) {
             return lhs[1] < rhs[1];
           }
           return lhs[0] < rhs[0];
         });
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] < intervals[i - 1][1]) {
        return false;
      }
    }
    return true;
  }
};