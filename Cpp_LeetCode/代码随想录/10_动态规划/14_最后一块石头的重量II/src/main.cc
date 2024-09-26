#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 1049_最后一块石头的重量 II
 * https://leetcode.cn/problems/last-stone-weight-ii/description/
 */

void printDp(std::vector<std::vector<int>>& dp) {
  for (int i = 0; i < dp.size(); i++) {
    for (int j = 0; j < dp[0].size(); j++) {
      std::cout << dp[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

// // 二维dp
// int lastStoneWeightII(vector<int>& stones) {
//   int sums = 0;
//   int half = 0;
//   for (auto& i : stones) {
//     sums += i;
//   }
//   int target = sums / 2;  // 背包容量
//   std::vector<std::vector<int>> dp(
//       stones.size(), std::vector<int>(target + 1, 0));  // 二维dp数组
//   // 二维dp数组初始化
//   for (int i = 0; i < stones.size(); i++) {
//     dp[i][0] = 0;
//   }
//   for (int j = 0; j <= target; j++) {
//     dp[0][j] = j >= stones[0] ? stones[0] : 0;
//   }
//   // 根据递推关系式，更新dp数组
//   for (int i = 1; i < stones.size(); i++) {
//     for (int j = 1; j <= target; j++) {
//       if (j >= stones[i]) {
//         dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - stones[i]] +
//         stones[i]);
//       } else
//         dp[i][j] = dp[i - 1][j];
//     }
//   }
//   // 打印dp数组
//   // printDp(dp);
//   int value = dp[stones.size() - 1][target];

//   return sums - value - value;
// }

// 一维dp
int lastStoneWeightII(vector<int>& stones) {
  int sums = 0;
  for (auto& i : stones) {
    sums += i;
  }
  int target = sums / 2;
  // 一维dp数组
  std::vector<int> dp(target + 1, 0);
  // 一维dp数组初始化
  for (int j = 0; j <= target; j++) {
    dp[j] = j >= stones[0] ? stones[0] : 0;
  }
  // 根据递推关系式，更新dp数组
  for (int i = 1; i < stones.size(); i++) {
    for (int j = target; j >= 0; j--) {
      if (j >= stones[i])
        dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
      else
        dp[j] = dp[j];
    }
  }
  return sums - 2 * dp[target];
}

int main(int argc, char const* argv[]) {
  std::vector<int> stones;
  int tmp;
  while (std::cin >> tmp) {
    stones.push_back(tmp);
  }
  std::cout << lastStoneWeightII(stones) << std::endl;
  return 0;
}
