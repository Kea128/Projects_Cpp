#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * @brief 53 最大子数组和
 * https://leetcode.cn/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-100-liked
 */

int maxSubArray(std::vector<int>& nums) {
  int windowSum = 0;
  int left = 0;
  int right = 0;
  for (; right < nums.size(); right++) {
    windowSum += nums[right];
  }
}

int main() {
  int n;
  std::vector<int> nums;
  while (std::cin >> n) {
    nums.emplace_back(n);
  }
  std::cout << maxSubArray(nums) << std::endl;
}
s