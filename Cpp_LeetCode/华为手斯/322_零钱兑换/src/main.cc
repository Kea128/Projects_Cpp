#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief 322_零钱兑换
 * https://leetcode.cn/problems/coin-change/description/
 */

// int coinChange(vector<int>& coins, int amount) {
//   std::sort(coins.begin(), coins.end());
//   std::vector<std::pair<int, int>> dp(amount + 1, {0, 0});
//   dp[0].first = 0;
//   dp[0].second = 0;
//   for (int i = coins.size() - 1; i >= 0; i--) {
//     for (int j = coins[i]; j <= amount; j++) {
//       if (dp[j - coins[i]].first + coins[i] > dp[j].first) {
//         dp[j].first = dp[j - coins[i]].first + coins[i];
//         dp[j].second = dp[j - coins[i]].second + 1;
//       } else if (dp[j - coins[i]].first + coins[i] < dp[j].first) {
//         dp[j].first = dp[j].first;
//         dp[j].second = dp[j].second;
//       } else if (dp[j - coins[i]].first + coins[i] == dp[j].first) {
//         dp[j].first = dp[j - coins[i]].first + coins[i];
//         dp[j].second = std::min(dp[j - coins[i]].second + 1, dp[j].second);
//       }
//     }
//     for (auto& k : dp) {
//       std::cout << k.first << ":" << k.second << " ";
//     }
//     std::cout << std::endl;
//   }
//   return dp[amount].first == amount ? dp[amount].second : -1;
// }

int coinChange(vector<int>& coins, int amount) {
  // dp[j]表示凑成总金额为j需要最少的硬币数量
  std::vector<int> dp(amount + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 0; i < coins.size(); i++) {
    for (int j = coins[i]; j <= amount; j++) {
      if (dp[j - coins[i]] != INT_MAX)
        dp[j] = std::min(dp[j], dp[j - coins[i]] + 1);
    }
  }
  return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main(int argc, char const* argv[]) {
  std::string str;
  std::getline(std::cin, str);
  std::stringstream ss(str);
  int coin;
  std::vector<int> coins;
  while (ss >> coin) {
    coins.emplace_back(coin);
  }
  int amount;
  std::cin >> amount;

  std::cout << coinChange(coins, amount) << std::endl;
}
