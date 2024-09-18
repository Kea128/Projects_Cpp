#include <iostream>
#include <vector>

/**
 * @brief 1253 重构 2 行二进制矩阵
 * https://leetcode.cn/problems/reconstruct-a-2-row-binary-matrix/solutions/2306023/zhong-gou-2-xing-er-jin-zhi-ju-zhen-by-l-if8v/
 */

std::vector<std::vector<int>> reconstructMatrix(int upper, int lower,
                                                std::vector<int>& colsum) {
  int sum = 0;
  for (int i = 0; i < colsum.size(); i++) {
    sum += colsum[i];
  }
  if (upper + lower != sum) return {};
  int colNums = colsum.size();
  std::vector<std::vector<int>> res(2, std::vector<int>(colNums, 0));
  for (int i = 0; i < colsum.size(); i++) {
    if (upper < 0 || lower < 0) return {};
    if (colsum[i] == 2) {
      res[0][i] = 1;
      res[1][i] = 1;
      upper--;
      lower--;
    } else if (colsum[i] == 0) {
      res[0][i] = 0;
      res[1][i] = 0;
    } else if (colsum[i] == 1) {
      if (upper >= lower) {
        upper--;
        res[0][i] = 1;
      } else {
        lower--;
        res[1][i] = 1;
      }
    }
  }
  return res;
}

int main(int argc, char const* argv[]) {
  int upper, lower;
  std::cin >> upper >> lower;
  std::vector<int> colsum;
  int tmp;
  while (std::cin >> tmp) {
    colsum.emplace_back(tmp);
  }

  std::cout << "结果为: " << std::endl;
  auto res = reconstructMatrix(upper, lower, colsum);

  for (auto& i : res) {
    for (auto& j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
