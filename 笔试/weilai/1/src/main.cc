#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int solution(string& S, string& T) {
  string sortS = S;
  string sortT = T;
  sort(sortS.begin(), sortS.end());
  sort(sortT.begin(), sortT.end());

  if (sortS != sortT) return -1;

  int n = S.length();
  int j = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (S[i] == T[j]) {
      j--;
    }
  }
  return n - (j + 1);
}

int main(int argc, char const* argv[]) {
  string S, T;
  std::cin >> S;
  std::cin >> T;
  std::cout << solution(S, T) << std::endl;
  return 0;
}
