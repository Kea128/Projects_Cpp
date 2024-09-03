#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief 283 移动零
 * https://leetcode.cn/problems/move-zeroes/solutions/90229/dong-hua-yan-shi-283yi-dong-ling-by-wang_ni_ma/?envType=study-plan-v2&envId=top-100-liked
 */

/*
  给定一个数组 nums，编写一个函数将所有 0
  移动到数组的末尾，同时保持非零元素的相对顺序。
  请注意,必须在不复制数组的情况下原地对数组进行操作
*/

void moveZeroes(std::vector<int>& nums) {
  int left = 0;
  int right = 0;
  for (; right < nums.size(); right++) {
    if (nums[right] != 0) {
      nums[left] = nums[right];
      left++;
    }
  }
  for (; left < nums.size(); left++) {
    nums[left] = 0;
  }
}

int main() {
  int n;
  std::vector<int> nums;
  while (true) {
    std::cin >> n;
    nums.emplace_back(n);
    char s = std::getchar();
    if (s == '\n') break;
  }

  moveZeroes(nums);

  for (const auto& num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}