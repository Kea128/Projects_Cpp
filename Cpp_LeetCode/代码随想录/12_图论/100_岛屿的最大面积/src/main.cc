#include <iostream>
#include <queue>
#include <vector>

/**
 * @brief 100_岛屿最大面积
 * https://kamacoder.com/problempage.php?pid=1172
 */

int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
int maxDao = 0;
void dfs(int n, int m, std::vector<std::vector<int>>& grid, int x, int y,
         std::vector<std::vector<bool>>& visited) {
  if (grid[x][y] == 0 || visited[x][y] == true) {
    return;
  }
  visited[x][y] = true;
  maxDao++;
  for (int i = 0; i < 4; i++) {
    int nextX = x + dir[i][0];
    int nextY = y + dir[i][1];
    if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
      dfs(n, m, grid, nextX, nextY, visited);
    }
  }
}

int calMaxNum(int n, int m, std::vector<std::vector<int>>& grid) {
  std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
  int maxNum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dfs(n, m, grid, i, j, visited);
      maxNum = std::max(maxDao, maxNum);
      maxDao = 0;
    }
  }
  return maxNum;
}

int bfs(int n, int m, std::vector<std::vector<int>>& grid, int x, int y,
        std::vector<std::vector<bool>>& visitedBFS) {
  if (grid[x][y] == 0 || visitedBFS[x][y] == true) return 0;
  int count = 0;
  std::pair<int, int> start({x, y});
  std::queue<std::pair<int, int>> que;
  que.push(start);
  visitedBFS[x][y] = true;
  while (!que.empty()) {
    auto node = que.front();
    que.pop();
    count++;
    for (int i = 0; i < 4; i++) {
      int nextX = node.first + dir[i][0];
      int nextY = node.second + dir[i][1];
      if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
        if (!visitedBFS[nextX][nextY] && grid[nextX][nextY] == 1) {
          que.push(std::pair<int, int>(nextX, nextY));
          visitedBFS[nextX][nextY] = true;
        }
      }
    }
  }
  return count;
}

int calMaxNumBFS(int n, int m, std::vector<std::vector<int>>& grid,
                 std::vector<std::vector<bool>>& visitedBFS) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      count = std::max(bfs(n, m, grid, i, j, visitedBFS), count);
    }
  }
  return count;
}

int main(int argc, char const* argv[]) {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> grid(n, std::vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> grid[i][j];
    }
  }

  // std::cout << calMaxNum(n, m, grid) << std::endl;

  std::vector<std::vector<bool>> visitedBFS(n, std::vector<bool>(m, false));
  std::cout << calMaxNumBFS(n, m, grid, visitedBFS) << std::endl;

  return 0;
}
