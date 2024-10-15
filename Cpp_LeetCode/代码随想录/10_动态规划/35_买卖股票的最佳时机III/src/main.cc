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

int maxProfit(vector<int>& prices) {}

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
