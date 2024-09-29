#include <iostream>
#include <set>
#include <vector>
using namespace std;

/**
 * @brief 2073_买票需要的时间
 * https://leetcode.cn/problems/time-needed-to-buy-tickets/description/
 */

int timeRequiredToBuy(vector<int>& tickets, int k) {
  int res = 0;
  while (tickets[k] != 0) {
    for (int i = 0; i < tickets.size(); i++) {
      if (tickets[i] == 0) continue;
      res++;
      tickets[i]--;
      if (tickets[k] == 0) {
        break;
      }
    }
  }
  return res;
}

int main(int argc, char const* argv[]) {
  int k;
  std::cin >> k;
  std::vector<int> tickets;
  int n;
  while (std::cin >> n) {
    tickets.emplace_back(n);
  }
  std::cout << timeRequiredToBuy(tickets, k) << std::endl;
}
