#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief 90_子集II
 * https://leetcode.cn/problems/subsets/description/
 */

std::vector<int> path;
std::vector<std::vector<int>> res;

// 先排序
void backtracking(std::vector<int>& nums, std::vector<bool>& visited,
                  int startIndex) {
  res.emplace_back(path);
  if (startIndex == nums.size()) return;
  for (int i = startIndex; i < nums.size(); i++) {
    if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) {  // 树层去重
      continue;
    }
    path.emplace_back(nums[i]);
    visited[i] = 1;
    backtracking(nums, visited, i + 1);
    visited[i] = 0;
    path.pop_back();
  }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  path.clear();
  res.clear();
  std::vector<bool> visited(nums.size(), false);
  backtracking(nums, visited, 0);
  return res;
}

int main() {
  int n;
  vector<int> nums;
  while (std::cin >> n) {
    nums.emplace_back(n);
  }

  auto ans = subsetsWithDup(nums);
  for (auto& i : ans) {
    for (auto& j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}