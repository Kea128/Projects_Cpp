#include <iostream>
#include <string>
#include <vector>

struct PDD {
  int m;
  std::string str;
};

int solution(PDD pdd) {
  std::string str = pdd.str;
  int m = pdd.m;
  int count = 0;
  if (str.size() == 1) {
    if (str[0] == 'P') {
      if (m < 2)
        return 0;
      else
        return 1 + (m - 2) / 3;
    } else {
      if (m < 2)
        return 0;
      else
        return 1 + (m - 2) / 3;
    }
  }
  for (int i = 0, j = 1; j < str.size();) {
    if (str[i] == 'P' && str[j] == 'D') {
      count++;
      i += 2;
      j += 2;
    } else if (str[i] == 'D' && str[j] == 'D') {
      count++;
      i += 2;
      j += 2;
    } else {
      i++;
      j++;
    }
  }
  return std::min(m, count);
}

int main(int argc, char const *argv[]) {
  int t;
  std::cin >> t;
  std::vector<PDD> vec(t, PDD());
  for (int i = 0; i < t; i++) {
    std::cin >> vec[i].m;
    std::cin >> vec[i].str;
  }
  for (int i = 0; i < vec.size(); i++) {
    std::cout << solution(vec[i]) << std::endl;
  }

  return 0;
}
