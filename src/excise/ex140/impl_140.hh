// 给定一个字符串 s 和一个字符串字典 wordDict ，在字符串 s 中增加空格来构建一个句子，使得句子中所有的单词都在词典中。以任意顺序
// 返回所有这些可能的句子。

// 注意：词典中的同一个单词可能在分段中被重复使用多次。

// 示例 1：

// 输入:s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// 输出:["cats and dog","cat sand dog"]
// 示例 2：

// 输入:s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// 输出:["pine apple pen apple","pineapple pen apple","pine applepen apple"]
// 解释: 注意你可以重复使用字典中的单词。
// 示例 3：

// 输入:s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// 输出:[]
#include <functional>
#include <string>
#include <vector>

#include "../common.hh"

class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet;
    for (const auto& str : wordDict) {
      wordSet.insert(str);
    }
    int n = s.size();
    vector<string> ans;
    string cur;
    function<void(int, int)> dfs = [&](int start, int pos) {
      if (start == n && pos == n) {
        ans.push_back(cur);
        return;
      }
      for (int i = pos; i < n; ++i) {
        auto str = s.substr(start, i - start + 1);
        auto tmp = cur;
        if (wordSet.find(str) != wordSet.end()) {
          if (!cur.empty()) {
            cur.push_back(' ');
          }
          cur.append(str);
          dfs(i + 1, i + 1);
          cur.swap(tmp);
        }
      }
    };
    dfs(0, 0);
    return ans;
  }
};