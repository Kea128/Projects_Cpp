
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> solution(int n, int m,
                                  std::vector<std::string>& strs) {
  for (int i = 0; i < n; ++i) {
    std::string str = strs[i];
    if (str.size() < 3) {
    }
  }
}

int main(int argc, char const* argv[]) {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> strs(n, "");
  for (int i = 0; i < n; ++i) {
    std::cin >> strs[i];
  }

  return 0;
}
