
#include "../common.hh"

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < n; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        int left = j + 1;
        int right = n - 1;
        while (left < right) {
          if (left > j + 1 && nums[left] == nums[left - 1]) {
            ++left;
            continue;
          }
          if (nums[i] + nums[j] ==
              static_cast<int64_t>(target) - (nums[left] + nums[right])) {
            ans.push_back({nums[i], nums[j], nums[left], nums[right]});
            ++left;
          } else if (nums[i] + nums[j] < static_cast<int64_t>(target) -
                                             (nums[left] + nums[right])) {
            left++;
          } else {
            right--;
          }
        }
      }
    }
    return ans;
  }
};