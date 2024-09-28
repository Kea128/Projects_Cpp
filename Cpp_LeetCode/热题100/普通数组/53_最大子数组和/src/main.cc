#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * @brief 53 最大子数组和
 * https://leetcode.cn/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-100-liked
 */

int maxSubArray(std::vector<int>& nums) {
  // 动态规划
  std::vector<int> dp(nums.size(), 0);
  // dp[i]表示以nums[i]结尾的最大子数组和（num[left - i]）
  // dp初始化
  dp[0] = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    dp[i] = dp[i - 1] < 0 ? nums[i] : dp[i - 1] + nums[i];
  }
  int max = dp[0];
  for (auto& ele : dp) {
    // std::cout << ele << " ";
    max = std::max(max, ele);
  }
  // std::cout << std::endl;
  return max;
}

int main() {
  int n;
  std::vector<int> nums;
  while (std::cin >> n) {
    nums.emplace_back(n);
  }
  std::cout << maxSubArray(nums) << std::endl;
}