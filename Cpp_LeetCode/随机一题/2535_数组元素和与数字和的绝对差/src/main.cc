#include <iostream>
#include <set>
#include <vector>

/**
 * @brief 2535_数组元素和与数字和的绝对差
 * https://leetcode.cn/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/?envType=daily-question&envId=2024-09-26
 */

int solution(std::vector<int>& nums) {
  int sum = 0;
  int sum2 = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    int tmp = nums[i];
    while (tmp > 0) {
      sum2 += tmp % 10;
      tmp /= 10;
    }
  }
  return std::abs(sum - sum2);
}

int main(int argc, char const* argv[]) {
  int tmp;
  std::vector<int> nums;
  while (std::cin >> tmp) {
    nums.emplace_back(tmp);
  }
  std::cout << solution(nums) << std::endl;
  return 0;
}
