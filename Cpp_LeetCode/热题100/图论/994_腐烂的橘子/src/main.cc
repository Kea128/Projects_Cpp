#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

/**
 * @brief 994_腐烂的橘子
 * https://leetcode.cn/problems/rotting-oranges/?envType=study-plan-v2&envId=top-100-liked
 */

int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int orangesRotting(vector<vector<int>>& grid) {
  std::queue<std::pair<int, int>> que;
  int time = 0;
  // 遍历grid，把初始即将腐烂的橘子放入que
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == 2) {
        que.push({i, j});
      }
    }
  }
  int minutes = -1;
  while (!que.empty()) {
    minutes++;
    int numsRotted = que.size();
    while (numsRotted--) {
      auto node = que.front();
      que.pop();
      for (int i = 0; i < 4; i++) {
        int nextX = node.first + dir[i][0];
        int nextY = node.second + dir[i][1];
        if (nextX >= 0 && nextX < grid.size() && nextY >= 0 &&
            nextY < grid[0].size()) {
          if (grid[nextX][nextY] == 1) {
            grid[nextX][nextY] = 2;
            que.push({nextX, nextY});
          }
        }
      }
    }
  }
  for (auto& i : grid) {
    for (auto& j : i) {
      if (j == 1) return -1;
    }
  }
  return minutes == -1 ? 0 : minutes;
}

int main(int argc, char const* argv[]) {
  std::vector<std::vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  std::cout << orangesRotting(grid) << std::endl;
  return 0;
}
