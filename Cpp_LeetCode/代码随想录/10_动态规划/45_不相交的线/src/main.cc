#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * @brief 1035_不相交的线
 * https://leetcode.cn/problems/uncrossed-lines/description/
 */

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
  // dp[i][j] 表示 nums1[0:i-1] 和 nums2[0:j-1] 的最长子序列
  std::vector<std::vector<int>> dp(nums1.size() + 1,
                                   std::vector<int>(nums2.size() + 1, 0));
  // dp[i][0], dp[0][j]初始化为0

  int res = 0;
  for (int i = 1; i <= nums1.size(); i++) {
    for (int j = 1; j <= nums2.size(); j++) {
      if (nums1[i - 1] == nums2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
      }
      res = std::max(res, dp[i][j]);
    }
  }
  return res;
}

int main(int argc, char const* argv[]) {
  std::vector<int> nums1 = {1, 4, 2};
  std::vector<int> nums2 = {1, 2, 4};
  std::cout << maxUncrossedLines(nums1, nums2) << std::endl;
  return 0;
}
