#include <iostream>
#include <string>
using namespace std;

/**
 * @brief 找到从triangle数组从上至下的最短路径
 */

int main(int argc, char const *argv[]) {
  int triangle[4][4] = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  int n = 4;
  int dp[4][4];
  for (int i = 0; i < n; i++) {
    dp[n - 1][i] = triangle[n - 1][i];
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
    }
  }
  cout << dp[0][0] << endl;
  return 0;
}
