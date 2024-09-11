#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

/**
 * @brief 17 电话号码的字母组合
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 */

std::string path;
std::vector<std::string> res;
std::map<char, std::string> mp;

void backtracking(std::string& str, int index) {
  if (str.empty()) return;
  if (path.size() == str.size()) {
    res.emplace_back(path);
    return;
  }
  for (int i = index; i < str.size(); i++) {
    char jian = str[i];
    std::string words = mp[jian];
    for (int j = 0; j < words.size(); j++) {
      path.push_back(words[j]);
      backtracking(str, i + 1);
      path.pop_back();
    }
  }
}

std::vector<std::string> letterCombinations(std::string digits) {
  backtracking(digits, 0);
  return res;
}

int main(int argc, char* argv[]) {
  mp['2'] = "abc";
  mp['3'] = "def";
  mp['4'] = "ghi";
  mp['5'] = "jkl";
  mp['6'] = "mno";
  mp['7'] = "pqrs";
  mp['8'] = "tuv";
  mp['9'] = "wxyz";

  std::string str;
  std::cin >> str;
  auto res = letterCombinations(str);

  for (auto& i : res) {
    for (auto& j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
