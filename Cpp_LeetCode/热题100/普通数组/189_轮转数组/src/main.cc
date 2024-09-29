#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 189_轮转数组
 * https://leetcode.cn/problems/rotate-array/?envType=study-plan-v2&envId=top-100-liked
 */

void rotate(vector<int>& nums, int k) {
  int left = 0;
  int right = nums.size() - k;
  int middle = k;
  for (; right < nums.size(); left++, right++, middle++) {
    int tmp = nums[middle];
    nums[middle] = nums[left];
    nums[left] = nums[right];
    nums[middle + k] = tmp;
  }
}

int main() {
  int k;
  std::cin >> k;
  std::vector<int> nums;
  int tmp;
  while (std::cin >> tmp) {
    nums.emplace_back(tmp);
  }

  rotate(nums, k);
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}
