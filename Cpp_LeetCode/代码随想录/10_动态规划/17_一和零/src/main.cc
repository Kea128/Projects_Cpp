#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 474_一和零
 * https://leetcode.cn/problems/ones-and-zeroes/description/
 */

int findMaxForm(vector<string>& strs, int m, int n) {
  // 初始化dp，三维dp压缩为二维
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
  for (string& str : strs) {
    int oneNum = 0, zeroNum = 0;
    for (char c : str) {
      if (c == '0')
        zeroNum++;
      else
        oneNum++;
    }
    for (int i = m; i >= zeroNum; i--) {
      for (int j = n; j >= oneNum; j--) {
        dp[i][j] = std::max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
      }
    }
  }
  return dp[m][n];
}

int main(int argc, char const* argv[]) { return 0; }
