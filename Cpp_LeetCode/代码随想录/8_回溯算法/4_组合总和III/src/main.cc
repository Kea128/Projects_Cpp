#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

/**
 * @brief 216 组合总和III
 * https://leetcode.cn/problems/combination-sum-iii/description/
 */
std::vector<int> path;
std::vector<std::vector<int>> res;
int sum = 0;
void backTracking(int k, int n, int startIndex) {
  // 剪枝
  if (sum > n) {
    return;
  }

  // k控制递归深度
  if (path.size() == k) {
    if (sum == n) res.emplace_back(path);
    return;
  }

  for (int i = startIndex; i <= 9; i++) {
    sum += i;
    path.emplace_back(i);
    backTracking(k, n, i + 1);
    sum -= i;
    path.pop_back();
  }
}

std::vector<std::vector<int>> combinationSum3(int k, int n) {
  backTracking(k, n, 1);
  return res;
}

int main(int argc, char *argv[]) {
  int k, n;
  std::cin >> k >> n;

  return 0;
}
