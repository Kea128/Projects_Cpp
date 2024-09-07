#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief 344 反转字符串
 * https://leetcode.cn/problems/reverse-string/description/
 */

void reverseString(std::vector<char>& s) {
  for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
    std::swap(s[i], s[j]);
  }
}

int main(int argc, char* argv[]) {
  char s;
  std::vector<char> str;
  while (std::cin >> s) {
    str.emplace_back(s);
  }

  reverseString(str);
  for (auto& i : str) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
