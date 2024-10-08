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
 * @brief 73_矩阵置零
 * https://leetcode.cn/problems/set-matrix-zeroes/?envType=study-plan-v2&envId=top-100-liked
 */

void setZeroes(vector<vector<int>>& matrix) {
  std::set<int> row;
  std::set<int> col;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      if (matrix[i][j] == 0) {
        row.insert(i);
        col.insert(j);
      }
    }
  }
  for (auto& i : row) {
    for (int j = 0; j < matrix[0].size(); j++) {
      matrix[i][j] = 0;
    }
  }
  for (auto& j : col) {
    for (int i = 0; i < matrix.size(); i++) {
      matrix[i][j] = 0;
    }
  }
}

int main() {
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  setZeroes(matrix);
  return 0;
}