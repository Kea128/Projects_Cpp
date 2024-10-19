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

int maxProfit(vector<int>& prices) {}

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
