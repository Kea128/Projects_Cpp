#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 56_合并区间
 * https://leetcode.cn/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-100-liked
 */

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  // 这里排序直接按二维数组每行首元素排序
  std::sort(intervals.begin(), intervals.end());
  std::vector<std::vector<int>> res;
  res.emplace_back(intervals[0]);
  for (int i = 1; i < intervals.size(); i++) {
    auto it = intervals[i];
    if (it[0] >= res.back()[0] && it[0] <= res.back()[1]) {
      res.back()[1] = std::max(res.back()[1], it[1]);
    } else {
      res.emplace_back(it);
    }
  }
  return res;
}

int main() {
  std::vector<std::vector<int>> intervals = {{2, 6}, {1, 3}, {8, 10}, {15, 18}};
  auto res = merge(intervals);
  return 0;
}
