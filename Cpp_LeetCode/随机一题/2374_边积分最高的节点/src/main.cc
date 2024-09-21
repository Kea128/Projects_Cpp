#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

/**
 * @brief 2374_边积分最高的节点
 * https://leetcode.cn/problems/points-that-intersect-with-cars/
 */

// int edgeScore(vector<int>& edges) {
//   std::vector<int> mp(edges.size(), 0);
//   for (int i = 0; i < edges.size(); i++) {
//     mp[edges[i]] += i;
//   }
//   int max = 0;
//   int res = 0;
//   for (int j = 0; j < mp.size(); j++) {
//     if (mp[j] > max) {
//       max = mp[j];
//       res = j;
//     }
//   }
//   return res;
// }

int edgeScore(vector<int>& edges) {
  int n = edges.size(), ans = 0;
  vector<long long> score(n);
  for (int i = 0; i < n; i++) {
    int to = edges[i];
    score[to] += i;
    if (score[to] > score[ans] || score[to] == score[ans] && to < ans) {
      ans = to;
    }
  }
  return ans;
}

int main(int argc, char const* argv[]) {
  std::vector<int> edges;

  int tmp;
  while (std::cin >> tmp) {
    edges.emplace_back(tmp);
  }

  std::cout << edgeScore(edges) << std::endl;

  return 0;
}
