#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 * @brief 118_杨辉三角
 * https://leetcode.cn/problems/pascals-triangle/?envType=study-plan-v2&envId=top-100-liked
 */

vector<vector<int>> generate(int numRows) {
  std::vector<std::vector<int>> ret(numRows, std::vector<int>(numRows, 1));
  for (int i = 2; i < numRows; ++i) {
    for (int j = 1; j < i; ++j) {
      ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
    }
  }
  std::vector<std::vector<int>> res;
  std::vector<int> level;
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j <= i; ++j) {
      level.push_back(ret[i][j]);
    }
    res.push_back(level);
    level.clear();
  }
  return res;
}

int main(int argc, char const* argv[]) {
  int numRows;
  std::cin >> numRows;
  std::cout << generate(numRows) << std::endl;
  return 0;
}
