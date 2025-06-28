
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按
// 任意顺序 返回。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
#include "../common.hh"

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.empty())
      return ans;
    unordered_map<char, string> map;
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";
    for (char ch : digits) {
      string str = map[ch];
      if (ans.empty()) {
        for (char ch2 : str) {
          ans.push_back(string(1, ch2));
        }
      } else {
        int n = ans.size();
        vector<string> tmp;
        for (int i = 0; i < n; ++i) {
          for (char ch2 : str) {
            ans[i].push_back(ch2);
            tmp.push_back(ans[i]);
            ans[i].pop_back();
          }
        }
        ans.swap(tmp);
      }
    }
    return ans;
  }
};