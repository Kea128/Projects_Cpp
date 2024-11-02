#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

int numDistinct(std::string s, std::string t) {
  std::vector<std::vector<uint64_t>> dp(s.size() + 1,
                                        std::vector<uint64_t>(t.size() + 1));
  for (int i = 0; i < s.size(); i++) {
    dp[i][0] = 1;
  }
  for (int j = 1; j < t.size(); j++) {
    dp[0][j] = 0;
  }
  int res = 0;
  for (int i = 1; i <= s.size(); i++) {
    for (int j = 1; j <= t.size(); j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
      if (j == t.size()) {
        res += dp[i][t.size()];
      }
    }
  }
  //   return dp[s.size()][t.size()];
  return res;
}

// long long solution(std::string& str) {
//   long long res = 0;
//   for (int i = 3; i <= str.size(); i++) {
//     for (int j = 0; j <= str.size() - i; j++) {
//       std::string sub = str.substr(j, i);
//       res += numDistinct(sub, "red");
//       res = res % 1000000007;
//     }
//   }
//   return res;
// }

long long solution(std::string& str) {
  long long res = 0;
  for (int i = 0; i <= str.size() - 3; i++) {
    std::string sub = str.substr(i, str.size() - i);
    res += numDistinct(sub, "red");
    res = res % 1000000007;
  }
  return res;
}

int main(int argc, char const* argv[]) {
  std::string str;
  std::cin >> str;
  std::cout << solution(str) << std::endl;
}
