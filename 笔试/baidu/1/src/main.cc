#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

// //
// int solution(int n, int k) {
//   std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));
//   for (int i = 0; i <= n; i++) {
//     dp[i][0] = 0;
//   }
//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= min(i, k); j++) {
//       if (i > 1)
//         dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + 1);
//       else
//         dp[i][j] = dp[i - 1][j];
//     }
//   }
//   return dp[n][k];
// }
const int mod = 1e9 + 7;

int solution(std::vector<int>& nums) {
  int validNum = nums.size();
  int flag = 1;
  while (validNum != 1) {
    for (int i = 1; i < validNum; i++) {
      if (flag == 1) {
        nums[i - 1] += nums[i];
        flag = 0;
      } else {
        nums[i - 1] -= nums[i];
        flag = 1;
      }
    }
    validNum--;
  }
  if (nums[0] < 0)
    return (nums[0] % mod + mod) % mod;
  else
    return nums[0] % mod;
}

int main(int argc, char const* argv[]) {
  int n;
  std::cin >> n;
  int num;
  std::vector<int> nums;
  while (std::cin >> num) {
    nums.push_back(num);
  }
  std::cout << solution(nums) << std::endl;
}
