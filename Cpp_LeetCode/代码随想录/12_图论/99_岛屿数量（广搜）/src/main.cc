#include <iostream>
#include <queue>
#include <vector>

/**
 * @brief kama : 99 岛屿数量(广搜版)
 * https://kamacoder.com/problempage.php?pid=1171
 */
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
void bfs(std::vector<std::vector<int>>& grid,
         std::vector<std::vector<int>>& visited, int x, int y);
int solution(std::vector<std::vector<int>> grid,
             std::vector<std::vector<int>> visited, int x, int y) {
  int count = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (!visited[i][j] && grid[i][j] == 1) {
        count++;
        bfs(grid, visited, i, j);
      }
    }
  }
  return count;
}
void bfs(std::vector<std::vector<int>>& grid,
         std::vector<std::vector<int>>& visited, int x, int y) {
  std::queue<std::pair<int, int>> que;
  que.push(std::pair<int, int>(x, y));
  visited[x][y] = 1;
  while (!que.empty()) {
    auto node = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int nextX = node.first + dir[i][0];
      int nextY = node.second + dir[i][1];
      if (nextX < 0 || nextX >= grid.size() || nextY < 0 ||
          nextY >= grid[0].size()) {
        continue;
      }
      if (!visited[nextX][nextY] && grid[nextX][nextY] == 1) {
        que.push(std::pair<int, int>(nextX, nextY));
        visited[nextX][nextY] = 1;
      }
    }
  }
}

int main(int argc, char const* argv[]) {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> grid(n, std::vector<int>(m, 0));
  std::vector<std::vector<int>> visited(n, std::vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> grid[i][j];
    }
  }

  std::cout << solution(grid, visited, n, m) << std::endl;

  return 0;
}
