#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

struct Test {
  string str;
  int n;
  int q;
  std::vector<std::vector<std::string>> operations;
};

int calc(string& str, int l, int r) {
  int res = 0;
  string sub = str.substr(l, r - l + 1);
  sort(sub.begin(), sub.end());
  char maxS = sub.back();
  return res;
}

void solution(Test& test) {
  string str = test.str;
  std::vector<std::vector<std::string>> operations = test.operations;
  for (int i = 0; i < test.q; i++) {
    string a = operations[i][0];
    string b = operations[i][1];
    string c = operations[i][2];
    if (a == "1") {
      int index = stoi(b) - 1;
      str[index] = c[0];
    } else {
      calc(str, stoi(b) - 1, stoi(c) - 1);
    }
  }
}

int main(int argc, char const* argv[]) {
  int T;
  std::cin >> T;
  while (T--) {
    Test test;
    int n, q;
    std::string str;
    std::cin >> n >> q;
    std::cin >> str;
    test.str = str;
    test.n = n;
    test.q = q;
    std::string a, b, c;
    for (int i = 0; i < q; i++) {
      std::cin >> a >> b >> c;
      test.operations.push_back({a, b, c});
    }
    solution(test);
  }
  return 0;
}
