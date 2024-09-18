#include <iostream>
#include <list>
#include <vector>

/**
 * @brief kama : 98 所有可达路径
 * https://kamacoder.com/problempage.php?pid=1170
 * @brief leet : 797 所有可能的路径
 * https://leetcode.cn/problems/all-paths-from-source-to-target/description/
 */

std::vector<std::vector<int>> res;
std::vector<int> path;

/**
 * @brief 深度优先搜索
 * @param graph 图（邻接矩阵/邻接表）
 * @param x 当前遍历的节点
 * @param n 终点
 */
void dfs(const std::vector<std::vector<int>>& graph, int x, int n) {
  if (x == n) {
    res.emplace_back(path);
    return;
  }
  for (int i = 1; i <= n; i++) {  // 遍历节点x链接的所有节点
    if (graph[x][i] == 1) {       // 找到x指向的节点i
      path.emplace_back(i);       // 遍历到的节点加入到路径中来
      dfs(graph, i, n);           // 进入下一层递归
      path.pop_back();            // 回溯，撤销本节点
    }
  }
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
  // 邻接矩阵写法
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, 0));
  int s, t;
  for (int i = 0; i < m; i++) {
    std::cin >> s >> t;
    graph[s][t] = 1;
  }
  path.push_back(1);
  dfs(graph, 1, n);

  if (res.empty()) std::cout << -1 << std::endl;
  showVector2D<int>(res);

  // 邻接表写法
  // int n, m;
  // std::cin >> n >> m;
  // std::vector<std::list<int>> graph2(n + 1);
  // int s, t;
  // while (m--) {
  //   std::cin >> s >> t;
  //   graph2[s].emplace_back(t);
  // }

  return 0;
}
