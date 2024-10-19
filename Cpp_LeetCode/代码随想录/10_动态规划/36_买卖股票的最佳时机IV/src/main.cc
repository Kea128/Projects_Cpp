#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief 188_买卖股票的最佳时机IV
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
 */

int maxProfit(int k, std::vector<int>& prices) {
  // 定义dp数组
  std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2 * k + 1));
  // dp数组初始化
  for (int j = 0; j <= 2 * k; j++) {
    if (j % 2 == 0)
      dp[0][j] = 0;
    else
      dp[0][j] = -prices[0];
  }

  for (int i = 1; i < prices.size(); i++) {
    for (int j = 1; j <= 2 * k; j++) {
      if (j % 2 == 1)
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
      else
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
    }
  }
  return dp[prices.size() - 1][2 * k];
}

int main(int argc, char const* argv[]) {
  int k;
  std::cin >> k;
  std::cin.ignore();  // 忽略换行符

  std::string str;
  std::getline(cin, str);
  std::stringstream ss(str);
  std::vector<int> prices;
  int price;
  while (ss >> price) {
    prices.emplace_back(price);
  }

  std::cout << maxProfit(k, prices) << std::endl;
  return 0;
}
