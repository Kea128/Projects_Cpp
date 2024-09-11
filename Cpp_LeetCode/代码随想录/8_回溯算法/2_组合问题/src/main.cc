#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

/**
 * @brief 77 组合
 * https://leetcode.cn/problems/combinations/description/
 */

// 回溯算法
std::vector<int> path;
std::vector<std::vector<int>> res;
// 确定递归参数和返回值
void backTracking(int n, int k, int startIndex) {
  // 终止条件
  if (path.size() == k) {  // 收集结果
    res.emplace_back(path);
    return;
  }
  // for (int i = startIndex; i <= n; i++) {
  //   path.emplace_back(i);
  //   backTracking(n, k, i + 1);
  //   path.pop_back();
  // }
  // 剪枝后
  for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
    path.emplace_back(i);
    backTracking(n, k, i + 1);
    path.pop_back();
  }
}

std::vector<std::vector<int>> combine(int n, int k) {
  backTracking(n, k, 1);
  return res;
}

int main(int argc, char* argv[]) {
  int n, k;
  std::cin >> n >> k;

  auto res = combine(n, k);
  for (auto& i : res) {
    for (auto& j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}
