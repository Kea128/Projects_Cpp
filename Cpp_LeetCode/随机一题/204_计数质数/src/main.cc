#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief 给定整数 n ，返回 所有小于非负整数 n 的质数的数量
 * @note
 * 示例 1：
 * 输入：n = 10
 * 输出：4
 * 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 *
 * 示例 2：
 * 输入：n = 0
 * 输出：0
 *
 * 示例 3：
 * 输入：n = 1
 * 输出：0
 */

// 厄拉多塞筛法，但是会超时
int countPrimes_V1(int n) {
  int count = 0;
  std::vector<int> delete_nums;
  for (int i = 2; i < n; ++i) {
    auto index = std::find(delete_nums.begin(), delete_nums.end(), i);
    // 没找到i，则当前i是质数
    if (index == delete_nums.end()) {
      count++;
      for (int j = i; j < n; j += i) {
        delete_nums.emplace_back(j);
      }
    }
    // 在删除数组中找到i
    else {
      continue;
    }
  }
  return count;
}

// 厄拉多塞筛法，不超时
int countPrimes_V2(int n) {
  int count = 0;
  std::vector<bool> primes(n, true);  // 初始化bool数组,true表示质数
  for (int i = 2; i < n; ++i) {
    if (primes[i]) {
      count++;
      for (int j = i * 2; j < n; j += i) {
        primes[j] = false;
      }
    }
  }
  return count;
}

int main() {
  int n;
  std::cin >> n;

  std::cout << n << std::endl;

  int result = countPrimes_V2(n);
  std::cout << "result = " << result << std::endl;
  return 0;
}