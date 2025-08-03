#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// 地图上下左右四个方向
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

std::vector<int> path;                // 存储当前路径
std::vector<std::vector<int>> paths;  // 存储所有路径

void dfs(std::vector<std::vector<int>>& map, int x, int y) {
  // 遍历周围四个节点
  path.push_back(map[x][y]);
  for (int i = 0; i < 4; ++i) {
    int nextx = x + dir[i][0];
    int nexty = y + dir[i][1];
    if (nextx >= 0 && nextx < map.size() && nexty >= 0 &&
        nexty < map[0].size() && map[nextx][nexty] > map[x][y]) {
      dfs(map, nextx, nexty);
      path.pop_back();
    }
  }
  paths.push_back(path);
}

int solution(std::vector<std::vector<int>>& map) {
  // 遍历map上的每个点作为起点
  int maxPathLength = 0;  // 最长递增路径的长度
  for (int i = 0; i < map.size(); ++i) {
    for (int j = 0; j < map[0].size(); ++j) {
      path.clear();
      paths.clear();
      dfs(map, i, j);
      // 获取paths中最长路径长度
      for (auto& p : paths) {
        if (p.size() > maxPathLength) {
          maxPathLength = p.size();
        }
      }
    }
  }
  return maxPathLength;
}

int main(int argc, char const* argv[]) {
  std::string line;
  std::vector<std::vector<int>> map;

  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);
    std::vector<int> row;
    int val;

    while (iss >> val) {
      row.push_back(val);
    }
    if (!row.empty()) {
      map.push_back(row);
    }
  }

  std::cout << solution(map) << std::endl;
  return 0;
}
