#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

const int MAP_SIZE = 100;
const double PI = 3.14159265358979323846;
const double EPSILON = 2.0;      // 每次扩展的步长
const double MAX_ITER = 10000;   // 最大迭代次数
const double GOAL_RADIUS = 2.0;  // 判断是否到达目标点的阈值

struct Node {
  double x, y;
  double cost;  // 从起点到该节点的代价
  Node* parent;

  Node(double _x, double _y) : x(_x), y(_y), cost(0), parent(nullptr) {}
};

struct Obstacle {
  double x, y, radius;

  Obstacle(double _x, double _y, double _radius)
      : x(_x), y(_y), radius(_radius) {}

  // 判断一个点是否在障碍物内
  bool isInside(double px, double py) {
    return std::sqrt((px - x) * (px - x) + (py - y) * (py - y)) < radius;
  }
};

std::vector<Obstacle> obstacles;  // 存储所有障碍物

// 随机生成一个新节点
Node* getRandomNode() { return new Node(rand() % MAP_SIZE, rand() % MAP_SIZE); }

// 计算两点之间的欧几里得距离
double distance(Node* n1, Node* n2) {
  return std::sqrt((n1->x - n2->x) * (n1->y - n2->y) +
                   (n1->x - n2->x) * (n1->x - n2->x));
}

// 检查点是否在障碍物中
bool isCollision(double x, double y) {
  for (const auto& obs : obstacles) {
    if (obs.isInside(x, y)) {
      return true;
    }
  }
  return false;
}

// 查找离当前节点最近的树中的节点
Node* getNearestNode(std::vector<Node*>& tree, Node* newNode) {
  Node* nearestNode = nullptr;
  double minDist = std::numeric_limits<double>::max();

  for (auto& node : tree) {
    double dist = distance(node, newNode);
    if (dist < minDist) {
      minDist = dist;
      nearestNode = node;
    }
  }
  return nearestNode;
}

// 扩展树的函数，返回扩展的新节点
Node* extend(Node* nearest, Node* randomNode) {
  double theta =
      std::atan2(randomNode->y - nearest->y, randomNode->x - nearest->x);
  double newX = nearest->x + EPSILON * std::cos(theta);
  double newY = nearest->y + EPSILON * std::sin(theta);

  if (!isCollision(newX, newY)) {
    Node* newNode = new Node(newX, newY);
    newNode->cost = nearest->cost + distance(nearest, newNode);
    newNode->parent = nearest;
    return newNode;
  }
  return nullptr;
}

// 判断是否到达目标
bool isGoalReached(Node* node, Node* goal) {
  return distance(node, goal) < GOAL_RADIUS;
}

// 回溯路径
std::vector<Node*> backtracePath(Node* goalNode) {
  std::vector<Node*> path;
  Node* current = goalNode;
  while (current != nullptr) {
    path.push_back(current);
    current = current->parent;
  }
  std::reverse(path.begin(), path.end());
  return path;
}

// 主RRT*函数
std::vector<Node*> rrt_star(Node* start, Node* goal) {
  std::vector<Node*> tree;
  tree.push_back(start);

  for (int i = 0; i < MAX_ITER; i++) {
    Node* randomNode = getRandomNode();
    Node* nearestNode = getNearestNode(tree, randomNode);
    Node* newNode = extend(nearestNode, randomNode);

    if (newNode) {
      tree.push_back(newNode);
      if (isGoalReached(newNode, goal)) {
        return backtracePath(newNode);
      }
    }
  }
  return {};  // 未找到路径
}

// 显示路径和地图
void displayMap(std::vector<Node*> path) {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      bool isPath = false;
      for (const auto& node : path) {
        if ((int)node->x == i && (int)node->y == j) {
          isPath = true;
          break;
        }
      }

      bool isObstacle = false;
      for (const auto& obs : obstacles) {
        if (obs.isInside(i, j)) {
          isObstacle = true;
          break;
        }
      }

      if (isPath)
        std::cout << "* ";  // 表示路径
      else if (isObstacle)
        std::cout << "O ";  // 表示障碍物
      else
        std::cout << ". ";  // 空白区域
    }
    std::cout << std::endl;
  }
}

int main() {
  srand(time(0));

  // 设置两个圆形障碍物
  obstacles.push_back(Obstacle(25, 25, 15));
  obstacles.push_back(Obstacle(75, 75, 15));

  // 随机生成起点和终点
  Node* start = nullptr;
  Node* goal = nullptr;

  while (!start || isCollision(start->x, start->y)) {
    start = new Node(rand() % MAP_SIZE, rand() % MAP_SIZE);
  }

  while (!goal || isCollision(goal->x, goal->y)) {
    goal = new Node(rand() % MAP_SIZE, rand() % MAP_SIZE);
  }

  std::cout << "Start: (" << start->x << ", " << start->y << ")" << std::endl;
  std::cout << "Goal: (" << goal->x << ", " << goal->y << ")" << std::endl;

  // 执行RRT*算法
  std::vector<Node*> path = rrt_star(start, goal);

  if (!path.empty()) {
    std::cout << "Path found!" << std::endl;
  } else {
    std::cout << "No path found." << std::endl;
  }

  // 输出地图和路径
  displayMap(path);

  return 0;
}
