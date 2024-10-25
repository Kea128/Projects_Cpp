#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief 44_最长公共子序列
 * https://leetcode.cn/problems/longest-common-subsequence/description/
 */

int longestCommonSubsequence(string text1, string text2) {
  // dp[i][j]含义：[0,i]区间的text1 和 [0,j]区间的text2的最长公共子序列的长度
  std::vector<std::vector<int>> dp(text1.size(),
                                   std::vector<int>(text2.size(), 0));
  int res = 0;
  // dp初始化
  if (text1[0] == text2[0]) {
    dp[0][0] = 1;
    res = 0;
  }
  // dp[0][0] = text1[0] == text2[0] ? 1 : 0;
  for (int i = 1; i < text1.size(); i++) {
    if (text1[i] == text2[0])
      dp[i][0] = 1;
    else
      dp[i][0] = dp[i - 1][0];
    res = std::max(res, dp[i][0]);
  }
  for (int j = 1; j < text2.size(); j++) {
    if (text1[0] == text2[j])
      dp[0][j] = 1;
    else
      dp[0][j] = dp[0][j - 1];
    res = std::max(res, dp[0][j]);
  }

  // dp递推
  for (int i = 1; i < text1.size(); i++) {
    for (int j = 1; j < text2.size(); j++) {
      if (text1[i] == text2[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
      }
      res = std::max(dp[i][j], res);
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
  std::cin >> str1;
  std::cin >> str2;
  std::cout << longestCommonSubsequence(str1, str2) << std::endl;
  return 0;
}
