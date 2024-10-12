#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief 74_搜索二维矩阵
 * https://leetcode.cn/problems/search-a-2d-matrix/?envType=study-plan-v2&envId=top-100-liked
 */

// 把矩阵每一行拼在一起，我们可以得到一个递增数组，然后二分查找
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int size = matrix.size() * matrix[0].size();
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    int midIndex = (left + right) / 2;
    int i = midIndex / matrix[0].size();
    int j = midIndex % matrix[0].size();
    int midValue = matrix[i][j];
    if (target > midValue) {
      left = midIndex + 1;
    } else if (target < midValue) {
      right = midIndex - 1;
    } else if (target == midValue) {
      return true;
    }
  }
  return false;
}

int main() {
  // matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
  std::vector<std::vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target = 3;
  std::cout << searchMatrix(matrix, target) << std::endl;
  return 0;
}