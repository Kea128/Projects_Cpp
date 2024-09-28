#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 494_目标和
 * https://leetcode.cn/problems/target-sum/description/
 */

// // 先用回溯
// int result = 0;
// int flag = 0;
// void backtracking(std::vector<int>& nums, int target, int pathSum, int start)
// {
//   if (pathSum < target) return;
//   if (pathSum == target) {
//     result++;
//   }
//   for (int i = start; i < nums.size(); i++) {
//     pathSum -= 2 * nums[i];
//     backtracking(nums, target, pathSum, i + 1);
//     pathSum += 2 * nums[i];
//   }
// }

// int findTargetSumWays(vector<int>& nums, int target) {
//   int sum = 0;
//   for (auto& i : nums) {
//     sum += i;
//   }
//   backtracking(nums, target, sum, 0);
//   return result;
// }

// 动态规划
int findTargetSumWays(vector<int>& nums, int target) {
  int sum = 0;
  for (auto& i : nums) {
    sum += i;
  }
  // left + right = sum;
  // left - right = target;
  // left = (sum + target) / 2;
  if ((sum + target) % 2 != 0) return 0;
  if (std::abs(target) > sum) return 0;
  int left = (sum + target) / 2;
  std::vector<int> dp(left + 1, 0);
  // 初始化dp
  dp[0] = 1;
  for (int i = 0; i < nums.size(); i++) {
    for (int j = left; j >= 0; j--) {
      if (j >= nums[i])
        dp[j] = dp[j] + dp[j - nums[i]];
      else
        dp[j] = dp[j];
    }
  }
  return dp[left];
}

int main(int argc, char const* argv[]) {
  int target;
  std::cin >> target;
  int tmp;
  std::vector<int> nums;
  while (std::cin >> tmp) {
    nums.push_back(tmp);
  }

  std::cout << findTargetSumWays(nums, target) << std::endl;
  return 0;
}
