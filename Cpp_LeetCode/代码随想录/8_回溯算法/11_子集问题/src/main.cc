#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief 78_子集
 * https://leetcode.cn/problems/subsets/description/
 */

std::vector<int> path;
std::vector<std::vector<int>> res;

void backtracking(std::vector<int>& nums, int startIndex) {
  res.emplace_back(path);
  if (startIndex >= nums.size()) {  // 终止条件可以不加
    return;
  }
  for (int i = startIndex; i < nums.size(); i++) {
    path.emplace_back(nums[i]);
    backtracking(nums, i + 1);
    path.pop_back();
  }
}

vector<vector<int>> subsets(vector<int>& nums) {
  path.clear();
  res.clear();
  backtracking(nums, 0);
  return res;
}

int main() {
  int n;
  vector<int> nums;
  while (std::cin >> n) {
    nums.emplace_back(n);
  }

  auto ans = subsets(nums);
  for (auto& i : ans) {
    for (auto& j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}