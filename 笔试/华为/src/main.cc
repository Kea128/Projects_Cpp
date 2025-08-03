#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 动态规划算法，计算S和T的最长公共子序列长度
int longestCommonSubsequence(const string& S, const string& T) {
  int m = S.length();
  int n = T.length();

  // 创建一个 (m+1) x (n+1) 的 DP 数组，初始值为 0
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  // 填充 DP 数组
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (S[i - 1] == T[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;  // 如果字符相等，LCS长度加1
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // 否则取左或上方向的最大值
      }
    }
  }

  return dp[m][n];  // 最终的 LCS 长度
}

int minMovesToTransform(string S, string T) {
  // 首先判断S和T是否由相同的字符组成
  if (S.length() != T.length()) {
    return -1;
  }

  // 计算最长公共子序列长度
  int lcsLength = longestCommonSubsequence(S, T);

  // 最少移动次数为 S 的长度减去 LCS 长度
  return S.length() - lcsLength;
}

int main() {
  string S, T;
  cout << "请输入字符串S: ";
  cin >> S;
  cout << "请输入字符串T: ";
  cin >> T;

  int result = minMovesToTransform(S, T);
  cout << result << endl;

  return 0;
}
