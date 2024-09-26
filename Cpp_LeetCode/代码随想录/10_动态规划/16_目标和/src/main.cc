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

  if () }

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
