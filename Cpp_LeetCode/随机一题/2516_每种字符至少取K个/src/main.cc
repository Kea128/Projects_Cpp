#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * @brief 2414_最长的字母序连续子字符串的长度
 * https://leetcode.cn/problems/length-of-the-longest-alphabetical-continuous-substring/description/
 */

int takeCharacters(string s, int k) {
  int res = s.size();
  int len = s.size();
  std::unordered_map<char, int> mp;
  for (int i = 0; i < s.size(); i++) {
    mp[s[i]]++;
  }
  for (auto& ele : mp) {
    if (ele.second < k) return -1;
  }
  int left = 0;
  for (int right = 0; right < s.size(); right++) {
    mp[s[right]]--;
    while (left < right && (mp['a'] < k || mp['b'] < k || mp['c'] < k)) {
      mp[s[left]]++;
      left++;
    }
    if (mp['a'] >= k && mp['b'] >= k && mp['c'] >= k) {
      res = std::min(res, len - (right - left + 1));
    }
  }
  return res;
}

int main(int argc, char const* argv[]) {
  std::string s;
  std::cin >> s;
  int k;
  std::cin >> k;
  std::cout << takeCharacters(s, k) << std::endl;
  return 0;
}
