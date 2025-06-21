// 请设计一个类，使该类的构造函数能够接收一个字符串数组。然后再实现一个方法，该方法能够分别接收两个单词，并返回列表中这两个单词之间的最短距离。

// 实现 WordDistanc 类:

// WordDistance(String[] wordsDict) 用字符串数组 wordsDict 初始化对象。
// int shortest(String word1, String word2) 返回数组 worddict 中 word1 和 word2
// 之间的最短距离。

// 示例 1:

// 输入:
// ["WordDistance", "shortest", "shortest"]
// [[["practice", "makes", "perfect", "coding", "makes"]], ["coding",
// "practice"], ["makes", "coding"]] 输出: [null, 3, 1]

// 解释：
// WordDistance wordDistance = new WordDistance(["practice", "makes", "perfect",
// "coding", "makes"]); wordDistance.shortest("coding", "practice"); // 返回 3
// wordDistance.shortest("makes", "coding");    // 返回 1

// 注意:

// 1 <= wordsDict.length <= 3 * 104
// 1 <= wordsDict[i].length <= 10
// wordsDict[i] 由小写英文字母组成
// word1 和 word2 在数组 wordsDict 中
// word1 != word2
//  shortest 操作次数不大于 5000

#include "../common.hh"
#include <cstdint>
#include <unordered_map>

class WordDistance {
private:
  unordered_map<string, vector<int>> wordsPos_;

public:
  WordDistance(vector<string> &wordsDict) {
    wordsPos_.clear();
    int n = wordsDict.size();
    for (int i = 0; i < n; ++i) {
      wordsPos_[wordsDict[i]].push_back(i);
    }
  }

  int shortest(string word1, string word2) {
    const auto &pos1 = wordsPos_[word1];
    const auto &pos2 = wordsPos_[word2];
    int n1 = pos1.size();
    int n2 = pos2.size();
    int i = 0, j = 0;
    int ans = INT32_MAX;
    while (i < n1 && j < n2) {
      if (pos1[i] < pos2[j]) {
        while (i + 1 < n1 && pos1[i + 1] < pos2[j]) {
          ++i;
        }
        ans = min(ans, pos2[j] - pos1[i]);
        ++i;
      } else {
        while (j + 1 < n2 && pos2[j + 1] < pos1[i]) {
          ++j;
        }
        ans = min(ans, pos1[i] - pos2[j]);
        ++j;
      }
    }
    while (i < n1 && j < n2) {
      ans = min(ans, abs(pos1[i] - pos2[j]));
      ++i;
    }
    while (i < n1 && j < n2) {
      ans = min(ans, abs(pos1[i] - pos2[j]));
      ++j;
    }
    return ans;
  }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */