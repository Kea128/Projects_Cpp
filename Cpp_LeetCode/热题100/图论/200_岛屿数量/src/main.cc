#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

/**
 * @brief 200_岛屿数量
 * https://leetcode.cn/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-100-liked
 */

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// 方法1：dfs
void dfs(std::vector<std::vector<char>>& grid,
         std::vector<std::vector<bool>>& visited, int x, int y) {
  if (visited[x][y]) return;
  if (grid[x][y] == '0') return;
  if (grid[x][y] == '1' && visited[x][y] == false) visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nextX = x + dir[i][0];
    int nextY = y + dir[i][1];
    if (nextX >= 0 && nextX < grid.size() && nextY >= 0 &&
        nextY < grid[0].size()) {
      dfs(grid, visited, nextX, nextY);
    }
  }
}

// 方法2：bfs
void bfs(std::vector<std::vector<char>>& grid,
         std::vector<std::vector<bool>>& visited, int x, int y) {
  std::queue<std::pair<int, int>> que;
  visited[x][y] = true;
  que.push({x, y});
  while (!que.empty()) {
    std::pair<int, int> node = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int nextX = node.first + dir[i][0];
      int nextY = node.second + dir[i][1];
      if (nextX >= 0 && nextX < grid.size() && nextY >= 0 &&
          nextY < grid[0].size()) {
        if (grid[nextX][nextY] == '1' && visited[nextX][nextY] == false) {
          visited[nextX][nextY] = true;
          que.push({nextX, nextY});
        }
      }
    }
  }
}

int numIslands(vector<vector<char>>& grid) {
  std::vector<std::vector<bool>> visited(
      grid.size(), std::vector<bool>(grid[0].size(), false));
  int res = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == '1' && visited[i][j] == false) {
        res++;
        // dfs(grid, visited, i, j);
        bfs(grid, visited, i, j);
      }
    }
  }
  return res;
}

int main(int argc, char const* argv[]) {
  std::vector<std::vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                         {'1', '1', '0', '0', '0'},
                                         {'0', '0', '1', '0', '0'},
                                         {'0', '0', '0', '1', '1'}};

  std::cout << numIslands(grid) << std::endl;

  return 0;
}
