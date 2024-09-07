#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * @brief 162_小红的第16版方案
 * https://kamacoder.com/problempage.php?pid=1240
 */

int main() {
  // n表示人数，m表示修改次数
  int n, m;
  std::cin >> n >> m;

  // angerThreld为愤怒阈值
  std::vector<int> angerThreld;
  int tmp;
  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    angerThreld.emplace_back(tmp);
  }

  // std::vector<std::vector<int>> range;
  // int range[m][2];
  std::vector<std::vector<int>> range(m, std::vector<int>(2));
  std::vector<int> hang;

  // for (int i = 0; i < m; i++) {
  //   for (int j = 0; j < n; j++) {
  //     std::cin >> tmp;
  //     hang.emplace_back(tmp);
  //     if (std::getchar() == '\n') {
  //       range.emplace_back(hang);
  //       hang.clear();
  //     }
  //   }
  // }

  int left, right;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      std::cin >> tmp;
      range[i][j] = tmp;
    }
  }

  bool stop = false;
  int res = 0;
  std::vector<int> anger(n, 0);
  for (int i = 1; i <= m; i++) {
    int l = range[i - 1][0];
    int r = range[i - 1][1];
    for (int j = l - 1; j < r; j++) {
      anger[j]++;
    }

    for (int j = 0; j < n; j++) {
      if (anger[j] > angerThreld[j]) {
        stop = true;
        break;
      }
    }
    if (stop) {
      res = i - 1;
      break;
    }
    res++;
  }
  std::cout << res << std::endl;
}