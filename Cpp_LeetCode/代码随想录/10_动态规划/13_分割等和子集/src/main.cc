#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool solution(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  int sum = 0;
  for (auto& i : nums) sum += i;
  if (sum % 2 == 1) return false;
  int target = sum / 2;
  // dp数组
  std::vector<std::vector<int>> dp(nums.size(),
                                   std::vector<int>(target + 1, 0));
  // dp初始化
  dp[0][0] = 0;
  for (int j = 1; j <= target; j++) {
    if (j >= nums[0])
      dp[0][j] = nums[0];
    else
      dp[0][j] = 0;
  }
  for (int i = 1; i < nums.size(); i++) {
    dp[i][0] = 0;
  }
  for (int i = 1; i < nums.size(); i++) {
    for (int j = 1; j <= target; j++) {
      if (j >= nums[i])
        dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
      else
        dp[i][j] = dp[i - 1][j];
    }
    if (dp[i][target] == target) return true;
  }
  return false;
}

int main(int argc, char const* argv[]) {
  int tmp;
  std::vector<int> nums;
  while (std::cin >> tmp) {
    nums.emplace_back(tmp);
  }
  std::cout << solution(nums) << std::endl;
  return 0;
}
