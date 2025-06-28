// 给你一个字符串数组，请你将 字母异位词
// 组合在一起。可以按任意顺序返回结果列表。

// 示例 1:

// 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

// 解释：

// 在 strs 中没有字符串可以通过重新排列来形成 "bat"。
// 字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
// 字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。
// 示例 2:

// 输入: strs = [""]

// 输出: [[""]]

// 示例 3:

// 输入: strs = ["a"]

// 输出: [["a"]]
#include "../common.hh"

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    unordered_map<string, int> map;
    for (const string &str : strs) {
      auto tmp = str;
      sort(tmp.begin(), tmp.end());
      auto pos_iter = map.find(tmp);
      if (pos_iter == map.end()) {
        ans.push_back({str});
        map[tmp] = ans.size() - 1;
      } else {
        ans[pos_iter->second].push_back(str);
      }
    }
    return ans;
  }
};