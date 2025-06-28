// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 每个右括号都有一个对应的相同类型的左括号。
 

// 示例 1：

// 输入：s = "()"

// 输出：true

// 示例 2：

// 输入：s = "()[]{}"

// 输出：true

// 示例 3：

// 输入：s = "(]"

// 输出：false
#include "../common.hh"

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        st.push(s[i]);
      } else {
        if (st.empty())
          return false;
        if (s[i] == ')') {
          if (st.top() == '(') {
            st.pop();
          } else
            return false;
        } else if (s[i] == '}') {
          if (st.top() == '{') {
            st.pop();
          } else
            return false;
        } else if (s[i] == ']') {
          if (st.top() == '[') {
            st.pop();
          } else
            return false;
        }
      }
    }
    return st.empty();
  }
};