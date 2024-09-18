#include <iostream>
#include <stack>
#include <string>
#include <vector>

std::string removeStars(std::string s) {
  std::string res;
  for (char& i : s) {
    if (i == '*')
      res.pop_back();
    else
      res.push_back(i);
  }
  return res;
}

int main(int argc, char const* argv[]) {
  std::string str;
  std::cin >> str;

  auto res = removeStars(str);
  std::cout << res << std::endl;

  return 0;
}
