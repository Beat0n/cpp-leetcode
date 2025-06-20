
#include "../common.hh"

class Solution {
public:
  int reverse(int x) {
    if (x == INT32_MIN) {
      return 0;
    }
    if (x < 0) {
      return -reverse(-x);
    }
    int ans = 0;
    while (x > 0) {
      int m = x % 10;
      x = (x - m) / 10;
      if (ans > (INT32_MAX - m) / 10) {
        return 0;
      }
      ans = ans * 10 + m;
    }
    return ans;
  }
};