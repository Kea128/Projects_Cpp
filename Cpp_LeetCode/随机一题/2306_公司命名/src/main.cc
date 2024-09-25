#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 * @brief 2414_最长的字母序连续子字符串的长度
 * https://leetcode.cn/problems/length-of-the-longest-alphabetical-continuous-substring/description/
 */

int longestContinuousSubstring(string s) {
  int left = 0;
  int right = 1;
  int count = 1;
  int rightMov = 0;
  int max = 1;
  for (; right < s.size(); right++) {
    rightMov++;
    if (s[right] - s[right - 1] == 1) {
      count++;
    } else if (s[right] - s[right - 1] != 1) {
      while (rightMov--) {
        left++;
      }
      rightMov = 0;
      count = 1;
    }
    max = std::max(count, max);
  }
  return max;
}

int main(int argc, char const* argv[]) {
  std::string s;
  std::cin >> s;
  std::cout << longestContinuousSubstring(s) << std::endl;

  return 0;
}
