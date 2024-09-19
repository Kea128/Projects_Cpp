
#include <iostream>
#include <string>
#include <vector>

// 深搜

std::string path;
std::vector<std::string> VEC;
bool flag = false;
void dfs(std::string& S, std::vector<std::string>& T, int start) {
  if (path.size() > S.size()) {
    return;
  }
  if (path == S) {
    VEC.emplace_back(path);
    flag = true;
    return;
  }
  for (int i = start; i < T.size(); i++) {
    int size = T[i].size();
    path += T[i];
    dfs(S, T, start);
    while (size--) {
      path.pop_back();
    }
    start++;
  }
}

bool solution(std::string& S, std::vector<std::string>& T) {
  for (int i = 0; i < T.size(); i++) {
    if (S == T[i]) return true;
  }
  dfs(S, T, 0);

  return flag;
}

int main(int argc, char const* argv[]) {
  std::string S;
  std::cin >> S;
  std::string tmp;
  std::vector<std::string> T;
  while (std::cin >> tmp) {
    T.emplace_back(tmp);
  }
  std::cout << solution(S, T) << std::endl;

  // std::string a = "abc";
  // std::string b = "c";
  // std::cout << a + b << std::endl;
  return 0;
}
