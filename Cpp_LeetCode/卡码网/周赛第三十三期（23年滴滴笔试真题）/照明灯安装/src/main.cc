#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * @brief 照明灯安装
 * https://kamacoder.com/problemcontest.php?cid=1059&pid=0
 */

// 用贪心
int main() {
  int n, k;
  int light;
  std::cin >> n >> k;
  std::vector<int> position;
  for (int i = 0; i < n; i++) {
    std::cin >> light;
    position.emplace_back(light);
  }
  std::set<int> pos(position.begin(), position.end());

  std::vector<int> dis(n, -1);

  // 首次安装在index = 0
  // 并更新最短距离

  int max_index = 0;
  int max = 0;
  std::set<int> installIndex;
  installIndex.insert(position[0]);
  installIndex.insert(position[n - 1]);
  dis[0] = 0;
  dis[n - 1] = 0;
  if (k <= 2) {
    std::cout << position[n - 1] - position[0] << std::endl;
  } else {
    for (int i = 1; i < n - 1; i++) {
      if (dis[i] != 0) {
        installIndex.insert(position[i]);
        auto it = installIndex.find(position[i]);
        auto it_pre = --it;
        int left = *it_pre;
        it = installIndex.find(position[i]);
        auto it_next = ++it;
        int right = *it_next;
        dis[i] = std::min(position[i] - *it_pre, *it_next - position[i]);
        if (dis[i] > max) {
          max = dis[i];
          max_index = position[i];
        }
        installIndex.erase(position[i]);
      }
    }
    int left_light_num = k - 2;
    int res = 0;
    while (left_light_num--) {
      int index = 0;
      for (int i = 0; i < n; i++) {
        if (position[i] == max_index) {
          index = i;
          break;
        }
      }
      res = dis[index];
      dis[index] = 0;
      max = 0;
      installIndex.insert(max_index);
      for (int i = 0; i < n; i++) {
        if (dis[i] != 0) {
          installIndex.insert(position[i]);
          auto it = installIndex.find(position[i]);
          auto it_pre = --it;
          int left = *it_pre;
          it = installIndex.find(position[i]);
          auto it_next = ++it;
          int right = *it_next;
          dis[i] = std::min(position[i] - *it_pre, *it_next - position[i]);
          if (dis[i] > max) {
            max = dis[i];
            max_index = position[i];
          }
          installIndex.erase(position[i]);
        }
      }
    }
    std::cout << res << std::endl;
  }
  return 0;
}