#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 131_分割回文串
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 */

std::vector<std::string> path;
std::vector<std::vector<string>> res;

bool isPa(std::string str, int i, int j) {
  std::string sub = str.substr(i, j - i + 1);
  std::string sub2 = sub;
  std::reverse(sub2.begin(), sub2.end());
  if (sub == sub2) {
    return true;
  }
  return false;
}

void backtracking(std::string str, int startIndex) {
  if (startIndex == str.size()) {
    res.emplace_back(path);
    return;
  }
  for (int i = startIndex; i < str.size(); i++) {
    //[startIndex, i]之间为子串
    if (isPa(str, startIndex, i)) {
      std::string sub = str.substr(startIndex, i - startIndex + 1);
      path.emplace_back(sub);
    } else {
      continue;
    }
    backtracking(str, i + 1);
    path.pop_back();
  }
}

vector<vector<string>> partition(string s) {
  backtracking(s, 0);
  return res;
}

int main(int argc, char const* argv[]) {
  std::string str;
  std::cin >> str;

  auto ans = partition(str);
  for (auto& v : ans) {
    for (auto& i : v) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}
