#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * @brief 560 和为K的子数组
 * https://leetcode.cn/problems/subarray-sum-equals-k/?envType=study-plan-v2&envId=top-100-liked
 */

/**
 * 需要long整型
 */
long calcu(const int& n, const std::vector<int> zan,
           const std::vector<int> cai) {
  long zanNum = 0;
  long caiNum = 0;
  for (int i = 0; i < n; i++) {
    if (zan[i] >= cai[i]) {
      zanNum += zan[i] - cai[i];
    } else {
      caiNum += cai[i] - zan[i];
    }
  }
  return std::max(zanNum, caiNum);
}

int main() {
  int n, tmp;
  std::vector<int> zan;
  std::vector<int> cai;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    zan.emplace_back(tmp);
  }
  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    cai.emplace_back(tmp);
  }
  std::cout << calcu(n, zan, cai) << std::endl;
}