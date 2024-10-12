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

<<<<<<< Updated upstream
void backtracking(std::vector<int>& nums, std::vector<bool>& used) {
=======
void backtracking(std::vector<int>& nums, int startIndex) {
>>>>>>> Stashed changes
  if (path.size() == nums.size()) {
    res.emplace_back(path);
    return;
  }
  for (int i = 0; i < nums.size(); i++) {
<<<<<<< Updated upstream
    if (used[i]) continue;
    path.emplace_back(nums[i]);
    used[i] = true;
    backtracking(nums, used);
    used[i] = false;
    path.pop_back();
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  std::vector<bool> used(nums.size(), 0);
  path.clear();
  res.clear();
  backtracking(nums, used);
  return res;
}
=======
  }
}

vector<vector<int>> permute(vector<int>& nums) {}
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
    std::cout << std::endl;
  }
=======
  }
  std::cout << std::endl;
>>>>>>> Stashed changes
}