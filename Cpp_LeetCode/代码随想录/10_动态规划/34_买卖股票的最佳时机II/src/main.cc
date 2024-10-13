#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief 122_买卖股票的最佳时机II
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
 */

int maxProfit(vector<int>& prices) {
  // 动态规划
  // 1-定义dp数组：
  // dp[i][0]表示第i天持有股票的最大收益
  // dp[i][1]表示第i天不持有股票的最大收益
  std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));
  // 2-dp数组初始化
  dp[0][0] = -prices[0];
  dp[0][1] = 0;

  for (int i = 1; i < prices.size(); i++) {
    // 第i天持有股票的最大收益 = 【第i-1天持有股票的最大收益】 和
    // 【第i天才买入的收益】二者的最大值
    dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);

    // 第i天不持有股票的最大收益 = 【第i-1天不持有股票的最大收益】 和
    // 【第i天才卖出的收益】二者的最大值
    dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
  }

  std::function<void(void)> printDP = [&]() {
    for (int i = 0; i < dp.size(); i++) {
      for (int j = 0; j < dp[i].size(); j++) {
        std::cout << dp[i][j] << " ";
      }
      std::cout << std::endl;
    }
  };

  // printDP();

  return dp[prices.size() - 1][1];
}

int main(int argc, char const* argv[]) {
  std::string input;
  std::getline(std::cin, input);
  std::stringstream ss(input);

  std::vector<int> prices;
  int price;
  while (ss >> price) {
    prices.emplace_back(price);
  }
  std::cout << maxProfit(prices) << std::endl;
  return 0;
}
