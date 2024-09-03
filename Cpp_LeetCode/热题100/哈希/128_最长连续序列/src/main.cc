#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief 128 最长连续序列
 */

/*
  给定一个未排序的整数数组 nums
  找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
  请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

  示例 1：
    输入：nums = [100,4,200,1,3,2]
    输出：4
    解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4
  示例 2：
    输入：nums = [0,3,7,2,5,8,4,6,0,1]
    输出：9
*/

/*
  采用排序和滑动窗口
  1 2 0 1 ——> 0 1 1 2 会有问题
*/
int longestConsecutive_V1(std::vector<int>& nums) {
  // 排序
  if (nums.size() == 0) return 0;
  if (nums.size() < 2) return 1;
  std::sort(nums.begin(), nums.end());
  // 滑动窗口
  int left = 0;
  int right = 1;
  int count = 1;
  int contiCount = 1;
  while (right <= nums.size() - 1) {
    if (nums[right] - nums[left] == 1) {
      count++;
    } else {
      count = 1;
    }
    if (count > contiCount) {
      contiCount = count;
    }
    left++;
    right++;
  }
  return contiCount;
}

/*
  采用排序和滑动窗口
*/
int longestConsecutive_V2(std::vector<int>& nums) {
  // 排序
  if (nums.size() == 0) return 0;
  if (nums.size() < 2) return 1;
  std::sort(nums.begin(), nums.end());
  // 滑动窗口
  int contiCount = 1;
  int count = 1;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] - nums[i - 1] == 1) {
      count++;
    } else if (nums[i] - nums[i - 1] == 0) {
      continue;
    } else if (nums[i] - nums[i - 1] > 1) {
      count = 1;
    }
    if (count > contiCount) {
      contiCount = count;
    }
  }
  return contiCount;
}

std::vector<std::string> strs;

int main() {
  int n;
  std::vector<int> nums;
  while (true) {
    std::cin >> n;
    nums.emplace_back(n);
    char s = std::getchar();
    if (s == '\n') break;
  }

  // 打印所有存储的字符串
  for (const auto& num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  std::cout << longestConsecutive_V2(nums) << std::endl;

  return 0;
}