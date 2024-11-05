// #include <algorithm>
// #include <iostream>
// #include <map>
// #include <set>
// #include <sstream>
// #include <vector>
// using namespace std;

// int main(int argc, char const* argv[]) {
//   int n;
//   std::cin >> n;
//   std::string str;
//   std::vector<std::string> strs;
//   while (n--) {
//     std::cin >> str;
//     strs.push_back(str);
//   }

//   // 求前i个字符串的最长公共前缀
//   std::vector<std::string> dp(strs.size(), "");
//   dp[0] = strs[0];
//   for (int i = 1; i < strs.size(); i++) {
//     for (int j = 0; j < min(dp[i - 1].size(), strs[i].size()); j++) {
//       if (dp[i - 1][j] == strs[i][j]) {
//         dp[i] += dp[i - 1][j];
//       } else {
//         break;
//       }
//     }
//   }

//   for (auto& k : dp) {
//     if (k == "") {
//       std::cout << -1 << std::endl;
//     } else {
//       std::cout << k << std::endl;
//     }
//   }
//   return 0;
// }
