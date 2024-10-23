#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief 714_买卖股票的最佳时机含手续费
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 */

int maxProfit(vector<int>& prices, int fee) {
  // dp[i][0]为持有股票的最大收益
  // dp[i][1]为不持有股票的最大收益

  std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));
  dp[0][0] = -prices[0];
  dp[0][1] = 0;

  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
    dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
  }
  return dp[prices.size() - 1][1];
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
  int fee;
  std::cin >> fee;
  std::cout << maxProfit(prices, fee) << std::endl;
}
