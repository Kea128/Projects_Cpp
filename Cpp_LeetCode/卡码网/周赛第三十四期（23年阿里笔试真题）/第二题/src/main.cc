#include <iostream>
#include <map>
#include <string>

int solution(std::string& str) {
  if (str.size() <= 2) return 0;
  // 先单独处理 aaa 情况
  std::string str2(str.begin(), str.begin() + 2);
  int count = 0;
  for (int i = 2; i < str.size(); i++) {
    if (str[i] == str[i - 1] && str[i] == str[i - 2]) {
      count++;
    } else {
      str2.push_back(str[i]);
    }
  }

  int index = 0;
  for (int j = 1; j < str2.size() - 2; j++) {
    if (str2[j - 1] == str2[j] && str2[j + 1] != str2[j] &&
        str2[j + 1] == str2[j + 2]) {
      if (j != index) {
        count++;
        index = j + 2;
      }
    }
  }
  return count;
}

int main(int argc, char const* argv[]) {
  std::string str;
  std::cin >> str;
  std::cout << solution(str) << std::endl;
  return 0;
}
