
#include "../common.hh"
#include <string>
#include <vector>

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int row = 0;
        bool down_flag = true;
        vector<string> vec(numRows, "");
        for (char ch : s) {
            if (row == 0) {
                down_flag = true;
            }
            if (row == numRows - 1) {
                down_flag = false;
            }
            vec[row].push_back(ch);
            if (down_flag) {
                row += 1;
            } else {
                row -= 1;
            }
        }
        string ans = "";
        for (const string& s : vec) {
            ans.append(s);
        }
        return ans;
    }
};