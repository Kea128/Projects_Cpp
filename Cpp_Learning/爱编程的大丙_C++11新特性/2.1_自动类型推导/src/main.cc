#include <iostream>
#include <map>
#include <string>

int main() {
  // auto x = 3.14;
  // auto y = 3;
  // auto z = 'a';

  // int temp = 110;
  // auto *a = &temp;
  // auto b = &temp;
  // auto d = temp;

  // // 有const修饰
  // int tmp = 250;
  // const auto a1 = tmp;
  // auto a2 = a1;
  // const auto &a3 = tmp;
  // auto &a4 = a3;

  std::map<int, std::string> mp;
  mp.insert(std::pair<int, std::string>(1, "a"));
  mp.insert(std::pair<int, std::string>(2, "b"));
  mp.insert(std::pair<int, std::string>(3, "c"));

  for (auto it = mp.begin(); it != mp.end(); ++it) {
    std::cout << it->first << " " << it->second << std::endl;
  }

  return 0;
}