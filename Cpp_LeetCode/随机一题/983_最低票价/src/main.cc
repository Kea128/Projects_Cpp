#include <iostream>
#include <set>
#include <vector>
using namespace std;

/**
 * @brief 983_最低票价
 * https://leetcode.cn/problems/minimum-cost-for-tickets/description/
 */

int mincostTickets(vector<int>& days, vector<int>& costs) {
  int res = 0;
  std::set<int> st(days.begin(), days.end());
  std::vector<int> dp(days.back() + 1, 0);
  // dp初始化
  dp[0] = 0;
  for (int i = 1; i <= days.back(); i++) {
    if (st.find(i) == st.end()) {
      dp[i] = dp[i - 1];
    } else {
      dp[i] = std::min(
          std::min(dp[max(i - 1, 0)] + costs[0], dp[max(i - 7, 0)] + costs[1]),
          dp[max(i - 30, 0)] + costs[2]);
    }
  }
  return dp[days.back()];
}

int main(int argc, char const* argv[]) {
  std::vector<int> days = {1, 4, 6, 7, 8, 20};
  std::vector<int> costs = {2, 7, 15};
  std::cout << mincostTickets(days, costs) << std::endl;
}
