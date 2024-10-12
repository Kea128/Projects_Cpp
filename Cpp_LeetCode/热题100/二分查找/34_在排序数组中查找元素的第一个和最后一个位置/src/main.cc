#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief 34_在排序数组中查找元素的第一个和最后一个位置
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/?envType=study-plan-v2&envId=top-100-liked
 */

// 把矩阵每一行拼在一起，我们可以得到一个递增数组，然后二分查找
vector<int> searchRange(vector<int>& nums, int target) {}

int main() {
  // matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
  std::vector<int> matrix = {5, 7, 7, 8, 8, 10};
  int target = 8;
  auto res = searchRange(matrix, target);
  return 0;
}