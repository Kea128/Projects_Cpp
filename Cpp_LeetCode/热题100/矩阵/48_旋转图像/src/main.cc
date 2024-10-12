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
 * @brief 48_旋转图像
 * https://leetcode.cn/problems/rotate-image/description/?envType=study-plan-v2&envId=top-100-liked
 */

void rotate_V1(vector<vector<int>>& matrix) {
  int n = matrix.size();
  std::vector<std::vector<int>> matrix_cp(matrix.begin(), matrix.end());
  // 考虑行：i行 -> n-i-1列
  // 考虑列：j列 -> j行
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      matrix[j][n - i - 1] = matrix_cp[i][j];
    }
  }
}

void rotate_V2(std::vector<std::vector<int>>& matrix) {
  int n = matrix.size();
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < (n + 1) / 2; j++) {
      int tmp = matrix[i][j];
      matrix[i][j] = matrix[n - j - 1][i];
      matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
      matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
      matrix[j][n - i - 1] = tmp;
    }
  }
}

int main() { return 0; }