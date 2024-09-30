#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief 51_N皇后
 * https://leetcode.cn/problems/n-queens/description/
 */

std::vector<std::string> path;  // path为棋盘
std::vector<std::vector<std::string>> res;

bool isValid(int row, int col, vector<string>& chessboard, int n) {
  // 检查列
  for (int i = 0; i < row; i++) {  // 这是一个剪枝
    if (chessboard[i][col] == 'Q') {
      return false;
    }
  }
  // 检查 45度角是否有皇后
  for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
    if (chessboard[i][j] == 'Q') {
      return false;
    }
  }
  // 检查 135度角是否有皇后
  for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
    if (chessboard[i][j] == 'Q') {
      return false;
    }
  }
  return true;
}

void backtracking(int n, int row) {
  if (row == n) {
    res.emplace_back(path);
    return;
  }
  for (int j = 0; j < n; j++) {  // j表示列
    if (isValid(row, j, path, n)) {
      path[row][j] = 'Q';
      backtracking(n, row + 1);
      path[row][j] = '.';
    }
  }
}

vector<vector<string>> solveNQueens(int n) {
  res.clear();
  path.resize(n, std::string(n, '.'));
  backtracking(n, 0);
  return res;
}

int main() {
  int n;
  std::cin >> n;
  auto res = solveNQueens(n);
  for (auto& i : res) {
    for (auto& j : i) {
      std::cout << j << std::endl;
    }
    std::cout << std::endl;
  }
}