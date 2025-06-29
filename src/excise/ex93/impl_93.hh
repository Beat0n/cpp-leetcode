// 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
// 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s
// 中的任何数字。你可以按 任何 顺序返回答案。

// 示例 1：

// 输入：s = "25525511135"
// 输出：["255.255.11.135","255.255.111.35"]
// 示例 2：

// 输入：s = "0000"
// 输出：["0.0.0.0"]
// 示例 3：

// 输入：s = "101023"
// 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
#include "../common.hh"

class Solution {
 private:
  vector<string> ans;
  vector<int> nums;

 public:
  vector<string> restoreIpAddresses(string s) {
    int n = s.size();
    auto dfs = [&](auto self, int pos) {
      if (pos == n || nums.size() == 4) {
        if (pos == n && nums.size() == 4) {
          string tmp = to_string(nums[0]);
          tmp.push_back('.');
          tmp.append(to_string(nums[1]));
          tmp.push_back('.');
          tmp.append(to_string(nums[2]));
          tmp.push_back('.');
          tmp.append(to_string(nums[3]));
          ans.emplace_back(tmp);
        }
        return;
      }
      int num = 0;
      // 1
      num = num * 10 + s[pos] - '0';
      ++pos;
      nums.push_back(num);
      self(self, pos);
      nums.pop_back();
      if (num == 0) {
        return;
      }
      // 2
      if (pos == n) {
        return;
      }
      num = num * 10 + s[pos] - '0';
      ++pos;
      nums.push_back(num);
      self(self, pos);
      nums.pop_back();
      // 3
      if (pos == n) {
        return;
      }
      num = num * 10 + s[pos] - '0';
      if (num > 255) return;
      ++pos;
      nums.push_back(num);
      self(self, pos);
      nums.pop_back();
    };
    dfs(dfs, 0);
    return ans;
  }
};