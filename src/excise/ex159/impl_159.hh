// 给你一个字符串 s ，请你找出 至多 包含 两个不同字符
// 的最长子串，并返回该子串的长度。

// 示例 1：

// 输入：s = "eceba"
// 输出：3
// 解释：满足题目要求的子串是 "ece" ，长度为 3 。
// 示例 2：

// 输入：s = "ccaabbb"
// 输出：5
// 解释：满足题目要求的子串是 "aabbb" ，长度为 5 。
#include "../common.hh"
#include <unordered_map>

class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int> map;
    int left = 0;
    int ans = 0;
    for (int right = 0; right < s.size(); ++right) {
      map[s[right]]++;
      while (map.size() > 2) {
        char ch = s[left];
        map[ch]--;
        if (map[ch] == 0) {
          map.erase(ch);
        }
        left++;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};