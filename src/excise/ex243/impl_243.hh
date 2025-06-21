// 给定一个字符串数组 wordDict 和两个已经存在于该数组中的不同的字符串 word1 和
// word2 。返回列表中这两个单词之间的最短距离。

// 示例 1:

// 输入: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1
// = "coding", word2 = "practice" 输出: 3 示例 2:

// 输入: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1
// = "makes", word2 = "coding" 输出: 1
#include "../common.hh"

class Solution {
public:
  int shortestDistance(vector<string> &wordsDict, string word1, string word2) {
    int pos1 = -1;
    int pos2 = -1;
    int n = wordsDict.size();
    int ans = n;
    for (int i = 0; i < n; ++i) {
      if (wordsDict[i] == word1) {
        pos1 = i;
        if (pos2 != -1) {
          ans = min(ans, pos1 - pos2);
        }
      }
      if (wordsDict[i] == word2) {
        pos2 = i;
        if (pos1 != -1) {
          ans = min(ans, pos2 - pos1);
        }
      }
    }
    return ans;
  }
};