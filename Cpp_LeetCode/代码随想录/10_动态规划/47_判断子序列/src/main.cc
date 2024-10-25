#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief 392_判断子序列
 * https://leetcode.cn/problems/is-subsequence/description/
 */

bool isSubsequence(string s, string t) {
  std::vector<std::vector<int>> dp(s.size() + 1,
                                   std::vector<int>(t.size() + 1, 0));
  // dp初始化：dp[i][0] dp[0][j] 均为0
  int maxNum = 0;
  for (int i = 1; i <= s.size(); i++) {
    for (int j = 1; j <= t.size(); j++) {
      if (s[i - 1] == t[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      maxNum = std::max(maxNum, dp[i][j]);
    }
  }

  for (auto& i : dp) {
    for (auto& j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
  return maxNum == s.size();
}

int main(int argc, char const* argv[]) {
  std::string str1 = "abc";
  std::string str2 = "ahbgdc";
  std::cout << isSubsequence(str1, str2) << std::endl;
  return 0;
}
