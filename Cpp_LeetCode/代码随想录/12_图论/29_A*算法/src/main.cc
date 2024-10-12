// #include <algorithm>
// #include <cmath>
// #include <iostream>
// #include <queue>
// #include <unordered_map>
// #include <vector>

// using namespace std;

// // 定义坐标结构体
// struct Node {
//   int x, y;  // 节点的坐标
//   int g, h;  // g: 从起点到当前节点的代价, h: 启发式距离(曼哈顿距离)
//   Node* parent;  // 用于追溯路径
//   Node(int x_, int y_, int g_, int h_, Node* parent_ = nullptr)
//       : x(x_), y(y_), g(g_), h(h_), parent(parent_) {}

//   // 计算f值，即g+h，越小优先级越高
//   int f() const { return g + h; }

//   // 重载 < 操作符，使优先队列按 f() 值升序排列
//   bool operator<(const Node& other) const {
//     return this->f() > other.f();  // 小的f值优先
//   }
// };

// // 曼哈顿距离作为启发式函数h
// int heuristic(int x1, int y1, int x2, int y2) {
//   return abs(x1 - x2) + abs(y1 - y2);
// }

// // 检查坐标是否在地图范围内
// bool isValid(int x, int y, const vector<vector<int>>& grid) {
//   return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
//          grid[x][y] == 0;
// }

// // 打印地图
// void printGrid(const vector<vector<int>>& grid) {
//   for (const auto& row : grid) {
//     for (const auto& cell : row) {
//       cout << cell << " ";
//     }
//     cout << endl;
//   }
// }

// // 追溯路径并将路径点标记为2
// void markPath(Node* node, vector<vector<int>>& grid) {
//   while (node) {
//     grid[node->x][node->y] = 2;
//     node = node->parent;
//   }
// }

// // 查找节点是否在open list中，并返回其指针
// Node* findInOpenList(vector<Node>& openList, int x, int y) {
//   for (auto& node : openList) {
//     if (node.x == x && node.y == y) {
//       return &node;
//     }
//   }
//   return nullptr;
// }

// // A* 算法
// void AStar(vector<vector<int>>& grid, pair<int, int> start,
//            pair<int, int> goal) {
//   // 定义八个方向移动: 上、下、左、右和四个对角线方向
//   vector<pair<int, int>> directions = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
//                                        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

//   // open list，优先队列存放节点，按f值排序
//   priority_queue<Node> openList;

//   // 起点
//   Node* startNode =
//       new Node(start.first, start.second, 0,
//                heuristic(start.first, start.second, goal.first,
//                goal.second));
//   openList.push(*startNode);

//   // close list 记录哪些节点已经在close list中
//   vector<vector<bool>> closedList(grid.size(),
//                                   vector<bool>(grid[0].size(), false));

//   // openList的辅助结构，用来避免直接在优先队列中查找
//   vector<Node> openListStorage;

//   // 将起点加入openList
//   openListStorage.push_back(*startNode);

//   while (!openList.empty()) {
//     // 获取 openList 中 f 值最小的节点
//     Node current = openList.top();
//     openList.pop();

//     // 如果找到目标节点，标记路径并打印地图
//     if (current.x == goal.first && current.y == goal.second) {
//       markPath(&current, grid);
//       cout << "Path found:" << endl;
//       printGrid(grid);
//       return;
//     }

//     // 把当前节点加入 closed list
//     closedList[current.x][current.y] = true;

//     // 遍历八个方向
//     for (const auto& dir : directions) {
//       int newX = current.x + dir.first;
//       int newY = current.y + dir.second;

//       // 检查新坐标是否有效且未在 closed list 中
//       if (isValid(newX, newY, grid) && !closedList[newX][newY]) {
//         int newG = current.g + 1;  // 新路径的g值

//         // 检查新坐标是否已经在 open list 中
//         Node* successorInOpen = findInOpenList(openListStorage, newX, newY);
//         if (successorInOpen == nullptr) {
//           // 如果不在 open list 中，创建新的节点
//           int newH = heuristic(newX, newY, goal.first, goal.second);
//           Node* successor = new Node(newX, newY, newG, newH, new
//           Node(current)); openList.push(*successor);
//           openListStorage.push_back(*successor);  // 存储到辅助结构
//         } else if (newG < successorInOpen->g) {
//           // 如果新路径更好，更新 G 和 F 值，设置新的父节点
//           successorInOpen->g = newG;
//           successorInOpen->parent = new Node(current);
//         }
//       }
//     }
//   }

//   // 如果 openList 为空，说明没有找到路径
//   cout << "No path found." << endl;
// }

// int main() {
//   // 5x5 的地图，0表示可通过，1表示障碍物
//   vector<vector<int>> grid = {{0, 0, 0, 0, 0},
//                               {0, 0, 1, 0, 0},
//                               {0, 0, 1, 0, 0},
//                               {0, 0, 1, 0, 0},
//                               {0, 0, 0, 0, 0}};

//   // 起点 (3, 1)，终点 (3, 5)
//   pair<int, int> start = {2, 0};
//   pair<int, int> goal = {1, 4};  // 索引从0开始，第三行第五列就是(3,4)

//   AStar(grid, start, goal);

//   return 0;
// }

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// 定义坐标和角度的结构体
struct State {
  double x, y, theta;  // x, y为坐标, theta为朝向角度
  double g, h;  // g: 从起点到当前节点的代价, h: 启发式距离(曼哈顿距离)
  State* parent;  // 用于追溯路径

  State(double x_, double y_, double theta_, double g_, double h_,
        State* parent_ = nullptr)
      : x(x_), y(y_), theta(theta_), g(g_), h(h_), parent(parent_) {}

  // 计算f值，即g+h，越小优先级越高
  double f() const { return g + h; }

  // 重载 < 操作符，使优先队列按 f() 值升序排列
  bool operator<(const State& other) const {
    return this->f() > other.f();  // 小的f值优先
  }
};

// 计算欧氏距离作为启发式函数h
double heuristic(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// 检查坐标是否在地图范围内
bool isValid(double x, double y, const vector<vector<int>>& grid) {
  int intX = static_cast<int>(floor(x));  // 使用floor避免越界
  int intY = static_cast<int>(floor(y));
  return intX >= 0 && intX < grid.size() && intY >= 0 &&
         intY < grid[0].size() && grid[intX][intY] == 0;
}

// 打印地图
void printGrid(const vector<vector<int>>& grid) {
  for (const auto& row : grid) {
    for (const auto& cell : row) {
      cout << cell << " ";
    }
    cout << endl;
  }
}

// 追溯路径并将路径点标记为2
void markPath(State* state, vector<vector<int>>& grid) {
  while (state) {
    int intX = static_cast<int>(round(state->x));
    int intY = static_cast<int>(round(state->y));
    grid[intX][intY] = 2;
    state = state->parent;
  }
}

// 混合A*的运动模型，基于车辆的转向角度和移动步长
vector<State> getSuccessors(State& current, const vector<vector<int>>& grid,
                            double step_size, double turn_angle) {
  vector<State> successors;

  // 定义三个可能的转向角度：左转、直行、右转
  vector<double> angles = {-turn_angle, 0, turn_angle};

  for (double deltaTheta : angles) {
    double newTheta = current.theta + deltaTheta;         // 新的方向角度
    double newX = current.x + step_size * cos(newTheta);  // 新的x坐标
    double newY = current.y + step_size * sin(newTheta);  // 新的y坐标

    // 如果新状态有效，生成新的状态
    if (isValid(newX, newY, grid)) {
      double newG = current.g + step_size;  // 新的g值
      double newH = heuristic(newX, newY, grid.size() - 1,
                              grid[0].size() - 1);  // 使用欧氏距离作为启发值
      successors.emplace_back(newX, newY, newTheta, newG, newH,
                              &current);  // 添加到successors中
    }
  }

  return successors;
}

// 混合A* 算法
void HybridAStar(vector<vector<int>>& grid, pair<double, double> start,
                 pair<double, double> goal, double step_size,
                 double turn_angle) {
  // 优先队列存放状态，按f值排序
  priority_queue<State> openList;

  // 起点
  State* startState =
      new State(start.first, start.second, 0, 0,
                heuristic(start.first, start.second, goal.first, goal.second));
  openList.push(*startState);

  // close list 记录哪些节点已经在close list中
  vector<vector<bool>> closedList(grid.size(),
                                  vector<bool>(grid[0].size(), false));

  while (!openList.empty()) {
    // 获取 openList 中 f 值最小的节点
    State current = openList.top();
    openList.pop();

    // 如果找到目标节点，标记路径并打印地图
    if (heuristic(current.x, current.y, goal.first, goal.second) < step_size) {
      markPath(&current, grid);
      cout << "Path found:" << endl;
      printGrid(grid);
      return;
    }

    // 把当前节点加入 closed list
    int intX = static_cast<int>(round(current.x));
    int intY = static_cast<int>(round(current.y));
    closedList[intX][intY] = true;

    // 获取所有后继状态
    vector<State> successors =
        getSuccessors(current, grid, step_size, turn_angle);

    for (auto& successor : successors) {
      int newX = static_cast<int>(round(successor.x));
      int newY = static_cast<int>(round(successor.y));

      // 如果后继节点未被访问过
      if (!closedList[newX][newY]) {
        openList.push(successor);
      }
    }
  }

  // 如果 openList 为空，说明没有找到路径
  cout << "No path found." << endl;
}

int main() {
  // 5x5 的地图，0表示可通过，1表示障碍物
  vector<vector<int>> grid = {{0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0}};

  // 起点 (3, 1)，终点 (3, 5)
  pair<double, double> start = {3.0, 0.0};
  pair<double, double> goal = {1.0, 4.0};

  // 车辆的步长和转向角度
  double step_size = 0.5;
  double turn_angle = M_PI / 3;  // 30度

  HybridAStar(grid, start, goal, step_size, turn_angle);

  return 0;
}
