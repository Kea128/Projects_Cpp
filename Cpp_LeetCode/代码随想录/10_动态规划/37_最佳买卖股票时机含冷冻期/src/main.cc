#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief 309_最佳买卖股票时机含冷冻期
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 */

int maxProfit(vector<int>& prices) {
  // dp[i][0]表示第i天持有股票的最大收益
  // dp[i][1]表示第i天保持卖出股票的最大收益
  // dp[i][2]表示在第i天卖出股票的最大收益
  // dp[i][3]表示在第i天是冷冻期的最大收益
  std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(4, 0));

  // dp数组初始化
  dp[0][0] = -prices[0];
  dp[0][1] = 0;
  dp[0][2] = 0;
  dp[0][3] = 0;

  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] = std::max(dp[i - 1][0], std::max(dp[i - 1][1] - prices[i],
                                               dp[i - 1][3] - prices[i]));
    dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][3]);
    dp[i][2] = dp[i - 1][0] + prices[i];
    dp[i][3] = dp[i - 1][2];
  }
  return std::max(dp[prices.size() - 1][1],
                  std::max(dp[prices.size() - 1][2], dp[prices.size() - 1][3]));
}

int main(int argc, char const* argv[]) {
  // int k;
  // std::cin >> k;
  // std::cin.ignore();  // 忽略换行符

  std::string str;
  std::getline(cin, str);
  std::stringstream ss(str);
  std::vector<int> prices;
  int price;
  while (ss >> price) {
    prices.emplace_back(price);
  }
  std::cout << maxProfit(prices) << std::endl;
}
