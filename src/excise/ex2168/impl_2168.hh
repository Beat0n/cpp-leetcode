// 给你一个由数字组成的字符串 s，返回 s 中独特子字符串数量，其中的每一个数字出现的频率都相同。
 

// 示例1:

// 输入: s = "1212"
// 输出: 5
// 解释: 符合要求的子串有 "1", "2", "12", "21", "1212".
// 要注意，尽管"12"在s中出现了两次，但在计数的时候只计算一次。
// 示例 2:

// 输入: s = "12321"
// 输出: 9
// 解释: 符合要求的子串有 "1", "2", "3", "12", "23", "32", "21", "123", "321".
#include "../common.hh"

class Solution {
public:
    int equalDigitFrequency(string s) {
        unordered_map<int, int> umap;
        int n = s.size();
        int left = 0;
        int ans = 0;
        for (int right = 0; right < n ; ++right) {

        }
    }
};