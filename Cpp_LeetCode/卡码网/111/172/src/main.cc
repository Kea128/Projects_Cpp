#include <iostream>
#include <vector>

struct gupiao {
  int n, k;
  std::vector<int> price;
};

int solution(gupiao gp) {
  auto price = gp.price;
  int res = 0;
  int prePrice = 0;
  for (int i = 1; i < price.size(); i++) {
    prePrice += price[i - 1];
    while ((float)price[i] / prePrice > 0.12) {
      price[0]++;
      prePrice++;
      res++;
    }
  }
  return res;
}

int main(int argc, char const *argv[]) {
  int t;
  std::cin >> t;
  std::vector<gupiao> vec(t, gupiao());

  for (int i = 0; i < t; i++) {
    std::cin >> vec[i].n >> vec[i].k;
    for (int j = 0; j < vec[i].n; j++) {
      int tmp;
      std::cin >> tmp;
      vec[i].price.emplace_back(tmp);
    }
  }

  for (int i = 0; i < vec.size(); i++) {
    std::cout << solution(vec[i]) << std::endl;
  }

  return 0;
}
