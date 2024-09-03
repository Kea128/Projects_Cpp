#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief 11 盛最多水的容器
 * https://leetcode.cn/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-100-liked
 */

/*

给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0)
和 (i, height[i]) 。 找出其中的两条线，使得它们与 x
轴共同构成的容器可以容纳最多的水。 返回容器可以储存的最大水量。
说明：你不能倾斜容器。
示例 1：
  输入：[1,8,6,2,5,4,8,3,7]
  输出：49
  解释：图中垂直线代表输入数组[1,8,6,2,5,4,8,3,7]。
  在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
示例 2：
  输入：height = [1,1]
  输出：1
*/

int maxArea(std::vector<int>& height) {
  int left = 0;
  int right = height.size() - 1;
  int maxV = 0;
  maxV = std::min(height[left], height[right]) * (right - left);
  while (left < right) {
    if (height[left] <= height[right]) {
      left++;
    } else if (height[left] > height[right]) {
      right--;
    }
    maxV = std::min(height[left], height[right]) * (right - left) > maxV
               ? std::min(height[left], height[right]) * (right - left)
               : maxV;
  }
  return maxV;
}

int main() {
  int n;
  std::vector<int> nums;
  while (true) {
    std::cin >> n;
    nums.emplace_back(n);
    if (std::getchar() == '\n') break;
  }

  for (const auto& num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  std::cout << "最大容量: ";
  std::cout << maxArea(nums) << std::endl;
}