// *** 题目描述 ***
/*
已知矿场可以划分成N*M的网格图，每个网格存在地形的差异，因此通过不同网格时，成本开销存在差。
网格有以下5种类型：
1、标志为'S'的网格为起点；
2、标志为'E'的网格为终点；
3、标志为'B'的网格为阻塞点，不允许通行；
4、标志为'C'的网格为检查点，矿车在运输路径中，至少需要进入一次检查点。
5、标志为'数字'的网格，其数字表示经过该网格的成本开销。
运输矿车只能上下左右4个方向运行，不允许斜对角进入其他网格。必要时可重复进入网格。请根据输入的网格图，寻求一条从S网格到E网格，并且至少经过一次检查点C的最低成本运输路径，并输出其成本开销。

输入：
第一行：网格图的行数N（3≤N≤200），和网格图的列数M（3≤M≤200），使用空格隔开。
第2行至第N行：网格图每一行的元素，可以为'S'、'E'、'B'、'C'或者数字（0≤数字≤100），且仅有一个'S'和一个'E'，同时存在一个或多个'C'，依次使用空格隔开。

输出：
第一行，输出运输最低成本开销。如果没有可达通路，请输出-1。

样例1：
输入：
3 3
S 4 5
7 B 3
C 9 E
输出：
16
提示：S->7->C->9->E

样例2：
输入：
3 4
12 B S 13
7 C 4 7
8 3 10 E
输出：
15
提示：S->4->C->4->7->E
*/

#include <bits/stdc++.h>

#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
  int x_;
  int y_;
  int cost_;
  Node(int x, int y, int cost) : x_(x), y_(y), cost_(cost) {}
};

class mycomparision {
 public:
  bool operator()(const Node& a, const Node& b) { return a.cost_ > b.cost_; }
};

int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int main() {
  int m, n;
  std::cin >> m >> n;
  std::vector<std::vector<std::string>> grid(m, std::vector<string>(n, ""));

  string str;

  // 3 3
  // S 4 5
  // 7 B 3
  // C 9 E
  Node start(0, 0, 0), end(0, 0, INT_MAX);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> str;
      if (str == "S") {
        start.x_ = i;
        start.y_ = j;
      } else if (str == "E") {
        end.x_ = i;
        end.y_ = j;
      }
      grid[i][j] = str;
    }
  }

  std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
  std::vector<std::vector<int>> cost(m, std::vector<int>(n, INT_MAX));
  cost[start.x_][start.y_] = 0;

  std::priority_queue<Node, std::vector<Node>, mycomparision> que;

  // 第一次dijkstra
  que.push(start);
  while (!que.empty()) {
    auto cur = que.top();
    que.pop();
    // 3 3
    // S 4 5
    // 7 B 3
    // C 9 E
    if (visited[cur.x_][cur.y_]) continue;
    visited[cur.x_][cur.y_] = true;

    for (int i = 0; i < 4; i++) {
      int nextX = cur.x_ + dir[i][0];
      int nextY = cur.y_ + dir[i][1];
      if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
      if (grid[nextX][nextY] == "B") continue;

      int nextCost = 0;
      if (grid[nextX][nextY] == "C" || grid[nextX][nextY] == "E" ||
          grid[nextX][nextY] == "S") {
        nextCost = 0;
      } else {
        nextCost = std::stoi(grid[nextX][nextY]);
      }
      if (cur.cost_ + nextCost < cost[nextX][nextY]) {
        cost[nextX][nextY] = cur.cost_ + nextCost;
        que.push(Node(nextX, nextY, cur.cost_ + nextCost));
      }
    }
  }

  //   打印cost
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << cost[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  // 第二次dijkstra
  // 重置visited，将所有grid[i][j] == “C” 加入que
  std::vector<Node> Cset;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      visited[i][j] = false;
      if (grid[i][j] == "C") {
        que.push(Node(i, j, cost[i][j]));
        Cset.push_back(Node(i, j, cost[i][j]));
      } else {
        cost[i][j] = INT_MAX;
      }
    }
  }
  std::cout << std::endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << cost[i][j] << " ";
    }
    std::cout << std::endl;
  }

  while (!que.empty()) {
    auto cur = que.top();
    que.pop();
    if (visited[cur.x_][cur.y_]) continue;
    visited[cur.x_][cur.y_] = true;

    for (int i = 0; i < 4; i++) {
      int nextX = cur.x_ + dir[i][0];
      int nextY = cur.y_ + dir[i][1];
      if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
      if (grid[nextX][nextY] == "B") continue;

      int nextCost = 0;
      if (grid[nextX][nextY] == "C" || grid[nextX][nextY] == "E" ||
          grid[nextX][nextY] == "S") {
        nextCost = 0;
      } else {
        nextCost = std::stoi(grid[nextX][nextY]);
      }
      if (cur.cost_ + nextCost < cost[nextX][nextY]) {
        cost[nextX][nextY] = cur.cost_ + nextCost;
        que.push(Node(nextX, nextY, cur.cost_ + nextCost));
      }
    }
  }

  std::cout << std::endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << cost[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
