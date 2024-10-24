#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief 718_最长重复子数组
 * https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/
 */

int findLength(vector<int>& nums1, vector<int>& nums2) {
  // dp[i][j]: 以i-1下标结尾的nums1子数组 和 以j-1下标结尾的nums2子数组 的
  // 最长子数组长度
  std::vector<std::vector<int>> dp(nums1.size() + 1,
                                   std::vector<int>(nums2.size() + 1, 0));
  // 初始化就是首行首列为0；
  int res = 0;
  for (int i = 1; i <= nums1.size(); i++) {
    for (int j = 1; j <= nums2.size(); j++) {
      if (nums1[i - 1] == nums2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        res = std::max(res, dp[i][j]);
      }
    }
  }

  // int res = 0;
  // for (auto& i : dp) {
  //   for (auto& j : i) {
  //     std::cout << j << " ";
  //     res = std::max(res, j);
  //   }
  //   std::cout << std::endl;
  // }
  return res;
}

int findLength_V2(vector<int>& nums1, vector<int>& nums2) {
  // dp[i][j]: 以i下标结尾的nums1子数组 和 以j下标结尾的nums2子数组 的
  // 最长子数组长度
  std::vector<std::vector<int>> dp(nums1.size(),
                                   std::vector<int>(nums2.size(), 0));
  int res = 0;
  // dp[0][j]和dp[i][0]初始化
  for (int j = 0; j < nums2.size(); j++) {
    if (nums1[0] == nums2[j]) dp[0][j] = 1;
    res = std::max(res, dp[0][j]);
  }
  for (int i = 0; i < nums1.size(); i++) {
    if (nums1[i] == nums2[0]) dp[i][0] = 1;
    res = std::max(res, dp[i][0]);
  }
  for (int i = 1; i < nums1.size(); i++) {
    for (int j = 1; j < nums2.size(); j++) {
      if (nums1[i] == nums2[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        res = std::max(res, dp[i][j]);
      }
    }
  }
  // for (auto& i : dp) {
  //   for (auto& j : i) {
  //     std::cout << j << " ";
  //   }
  //   std::cout << std::endl;
  // }
  return res;
}

int main(int argc, char const* argv[]) {
  std::string str1, str2;
  std::getline(std::cin, str1);
  std::getline(std::cin, str2);
  std::stringstream ss1(str1);
  std::stringstream ss2(str2);
  int num;
  std::vector<int> nums1, nums2;
  while (ss1 >> num) {
    nums1.emplace_back(num);
  }
  while (ss2 >> num) {
    nums2.emplace_back(num);
  }

  std::cout << findLength_V2(nums1, nums2) << std::endl;
  return 0;
}
