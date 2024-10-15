// #include <algorithm>
// #include <iostream>
// #include <map>
// #include <set>
// #include <sstream>
// #include <vector>
// using namespace std;

// // //
// // int solution(int n, int k) {
// //   std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));
// //   for (int i = 0; i <= n; i++) {
// //     dp[i][0] = 0;
// //   }
// //   for (int i = 1; i <= n; i++) {
// //     for (int j = 1; j <= min(i, k); j++) {
// //       if (i > 1)
// //         dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + 1);
// //       else
// //         dp[i][j] = dp[i - 1][j];
// //     }
// //   }
// //   return dp[n][k];
// // }

// int solution(int n, int k) {
//   if (k <= (n + 1) / 2) {
//     return k;
//   } else {
//     int value = (n + 1) / 2;
//     int m = k - value;
//     if (m == 1)
//       return value - 2;
//     else
//       return (value - 2 - (m - 1));
//   }
// }

// int main(int argc, char const* argv[]) {
//   int T;
//   std::cin >> T;
//   int n, k;
//   for (int t = 0; t < T; t++) {
//     std::cin >> n >> k;
//     std::cout << solution(n, k) << std::endl;
//   }
//   return 0;
// }
