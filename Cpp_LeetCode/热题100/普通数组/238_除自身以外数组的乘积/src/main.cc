#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief 238_除自身以外数组的乘积
 * https://leetcode.cn/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-100-liked
 */

vector<int> productExceptSelf(vector<int>& nums) {
  std::vector<int> qian(nums.size(), 1);
  std::vector<int> hou(nums.size(), 1);
  int ji = 1;
  for (int i = 1; i < nums.size(); i++) {
    ji *= nums[i - 1];
    qian[i] = ji;
  }
  ji = 1;
  for (int i = nums.size() - 2; i >= 0; i--) {
    ji *= nums[i + 1];
    hou[i] = ji;
  }
  std::vector<int> ans(nums.size(), 0);
  for (int i = 0; i < nums.size(); i++) {
    ans[i] = qian[i] * hou[i];
  }
  return ans;
}

int main() {
  int n;
  std::vector<int> nums;
  while (std::cin >> n) {
    nums.emplace_back(n);
  }
  std::vector<int> ans = productExceptSelf(nums);
  for (auto& i : ans) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}