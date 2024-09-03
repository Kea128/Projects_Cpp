#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

/**
 * @brief 438 找到字符串中的所有字母异位词
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/?envType=study-plan-v2&envId=top-100-liked
 */

std::vector<int> findAnagrams(std::string s, std::string p) {
  int n = p.size();
  std::unordered_set<char> window(p.begin(), p.end());
}

int main() {
  std::string str1;
  std::string str2;
  std::cin >> str1;
  std::cin >> str2;

  auto index = findAnagrams(str1, str2);
}