#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * @brief 黑白块
 * https://kamacoder.com/problempage.php?pid=1245
 */

int solution(const std::vector<std::vector<int>>& map, int n, int m) {
  // 动态规划
  // 首先初始化dp数组
  std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
  if (map[0][0] == 1) dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0] + map[i][0];
  }
  for (int j = 1; j < m; j++) {
    dp[0][j] = dp[0][j - 1] + map[0][j];
  }

  // for (auto i : dp) {
  //   for (auto j : i) {
  //     std::cout << j << " ";
  //   }
  //   std::cout << std::endl;
  // }
  // 动态规划
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j]) + map[i][j];
    }
  }
  return dp[n - 1][m - 1];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> map(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> map[i][j];
    }
  }
  std::cout << solution(map, n, m) << std::endl;
}