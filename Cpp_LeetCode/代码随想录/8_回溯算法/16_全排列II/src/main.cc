#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief 47_全排列II
 * https://leetcode.cn/problems/permutations-ii/description/
 */

std::vector<int> path;
std::vector<std::vector<int>> res;

/**
 * @note 这里用 uset 做横向树层去重
 * @note 用 used 做纵向树枝去重
 */
void backtracking(std::vector<int>& nums, std::vector<bool> used) {
  if (path.size() == nums.size()) {
    res.emplace_back(path);
    return;
  }
  std::unordered_set<int> uset;
  for (int i = 0; i < nums.size(); i++) {
    if ((!uset.empty() && uset.find(nums[i]) != uset.end()) ||
        used[i] == true) {
      continue;
    }
    uset.insert(nums[i]);
    path.emplace_back(nums[i]);
    used[i] = true;
    backtracking(nums, used);
    used[i] = false;
    path.pop_back();
  }
}

/**
 * @note 用 used 同时进行 树层+树枝 去重
 */
void backtracking2(std::vector<int>& nums, std::vector<bool> used) {
  if (path.size() == nums.size()) {
    res.emplace_back(path);
    return;
  }
  for (int i = 0; i < nums.size(); i++) {
    if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {  // 树层去重
      continue;
    }
    if (used[i] == true) {  // 树枝去重
      continue;
    }
    path.emplace_back(nums[i]);
    used[i] = true;
    backtracking2(nums, used);
    used[i] = false;
    path.pop_back();
  }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
  std::vector<bool> used(nums.size(), false);
  backtracking(nums, used);
  return res;
}

vector<vector<int>> permuteUnique2(vector<int>& nums) {
  std::vector<bool> used(nums.size(), false);
  // 需要排序
  std::sort(nums.begin(), nums.end());
  backtracking2(nums, used);
  return res;
}

int main() {
  int n;
  vector<int> nums;
  while (std::cin >> n) {
    nums.emplace_back(n);
  }

  auto ans = permuteUnique(nums);
  for (auto& i : ans) {
    for (auto& j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}