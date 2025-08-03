#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void solution(std::vector<std::vector<int>>& dianzan,
              std::vector<std::vector<int>>& xunwen, int n) {
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
  for (int i = 0; i < dianzan.size(); i++) {
    dp[dianzan[i][0]][dianzan[i][1]]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        dp[i][j] = std::max(dp[i][j], std::min(dp[i][k], dp[k][j]));
      }
    }
  }

  for (int i = 0; i < xunwen.size(); i++) {
    std::cout << dp[xunwen[i][0]][xunwen[i][1]] << std::endl;
  }
}

int main() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<std::vector<int>> dianzan(m, std::vector<int>(2, 0));
  for (int i = 0; i < m; i++) {
    std::cin >> dianzan[i][0] >> dianzan[i][1];
  }

  std::vector<std::vector<int>> xunwen(q, std::vector<int>(2, 0));
  for (int i = 0; i < q; i++) {
    std::cin >> xunwen[i][0] >> xunwen[i][1];
  }
  solution(dianzan, xunwen, n);
}
