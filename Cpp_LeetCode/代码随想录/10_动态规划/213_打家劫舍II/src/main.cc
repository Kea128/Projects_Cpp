#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 213_打家劫舍II
 * https://leetcode.cn/problems/house-robber-ii/description/
 */

int cal(vector<int>& nums, int start, int end) {
  if (start > end) return 0;
  if (start == end) return nums[start];
  vector<int> dp(nums.size(), 0);
  dp[start] = nums[start];
  dp[start + 1] = max(nums[start], nums[start + 1]);
  for (int i = start + 2; i <= end; i++) {
    dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
  }
  return dp[end];
}

int rob(vector<int>& nums) {
  if (nums.size() == 0) return 0;
  if (nums.size() == 1) return nums[0];

  // 取nums[0]
  int value1 = nums[0] + cal(nums, 2, nums.size() - 2);
  // 不取nums[0]
  int value2 = cal(nums, 1, nums.size() - 1);
  return max(value1, value2);
}

int main(int argc, char const* argv[]) {
  int n;
  std::vector<int> cash;
  while (std::cin >> n) {
    cash.emplace_back(n);
  }
  std::cout << rob(cash) << std::endl;

  return 0;
}
