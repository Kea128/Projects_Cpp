#include <iostream>
#include <list>
#include <vector>

/**
 * @brief kama : 99 岛屿数量
 * https://kamacoder.com/problempage.php?pid=1171
 */

std::vector<std::vector<int>> res;
std::vector<int> path;

// 右下上左
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

/**
 * @brief 深度优先搜索
 * @param grid 图
 * @param visited 已经访问的陆地
 * @param x 当前坐标点x
 * @param y 当前坐标点y
 */
void dfs(std::vector<std::vector<int>>& grid,
         std::vector<std::vector<bool>>& visited, int x, int y) {
  if (visited[x][y] == true || grid[x][y] == 0) return;
  if (grid[x][y] == 1) visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nextX = x + dir[i][0];
    int nextY = y + dir[i][1];
    // 坐标为有效
    if (nextX >= 0 && nextX < grid.size() && nextY >= 0 &&
        nextY < grid[0].size()) {
      dfs(grid, visited, nextX, nextY);
    }
  }
}

int solution(int n, int m, std::vector<std::vector<int>>& grid,
             std::vector<std::vector<bool>>& visited) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // 是陆地且没访问过
      if (!visited[i][j] && grid[i][j] == 1) {
        count++;
      }
      dfs(grid, visited, i, j);
    }
  }
  return count;
}

template <class T>
void showVector2D(std::vector<std::vector<T>>& vec) {
  for (auto& level : vec) {
    for (int i = 0; i < level.size() - 1; i++) {
      std::cout << level[i] << " ";
    }
    std::cout << level[level.size() - 1] << std::endl;
  }
}

int main(int argc, char const* argv[]) {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> grid(
      n, std::vector<int>(m, 0));  // 这里注意需要先指定大小
  std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> grid[i][j];
    }
  }

  std::cout << solution(n, m, grid, visited) << std::endl;

  return 0;
}
