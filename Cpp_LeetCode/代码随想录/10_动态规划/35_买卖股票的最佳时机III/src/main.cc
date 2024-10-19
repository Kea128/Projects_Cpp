#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief 123_买卖股票的最佳时机III
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/
 */

int maxProfit(vector<int>& prices) {
  // 定义dp数组
  // dp[i][0]第i天不操作的最大利润
  // dp[i][1]第i天第一次持有的最大利润
  // dp[i][2]第i天第一次不持有的最大利润
  // dp[i][3]第i天第二次持有的最大利润
  // dp[i][4]第i天第二次不持有的最大利润
  std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(5, 0));
  // dp数组初始化
  dp[0][0] = 0;
  dp[0][1] = -prices[0];
  dp[0][2] = 0;
  dp[0][3] = -prices[0];
  dp[0][4] = 0;
  // 动态规划
  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] = 0;
    dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
    dp[i][3] = std::max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
    dp[i][4] = std::max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
  }
  return dp[prices.size() - 1][4];
}

int main(int argc, char const* argv[]) {
  std::string str;
  std::getline(cin, str);
  std::stringstream ss(str);
  std::vector<int> prices;
  int price;
  while (ss >> price) {
    prices.emplace_back(price);
  }
  std::cout << maxProfit(prices) << std::endl;
  return 0;
}
