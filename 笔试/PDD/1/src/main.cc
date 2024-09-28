
#include <iostream>
#include <set>
#include <string>
#include <vector>

struct data {
  int n;
  std::vector<int> prices;
};

int solution(data d) {
  int sum = 0;
  int quansum = 0;
  int n = d.n;
  auto prices = d.prices;
  int quan = 0;

  for (int i = 0; i < n; i++) {
    sum += prices[i];
    quansum += prices[i];

    if (quansum >= 100) {
      quansum = 0;
      quan += 1;
    }
    if (quan > 0) {
      int indexMax = i + 1;
      for (int j = i + 1; j < n; j++) {
        if (prices[j] > prices[indexMax]) {
          indexMax = j;
        }
      }
      if (indexMax < n) prices[indexMax] = 0;
    }
  }
  return sum;
}

int main(int argc, char const* argv[]) {
  int t;
  std::cin >> t;
  int n;
  std::vector<data> datas(t, data());
  for (int i = 0; i < t; ++i) {
    std::cin >> n;
    datas[i].n = n;
    for (int j = 0; j < n; ++j) {
      int num;
      std::cin >> num;
      datas[i].prices.push_back(num);
    }
  }
  for (int i = 0; i < t; i++) {
    std::cout << solution(datas[i]) << std::endl;
  }
  return 0;
}
