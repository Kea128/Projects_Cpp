#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * @brief 438 找到字符串中的所有字母异位词(未解决)
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/?envType=study-plan-v2&envId=top-100-liked
 */

// 超时
std::vector<int> findAnagrams_V1(std::string s, std::string p) {
  int n = p.size();
  // unordered_map存储p的字符及出现次数
  std::unordered_map<char, int> mp;
  std::vector<int> res;
  for (const char& ele : p) {
    mp[ele]++;
  }

  int n_bk = n;
  for (int right = n_bk - 1; right < s.size(); right++) {
    std::unordered_map<char, int> mp_bk = mp;
    while (n_bk--) {
      auto it = mp_bk.find(s[right - n_bk]);
      if (it != mp_bk.end()) {
        mp_bk[s[right - n_bk]]--;
      }
    }
    n_bk = n;
    int count = 0;
    for (const auto& ele : mp_bk) {
      if (ele.second != 0) {
        break;
      }
      count++;
    }
    if (count == mp_bk.size()) {
      res.emplace_back(right - n + 1);
    }
  }

  return res;
}

std::vector<int> findAnagrams_V2(std::string s, std::string p) {
  int n = p.size();
  // unordered_map存储p的字符及出现次数
  std::unordered_map<char, int> mp;
  std::vector<int> res;
  for (const char& ele : p) {
    mp[ele]++;
  }

  for (int right = n - 1; right < s.size(); right++) {
    std::unordered_map<char, int> window;
    for (int left = right - n + 1; left <= right; left++) {
      window[s[left]]++;
    }
    if (mp == window) {
      res.emplace_back(right - n + 1);
    }
  }
  return res;
}

int main() {
  std::string str1;
  std::string str2;
  std::cin >> str1;
  std::cin >> str2;

  auto index = findAnagrams_V2(str1, str2);
  for (auto i : index) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}