#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief 2207_字符串中最多数目的子序列
 * https://leetcode.cn/problems/maximize-number-of-subsequences-in-a-string/description/
 */

long long maximumSubsequenceCount(string text, string pattern) {
  int count1 = 0;
  int count2 = 0;
  int oriNum = 0;
  for (int i = 0; i < text.size(); i++) {
    if (text[i] == pattern[1]) {
      count2++;
      oriNum += count1;
    }
    if (text[i] == pattern[0]) {
      count1++;
    }
  }
  return (long long)(std::max(count1, count2) + oriNum);
}

int main(int argc, char const* argv[]) {
  string text;
  string pattern;
  std::cin >> text >> pattern;

  std::cout << maximumSubsequenceCount(text, pattern) << std::endl;
  return 0;
}
