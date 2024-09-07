#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * @brief 560 和为K的子数组
 * https://leetcode.cn/problems/subarray-sum-equals-k/?envType=study-plan-v2&envId=top-100-liked
 */

/**
 * 滑动窗口，负值有问题
 * 35/93
 * 输入 nums = [-1,-1,1]; k = 0
 * 输出 0
 * 预期结果 1
 */
int subarraySum_V1(std::vector<int>& nums, int k) {
  std::vector<int> window;
  int sum = 0;
  int left = 0;
  int count = 0;
  for (int right = 0; right < nums.size(); right++) {
    window.emplace_back(nums[right]);
    sum += nums[right];
    while (sum > k && left < right) {
      sum -= nums[left];
      left++;
    }
    if (sum == k) count++;
  }
  return count;
}

// 枚举 超时
int subarraySum_V2(std::vector<int>& nums, int k) {
  int count = 0;
  for (int start = 0; start < nums.size(); start++) {
    int sum = 0;
    for (int end = start; end < nums.size(); end++) {
      sum += nums[end];
      if (sum == k) {
        count++;
      }
    }
  }
  return count;
}

// 前缀和 + 哈希
int subarraySum_V3(std::vector<int>& nums, int k) {
  int count = 0;
  std::unordered_map<int, int> mp;
  mp.insert(std::pair<int, int>(0, 1));
  int sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    auto it = mp.find(sum - k);
    if (it != mp.end()) {
      count += it->second;
    }
    mp[sum]++;
  }
  return count;
}

int main() {
  std::vector<int> nums;
  int n, k;
  while (true) {
    std::cin >> n;
    nums.emplace_back(n);
    if (std::getchar() == '\n') break;
  }
  std::cin >> k;

  std::cout << subarraySum_V3(nums, k) << std::endl;
}