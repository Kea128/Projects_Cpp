#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, m, p1, p2, val;
  // n个节点，m条路径
  cin >> n >> m;

  // 邻接矩阵
  vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
  for (int i = 0; i < m; i++) {
    cin >> p1 >> p2 >> val;
    grid[p1][p2] = val;
  }

  // 打印邻接矩阵
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }

  int start = 1;
  int end = n;

  // 第1个到第n个的最短距离，初始化为INT_MAX
  std::vector<int> minDist(n + 1, INT_MAX);

  // 记录是否已经访问过
  std::vector<bool> visited(n + 1, false);

  minDist[start] = 0;
  // 共7个节点，需要取7次
  for (int i = 1; i <= n; i++) {
    int minVal = INT_MAX;
    int cur = 1;

    // 1.遍历所有节点，找到未访问过且距离原点最短的节点
    for (int v = 1; v <= n; ++v) {
      if (!visited[v] && minDist[v] < minVal) {
        minVal = minDist[v];
        cur = v;
      }
    }

    // 2.标记当前节点已经访问
    visited[cur] = true;

    // 3.更新从当前节点出发，到其他未访问节点的最短距离
    for (int v = 1; v <= n; v++) {
      // 未访问过，且有边，且当前路径更短
      if (!visited[v] && grid[cur][v] != INT_MAX &&
          minDist[cur] + grid[cur][v] < minDist[v]) {
        minDist[v] = minDist[cur] + grid[cur][v];
      }
    }

    // 打印日志：
    cout << "select:" << cur << endl;
    for (int v = 1; v <= n; v++) cout << v << ":" << minDist[v] << " ";
    cout << endl << endl;
  }
  if (minDist[end] == INT_MAX)
    cout << -1 << endl;
  else
    cout << minDist[end] << endl;
}
