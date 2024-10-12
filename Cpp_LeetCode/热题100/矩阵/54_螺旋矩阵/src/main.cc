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
 * @brief 54_螺旋矩阵
 * https://leetcode.cn/problems/spiral-matrix/description/?envType=study-plan-v2&envId=top-100-liked
 */

std::vector<int> solution(std::vector<std::vector<int>>& matrix, int row,
                          int col) {
  std::vector<int> res;
  int count = 0;
  int size = 0;
  if (row == 1) return matrix[0];
  if (col == 1) {
    for (int i = 0; i < row; i++) {
      res.emplace_back(matrix[i][0]);
    }
    return res;
  }

  while (size < row * col) {
    for (int j = count; j < col - count - 1; j++) {
      res.emplace_back(matrix[count][j]);
      size++;
    }
    for (int i = count; i < row - count - 1; i++) {
      res.emplace_back(matrix[i][col - 1 - count]);
      size++;
    }
    for (int j = col - 1 - count; j > 0 + count; j--) {
      res.emplace_back(matrix[row - 1 - count][j]);
      size++;
    }
    for (int i = row - 1 - count; i > 0 + count; i--) {
      res.emplace_back(matrix[i][count]);
      size++;
    }
    if (row * col - size == 1) {
      res.emplace_back(matrix[row / 2][col / 2]);
      size++;
    }
    // row -= 2;
    // col -= 2;
    count++;
  }
  return res;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int row = matrix.size();
  int col = matrix[0].size();
  std::vector<int> res = solution(matrix, row, col);
  return res;
}

int main() {
  // std::vector<std::vector<int>> matrix = {
  //     {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  // std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // std::vector<std::vector<int>> matrix = {{6, 9, 7}};
  // [[2,3,4],[5,6,7],[8,9,10],[11,12,13],[14,15,16]]
  std::vector<std::vector<int>> matrix = {
      {2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13}, {14, 15, 16}};
  std::vector<int> res = spiralOrder(matrix);
  for (int i = 0; i < res.size(); i++) {
    std::cout << res[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}