#include <iostream>
#include <map>
#include <vector>

int solution(int n, std::vector<int> parents, std::vector<int> quanzhi) {
  int count = 0;
  count += n;
  std::map<int, std::vector<int>> mp;
  for (int i = 0; i < parents.size(); i++) {
    mp[parents[i]].emplace_back(i + 2);
  }

  for (auto& level : mp) {
    int num = level.second.size();
    while (num--) {
      if (quanzhi[level.first - 1] != quanzhi[level.second[num] - 1]) {
        count++;
      }
    }
  }
  return count;
}

int main(int argc, char const* argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> parents;
  int tmp;
  for (int i = 0; i < n - 1; i++) {
    std::cin >> tmp;
    parents.emplace_back(tmp);
  }
  std::vector<int> quanzhi;
  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    quanzhi.emplace_back(tmp);
  }

  std::cout << solution(n, parents, quanzhi) << std::endl;

  return 0;
}
