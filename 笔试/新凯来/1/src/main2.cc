/**
 * 环境ubuntu20.04
 * 在线IDE编写
 */
#include <iostream>
#include <string>

std::string solution2(std::string& str, int n) {
  int left = 0;
  int right = 0;
  int count = 0;
  std::string res;
  int countstar = 0;
  for (auto& i : str) {
    if (i == '.') countstar++;
  }
  if (n > countstar) return "NULL";

  for (right = 0; right < str.size(); right++) {
    if (str[right] == '.') count++;
    while (count > n) {
      char tmp = str[left];
      if (tmp == '.') count--;
      left++;
    }
  }
  for (int i = left; i <= right; i++) {
    res.push_back(str[i]);
  }
  return res;
}

int main2() {
  std::string str;
  int n;
  std::cin >> str;
  std::cin >> n;
  std::cout << solution(str, n) << std::endl;
}