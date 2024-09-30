#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief 491_非递减子序列
 * https://leetcode.cn/problems/non-decreasing-subsequences/
 */

std::vector<int> path;
std::vector<std::vector<int>> res;

// 这题没法先排序
void backtracking(std::vector<int>& nums, int startIndex) {
  if (path.size() >= 2) {
    res.emplace_back(path);
  }
  if (startIndex >= nums.size()) return;
  std::unordered_set<int> st;
  for (int i = startIndex; i < nums.size(); i++) {
    if (st.find(nums[i]) != st.end()) {  // 同一树层上去重
      continue;
    }
    st.insert(nums[i]);
    if (!path.empty()) {
      if (nums[i] < path.back())
        continue;
      else {
        path.emplace_back(nums[i]);
        backtracking(nums, i + 1);
        path.pop_back();
      }
    } else {
      path.emplace_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
  backtracking(nums, 0);
  return res;
}

int main() {
  int n;
  vector<int> nums;
  while (std::cin >> n) {
    nums.emplace_back(n);
  }

  auto ans = findSubsequences(nums);
  for (auto& i : ans) {
    for (auto& j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}