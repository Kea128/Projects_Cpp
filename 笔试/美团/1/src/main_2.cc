// // #include <algorithm>
// // #include <iostream>
// // #include <map>
// // #include <set>
// // #include <sstream>
// // #include <vector>
// // using namespace std;

// // int solution(int n) {
// //   std::vector<int> dp(n + 1, 0);
// //   dp[1] = 1;
// //   dp[2] = 2;
// //   dp[3] = 3;
// //   dp[4] = 4;
// //   for (int i = 5; i <= n; i++) {
// //     // 奇数
// //     if (i % 2 == 1) {
// //         dp[i] = dp[i/2 + 1] + 1;
// //     } else {
// //         dp[i] = dp[i/2 + 1] + 1;
// //     }
// //   }
// //   int res = dp[n];
// //   return res;
// // }

// // int main(int argc, char const* argv[]) {
// //   int T;
// //   std::cin >> T;
// //   while (T--) {
// //     int n;
// //     std::cin >> n;
// //     std::cout << solution(n) << std::endl;
// //   }
// // }

// #include <algorithm>
// #include <iostream>
// #include <map>
// #include <set>
// #include <sstream>
// #include <vector>
// using namespace std;

// void solution(int n, std::vector<int>& dp) {
//   dp[1] = 1;
//   dp[2] = 2;
//   dp[3] = 3;
//   dp[4] = 4;
//   for (int i = 5; i <= n; i++) {
//     dp[i] = dp[i / 2 + 1] + 1;
//   }
// }

// int main(int argc, char const* argv[]) {
//   int T;
//   std::cin >> T;

//   std::vector<int> nums(T, 0);
//   int n;
//   int nMax = 0;
//   for (int i = 0; i < T; i++) {
//     std::cin >> n;
//     nMax = std::max(nMax, n);
//     nums[i] = n;
//   }
//   std::vector<int> dp(nMax + 1, 0);
//   solution(nMax, dp);
//   for (auto& k : nums) {
//     std::cout << dp[k] << std::endl;
//   }
//   return 0;
// }
