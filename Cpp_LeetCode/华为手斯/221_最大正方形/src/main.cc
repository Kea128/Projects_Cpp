#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief 221_最大正方形
 * https://leetcode.cn/problems/maximal-square/description/
 */

int maximalSquare(vector<vector<char>>& matrix) {
  std::vector<std::vector<int>> dp(matrix.size(),
                                   std::vector<int>(matrix[0].size(), 0));
  int res = 0;
  for (int i = 0; i < matrix.size(); i++) {
    dp[i][0] = matrix[i][0] - '0';
    res = std::max(res, dp[i][0]);
  }
  for (int j = 1; j < matrix[0].size(); j++) {
    dp[0][j] = matrix[0][j] - '0';
    res = std::max(res, dp[0][j]);
  }

  for (int i = 1; i < matrix.size(); i++) {
    for (int j = 1; j < matrix[0].size(); j++) {
      if (matrix[i][j] == '0')
        dp[i][j] = 0;
      else
        dp[i][j] = std::min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
      res = std::max(res, dp[i][j]);
    }
  }
  return res * res;
}

int main(int argc, char const* argv[]) {
  // matrix =
  // [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
  std::vector<std::vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                           {'1', '0', '1', '1', '1'},
                                           {'1', '1', '1', '1', '1'},
                                           {'1', '0', '0', '1', '0'}};
  std::cout << maximalSquare(matrix) << std::endl;
}
