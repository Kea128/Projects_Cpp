#include <algorithm>
#include <iostream>
#include <vector>

int solution(std::vector<int>& my, std::vector<int>& you) {
  std::sort(my.begin(), my.end());
  std::sort(you.begin(), you.end());
  int count = 0;
  int myPaiIndex = 0;
  for (int i = 0; i < you.size(); i++) {
    int youPai = you[i];
    while (my[myPaiIndex] <= youPai) {
      myPaiIndex++;
      if (myPaiIndex >= my.size()) {
        break;
      }
    }
    if (myPaiIndex >= my.size()) break;
    count++;
    myPaiIndex++;
  }
  return count;
}

int main(int argc, char const* argv[]) {
  int n;
  std::cin >> n;

  std::vector<int> you(n, 0);
  std::vector<int> my(n, 0);

  for (int i = 0; i < n; i++) {
    std::cin >> my[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> you[i];
  }

  std::cout << solution(my, you) << std::endl;
  return 0;
}
