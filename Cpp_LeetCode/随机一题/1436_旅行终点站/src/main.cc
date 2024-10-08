#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

/**
 * @brief 1436_旅行终点站
 * https://leetcode.cn/problems/destination-city/
 */

string destCity(vector<vector<string>>& paths) {
  std::map<std::string, std::string> mp;
  for (auto& i : paths) {
    mp[i[0]] = i[1];
  }
  for (auto& i : paths) {
    if (mp.find(i[1]) == mp.end()) {
      return i[1];
    }
  }
  return "";
}

int main(int argc, char const* argv[]) {
  std::vector<vector<string>> paths;
  std::cout << destCity(paths) << std::endl;

  return 0;
}
