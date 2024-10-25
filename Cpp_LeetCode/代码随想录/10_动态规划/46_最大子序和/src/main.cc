#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief 53_最大子数组和
 * https://leetcode.cn/problems/maximum-subarray/description/
 */

int maxSubArray(vector<int>& nums) {
  std::vector<int> dp(nums.size(), 0);
  dp[0] = nums[0];

  int res = dp[0];
  for (int i = 1; i < nums.size(); i++) {
    dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
    res = std::max(dp[i], res);
  }
  return res;
}

int main(int argc, char const* argv[]) {
  std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::cout << maxSubArray(nums) << std::endl;
  return 0;
}
