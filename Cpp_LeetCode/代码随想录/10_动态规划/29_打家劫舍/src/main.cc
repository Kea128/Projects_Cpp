#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 198_打家劫舍
 * https://programmercarl.com/0198.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8D.html
 */

int rob(vector<int>& cash) {
  std::vector<int> dp(cash.size(), 0);
  if (cash.size() == 1) return cash[0];
  if (cash.size() == 2) return std::max(cash[0], cash[1]);
  dp[0] = cash[0];
  dp[1] = cash[1] >= cash[0] ? cash[1] : cash[0];

  for (int i = 2; i < cash.size(); i++) {
    dp[i] = std::max(dp[i - 2] + cash[i], dp[i - 1]);
  }

  for (auto& i : dp) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return dp[cash.size() - 1];
}

int main(int argc, char const* argv[]) {
  int n;
  std::vector<int> cash;
  while (std::cin >> n) {
    cash.emplace_back(n);
  }
  std::cout << rob(cash) << std::endl;

  return 0;
}
