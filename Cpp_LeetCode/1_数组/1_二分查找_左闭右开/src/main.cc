#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief 二分查找 [左闭右开）
 */

int search(std::vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size();
  while (left < right) {
    int middle = (left + right) / 2;
    if (nums[middle] > target) {
      right = middle;
    } else if (nums[middle] < target) {
      left = middle + 1;
    } else {
      return middle;
    }
  }
  return -1;
}

int main() {
  std::vector<int> numbers;
  int num;
  while (true) {
    std::cin >> num;
    numbers.push_back(num);
    // if (std::cin.get() == '\n') break;
    if (getchar() == '\n') break;
  }
  int target;
  std::cin >> target;

  std::cout << search(numbers, target) << std::endl;

  return 0;
}