#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int lastStoneWeightII(vector<int>& stones) {
  int sums = 0;
  for (auto& i : stones) {
    sums += i;
  }
  int target = sums / 2;
  std::vector<std::vector<int>> dp(stones.size(), std::vector<int>(target, 0));
}

int main(int argc, char const* argv[]) {
  std::vector<int> stones;
  int tmp;
  while (std::cin >> tmp) {
    stones.push_back(tmp);
  }
  return 0;
}
