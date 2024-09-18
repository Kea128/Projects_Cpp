#include <iostream>
#include <set>
#include <vector>

/**
 * @brief 2848_与车相交的点
 * https://leetcode.cn/problems/points-that-intersect-with-cars/
 */

int numberOfPoints(std::vector<std::vector<int>>& nums) {
  std::set<int> st;
  int count = 0;
  for (int i = 0; i < nums.size(); i++) {
    for (int index = nums[i][0]; index <= nums[i][1]; index++) {
      if (st.find(index) == st.end()) {
        count++;
        st.insert(index);
      } else {
        continue;
      }
    }
  }
  return count;
}

int main(int argc, char const* argv[]) {
  int left, right;
  std::vector<int> level;
  std::vector<std::vector<int>> nums;

  while (std::cin >> left >> right) {
    level = {left, right};
    nums.emplace_back(level);
  }

  std::cout << numberOfPoints(nums) << std::endl;

  return 0;
}
