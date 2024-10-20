#include <iostream>
#include <vector>
using namespace std;

int solution() {}

int main(int argc, char const *argv[]) {
  int p[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int i = 0;
  int j = 0;
  while (i++ < 6) {
    if (p[i] % 2) {
      j += p[i];
    }
    std::cout << j;
  }
  return 0;
}
