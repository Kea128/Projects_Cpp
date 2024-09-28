
#include <iostream>
#include <map>

long solution(int n) {
  std::map<int, int> mp;
  long res = 0;
  int count = 1;
  while (n > 0) {
    mp[n % 10]++;
    n /= 10;
  }
  for (auto it = mp.begin(); it != mp.end(); it++) {
    while (it->second != 0) {
      res += it->first * count;
      count *= 10;
      it->second--;
    }
  }
  return res;
}

int main1(int argc, char const *argv[]) {
  long n;
  std::cin >> n;
  std::cout << solution(n) << std::endl;
  return 0;
}
