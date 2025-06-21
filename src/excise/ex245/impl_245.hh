// 给定一个字符串数组 wordsDict 和两个字符串 word1 和 word2
// ，返回这两个单词在列表中出现的最短距离。

// 注意：word1 和 word2 是有可能相同的，并且它们将分别表示为列表中
// 两个独立的单词 。

// 示例 1：

// 输入：wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1
// = "makes", word2 = "coding" 输出：1 示例 2：

// 输入：wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1
// = "makes", word2 = "makes" 输出：3
#include "../common.hh"

class Solution {
private:
  int shortestDiffrentWordDistance(vector<string> &wordsDict, string word1,
                                   string word2) {
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
  int shortestSameWordDistance(vector<string> &wordsDict, string word) {
    int pos = -1;
    int n = wordsDict.size();
    int ans = n;
    for (int i = 0; i < n; ++i) {
      if (wordsDict[i] == word) {
        if (pos != -1) {
          ans = min(ans, i - pos);
        }
        pos = i;
      }
    }
    return ans;
  }

public:
  int shortestWordDistance(vector<string> &wordsDict, string word1,
                           string word2) {
    if (word1 != word2) {
      return shortestDiffrentWordDistance(wordsDict, word1, word2);
    } else {
      return shortestSameWordDistance(wordsDict, word1);
    }
  }
};