#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief 908_最小差值I
 * https://leetcode.cn/problems/smallest-range-i/description/?envType=daily-question&envId=2024-10-20
 */

int smallestRangeI(vector<int>& nums, int k) {
  std::sort(nums.begin(), nums.end());
  int lastIndex = nums.size() - 1;
  if (nums[0] + k >= nums[lastIndex] - k) {
    return 0;
  } else {
    return nums[lastIndex] - k - nums[0] - k;
  }
}

int main() {
  std::vector<int> nums;
  std::string line;
  std::getline(std::cin, line);
  std::stringstream ss(line);
  int num;
  while (ss >> num) {
    nums.push_back(num);
  }
  std::cin.ignore();
  int k;
  std::cin >> k;
  std::cout << smallestRangeI(nums, k) << std::endl;
  return 0;
}