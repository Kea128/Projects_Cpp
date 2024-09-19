#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 * @brief 1184_公交站间的距离
 * https://leetcode.cn/problems/distance-between-bus-stops/description/?envType=daily-question&envId=2024-09-16
 */

int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
  int cost_1 = 0;
  int cost_2 = 0;
  if (start > destination) {
    std::swap(start, destination);
  }

  size_t size = destination - start;
  while (size--) {
    cost_1 += distance[start + size];
  }

  size_t size2 = distance.size() - 1 - destination;
  size_t size3 = start;
  while (size2--) {
    cost_2 += distance[destination + size2];
  }
  while (size3--) {
    cost_2 += distance[0 + size3];
  }
  cost_2 += distance.back();

  return std::min(cost_1, cost_2);
}

int main(int argc, char const* argv[]) {
  std::vector<int> distance;
  int start, destination;
  int tmp;
  while (std::cin >> tmp) {
    distance.emplace_back(tmp);
    if (std::getchar() == '\n') break;
  }
  std::cin >> start;
  std::cin >> destination;

  std::cout << distanceBetweenBusStops(distance, start, destination)
            << std::endl;
}
