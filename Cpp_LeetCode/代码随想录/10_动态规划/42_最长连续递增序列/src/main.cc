#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief 674_最长连续递增序列
 * https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/
 */

int findLengthOfLCIS(vector<int>& nums) {
  // dp定义为以nums[i]结尾的最长连续递增子序列的长度
  std::vector<int> dp(nums.size(), 1);

  for (int i = 1; i < nums.size(); i++) {
    if (nums[i - 1] < nums[i]) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = 1;
    }
  }
  int res = 0;
  for (auto& i : dp) {
    res = std::max(i, res);
  }
  return res;
}

int main(int argc, char const* argv[]) {
  std::string str;
  std::getline(std::cin, str);
  std::stringstream ss(str);
  int num;
  std::vector<int> nums;
  while (ss >> num) {
    nums.emplace_back(num);
  }
  std::cout << findLengthOfLCIS(nums) << std::endl;
  return 0;
}
