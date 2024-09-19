#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 * @brief 2332_坐上公交的最晚时间
 * https://leetcode.cn/problems/the-latest-time-to-catch-a-bus/description/?envType=daily-question&envId=2024-09-18
 */

int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers,
                          int capacity) {
  std::sort(buses.begin(), buses.end());
  std::sort(passengers.begin(), passengers.end());
  std::map<int, std::vector<int>> mp;
  std::vector<int> vec;
  for (int i = 0; i < buses.size(); i++) {
    mp.insert({buses[i], {}});
  }

  int start = 0;
  for (int i = 0; i < buses.size(); i++) {
    for (int j = start; j < passengers.size(); j++) {
      if (passengers[j] <= buses[i] && mp[buses[i]].size() < capacity) {
        mp[buses[i]].emplace_back(passengers[j]);
        vec.emplace_back(passengers[j]);
        start++;
      } else {
        break;
      }
    }
  }
  int res = 0;
  // 如果最后一班车有空位
  if (mp[buses.back()].size() < capacity) {
    res = buses.back();
  } else {
    res = vec.back();
  }
  int i = vec.size() - 1;
  while (i >= 0 && res == vec[i]) {
    i--;
    res--;
  }
  return res;
}

int main(int argc, char const* argv[]) {
  std::vector<int> buses;
  std::vector<int> passengers;
  int capacity;

  int n, m;
  while (std::cin >> n) {
    buses.emplace_back(n);
    if (std::getchar() == '\n') break;
  }
  while (std::cin >> m) {
    passengers.emplace_back(m);
    if (std::getchar() == '\n') break;
  }
  std::cin >> capacity;

  std::cout << latestTimeCatchTheBus(buses, passengers, capacity) << std::endl;
  return 0;
}
