#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 518_零钱兑换II
 * https://leetcode.cn/problems/coin-change-ii/description/
 */

// 打印dp数组

int change(int amount, vector<int>& coins) {
  // dp[j]表示容量为j的背包有多少种方法可以装满
  // 求 dp[amount]
  std::vector<int> dp(amount + 1, 0);
  dp[0] = 1;
  // for (int i = 0; i < coins.size(); i++) {
  //   for (int j = coins[i]; j <= amount; j++) {
  //     dp[j] = dp[j] + dp[j - coins[i]];
  //   }
  // }
  for (int j = 0; j <= amount; j++) {         // 遍历背包容量
    for (int i = 0; i < coins.size(); i++) {  // 遍历物品
      if (j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
      std::cout << dp[j] << " ";
    }
    std::cout << std::endl;
  }

  return dp[amount];
}

int main(int argc, char const* argv[]) {
  int amount;
  std::cin >> amount;
  int n;
  std::vector<int> coins;
  while (std::cin >> n) {
    coins.emplace_back(n);
  }
  std::cout << change(amount, coins) << std::endl;

  return 0;
}
