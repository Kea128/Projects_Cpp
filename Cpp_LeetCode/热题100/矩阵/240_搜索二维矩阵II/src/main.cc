#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief 240_搜索二维矩阵II
 * https://leetcode.cn/problems/search-a-2d-matrix-ii/?envType=study-plan-v2&envId=top-100-liked
 */

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int m = matrix.size();
  int n = matrix[0].size();
  int i = 0, j = n - 1;
  while (i <= m - 1 && j >= 0) {
    if (matrix[i][j] > target) {
      j--;
    } else if (matrix[i][j] < target) {
      i++;
    } else if (matrix[i][j] == target) {
      return true;
    }
  }
  return false;
}

int main() {
  // matrix =
  // [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
  // target = 5
  std::vector<std::vector<int>> matrix = {{1, 4, 7, 11, 15},
                                          {2, 5, 8, 12, 19},
                                          {3, 6, 9, 16, 22},
                                          {10, 13, 14, 17, 24},
                                          {18, 21, 23, 26, 30}};
  int target = 5;
  std::cout << searchMatrix(matrix, target) << std::endl;
  return 0;
}