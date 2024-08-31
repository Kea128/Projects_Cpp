#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief 移除元素
 */

int removeElement(std::vector<int>& nums, int val) {}

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

  std::cout << removeElement(numbers, target) << std::endl;

  return 0;
}