#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief 35_搜索插入位置
 * https://leetcode.cn/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-100-liked
 */

// 二分查找: 左闭右闭
int searchInsert(vector<int>& nums, int target) {
  int left = 0, right = nums.size() - 1;
  while (left <= right) {
    int midIndex = (left + right) / 2;  // 已经向下取整
    int midValue = nums[midIndex];
    if (midValue > target) {
      right = midIndex - 1;
    } else if (midValue < target) {
      left = midIndex + 1;
    } else if (midValue == target) {
      return midIndex;
    }
  }
  return left;
}

int main() {
  vector<int> nums = {1, 3, 5, 6};
  int target = 5;
  cout << searchInsert(nums, target) << endl;
  return 0;
}