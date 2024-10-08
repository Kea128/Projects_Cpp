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

vector<int> spiralOrder(vector<vector<int>>& matrix) {}

int main() {
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int>::iterator it = nums.end();
  nums.push_back(5);

  for (auto it = nums.begin(); it != nums.end(); ++it) {
    std::cout << *it << std::endl;
  }

  // std::cout << *it << std::endl;
  // std::cout << *(it - 1) << std::endl;

  return 0;
}