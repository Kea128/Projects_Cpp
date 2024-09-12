#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

/**
 * @brief 455分发饼干
 * https://leetcode.cn/problems/assign-cookies/
 */

int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());
  int count = 0;
  int j = s.size() - 1;
  if (s.empty() || g.empty()) return 0;
  for (int i = g.size() - 1; i >= 0; i--) {
    if (g[i] <= s[j]) {
      j--;
      count++;
    }
    if (j < 0) return count;
  }
  return count;
}

int main(int argc, char const* argv[]) {
  int n;
  std::vector<int> weikou;
  std::vector<int> binggan;

  while (std::cin >> n) {
    weikou.emplace_back(n);
    if (std::getchar() == '\n') break;
  }
  while (std::cin >> n) {
    binggan.emplace_back(n);
  }

  //   for (auto& i : weikou) {
  //     std::cout << i << " ";
  //   }
  //   std::cout << "以上为胃口" << std::endl;
  //   for (auto& i : binggan) {
  //     std::cout << i << " ";
  //   }
  //   std::cout << "以上为饼干" << std::endl;

  std::cout << findContentChildren(weikou, binggan) << std::endl;

  return 0;
}
