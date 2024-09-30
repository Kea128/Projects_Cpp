#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 40_组合总和II
 * https://leetcode.cn/problems/combination-sum-ii/description/
 */

// 树层去重
std::vector<int> path;
std::vector<std::vector<int>> res;
void backtracking(std::vector<int>& candidates, int target, int sum,
                  int startIndex, std::vector<bool> used) {
  if (sum > target) {
    return;
  }
  if (sum == target) {
    res.emplace_back(path);
    return;
  }

  for (int i = startIndex; i < candidates.size(); i++) {
    if (i > 0 && candidates[i] == candidates[i - 1] &&
        used[i - 1] == 0) {  // 回溯后的树层去重
      continue;
    }
    path.emplace_back(candidates[i]);
    sum += candidates[i];
    used[i] = 1;
    backtracking(candidates, target, sum, i + 1, used);
    sum -= candidates[i];
    used[i] = 0;
    path.pop_back();
  }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  std::vector<bool> used(candidates.size(), 0);
  backtracking(candidates, target, 0, 0, used);
  return res;
}

int main(int argc, char const* argv[]) {
  int target;
  std::cin >> target;

  std::vector<int> candidates;
  int n;
  while (std::cin >> n) {
    candidates.emplace_back(n);
  }

  auto ans = combinationSum2(candidates, target);
  for (auto& v : ans) {
    for (auto& i : v) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}
