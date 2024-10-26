#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int to;   // 节点
  int val;  // 权值
  Edge(int t, int v) : to(t), val(v) {}
};

class mycomparison {
 public:
  bool operator()(const std::pair<int, int>& l, const std::pair<int, int>& r) {
    return l.second > r.second;
  }
};

int main() {
  int n, m, p1, p2, val;
  // n个节点，m条路径
  cin >> n >> m;

  // // 邻接矩阵
  // vector<vector<int>> grid1(n + 1, vector<int>(n + 1, INT_MAX));
  // for (int i = 0; i < m; i++) {
  //   cin >> p1 >> p2 >> val;
  //   grid1[p1][p2] = val;
  // }

  // 邻接表: pair<int,int>分别表示 节点 和 指向该节点的这条边的权值
  std::vector<list<Edge>> grid(n + 1);
  for (int i = 0; i < m; i++) {
    std::cin >> p1 >> p2 >> val;
    grid[p1].push_back(Edge(p2, val));
  }

  int start = 1;
  int end = n;

  // 存储从源点到每个节点的最短距离
  std::vector<int> minDist(n + 1, INT_MAX);
  // 记录顶点是否被访问过
  std::vector<bool> visited(n + 1, false);

  // 优先队列中存放 pair<节点编号，源点到该节点的权值>
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      mycomparison>
      pq;

  // 初始化起点距离，并将<起点, 距原点距离>放入优先队列
  minDist[start] = 0;
  pq.push(std::pair<int, int>(start, 0));
  while (!pq.empty()) {
    // 1.取出距离原点最短 且 未访问过的节点
    auto cur = pq.top();
    pq.pop();
    if (visited[cur.first] == true) continue;
    // 2.标记该节点已访问
    visited[cur.first] = true;
    // 3.更新该节点邻接的且未访问过的节点(边) 与 原点的距离
    for (auto edge : grid[cur.first]) {
      if (!visited[edge.to] && cur.second + edge.val < minDist[edge.to]) {
        minDist[edge.to] = cur.second + edge.val;
        pq.push(std::pair<int, int>(edge.to, minDist[edge.to]));
      }
    }
  }

  if (minDist[end] == INT_MAX)
    cout << -1 << endl;  // 不能到达终点
  else
    cout << minDist[end] << endl;  // 到达终点最短路径
  return 0;
}
