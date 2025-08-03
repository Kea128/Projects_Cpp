#include <algorithm>

#include <climits>

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
using namespace std;


std::vector<int> path;
std::vector<std::vector<int>> chooseIndex;

void dfs(int n, int k, int start) {
  if (path.size() == k) {
    chooseIndex.push_back(path);
    return;
  }
  for (int i = start; i < n; i++) {
    path.push_back(i);
    dfs(n, k, i + 1);
    path.pop_back();
  }
}

int solution(int n, int m, int k, std::vector<std::vector<int>>& shuxing) {
  int res = INT_MAX;
  // 外层遍历属性，内层遍历人选
  for (int j = 0; j < m; j++) {
    int danMax = 0;
    for (int i = 0; i < n; i++) {
      danMax = max(danMax, shuxing[i][j]);
    }
    res = min(res, danMax);
  }

  return res;
}

int main(int argc, char const* argv[]) {
  int T;
  std::cin >> T;
  while (T--) {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> shuxing(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cin >> shuxing[i][j];
      }
    }
    chooseIndex.clear();
    path.clear();
    dfs(n, k, 0);
    int ress = INT_MIN;
    for (int i = 0; i < chooseIndex.size(); i++) {
      std::vector<std::vector<int>> shuxing2;
      for (int j = 0; j < k; j++) {
        shuxing2.emplace_back(shuxing[chooseIndex[i][j]]);
      }
      ress = max(ress, solution(n, m, k, shuxing2));
    }
    std::cout << ress << std::endl;
  }
  return 0;
}

