#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief 300_最长递增子序列
 * https://leetcode.cn/problems/longest-increasing-subsequence/description/
 */

int lengthOfLIS(vector<int>& nums) {
  // dp[i]表示以第i个数结尾的最长递增子序列的长度
  std::vector<int> dp(nums.size(), 1);

  for (int i = 0; i < nums.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j]) {  // 表示递增
        dp[i] = std::max(dp[j] + 1, dp[i]);
      }
    }
  }
  int res = 0;
  for (auto& i : dp) {
    res = std::max(res, i);
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
  std::cout << lengthOfLIS(nums) << std::endl;
  return 0;
}
