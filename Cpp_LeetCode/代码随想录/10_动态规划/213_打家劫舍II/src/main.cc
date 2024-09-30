#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 213_打家劫舍II
 * https://leetcode.cn/problems/house-robber-ii/description/
 */

int rob(vector<int>& nums) {
  std::vector<int> nums2(nums.rbegin(), nums.rend());
  std::vector<int> dp_left(nums.size(), 0);
  std::vector<int> dp_right(nums.size(), 0);
  dp_left[0] = nums[0];

  return 1;
}

int main(int argc, char const* argv[]) {
  int n;
  std::vector<int> cash;
  while (std::cin >> n) {
    cash.emplace_back(n);
  }
  std::cout << rob(cash) << std::endl;

  return 0;
}
