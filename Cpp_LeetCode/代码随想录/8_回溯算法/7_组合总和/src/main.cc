#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 39_组合总和
 * https://leetcode.cn/problems/combination-sum/description/
 */

std::vector<int> path;
std::vector<std::vector<int>> res;
void backtracking(std::vector<int>& candidates, int target, int sum,
                  int startIndex) {
  if (sum > target) return;
  if (sum == target) {
    res.emplace_back(path);
    return;
  }
  for (int i = startIndex; i < candidates.size(); i++) {
    path.emplace_back(candidates[i]);
    sum += candidates[i];
    backtracking(candidates, target, sum, i);
    path.pop_back();
    sum -= candidates[i];
  }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  backtracking(candidates, target, 0, 0);
  return res;
}

int main(int argc, char const* argv[]) {
  int tmp;
  std::vector<int> candidates;
  while (std::cin >> tmp) {
    candidates.emplace_back(tmp);
    if (std::getchar() == '\n') break;
  }
  int target;
  std::cin >> target;

  auto ans = combinationSum(candidates, target);
  for (const auto& i : ans) {
    for (const auto& j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
