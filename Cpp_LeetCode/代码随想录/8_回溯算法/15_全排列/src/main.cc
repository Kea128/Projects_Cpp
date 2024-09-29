#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief 46_全排列
 * https://leetcode.cn/problems/permutations/?envType=study-plan-v2&envId=top-100-liked
 */

std::vector<int> path;
std::vector<std::vector<int>> res;

void backtracking(std::vector<int>& nums, int startIndex) {
  if (path.size() == nums.size()) {
    res.emplace_back(path);
    return;
  }
  for (int i = 0; i < nums.size(); i++) {
  }
}

vector<vector<int>> permute(vector<int>& nums) {}

int main() {
  int n;
  vector<int> nums;
  while (std::cin >> n) {
    nums.emplace_back(n);
  }

  auto ans = permute(nums);
  for (auto& i : ans) {
    for (auto& j : i) {
      std::cout << j << " ";
    }
  }
  std::cout << std::endl;
}