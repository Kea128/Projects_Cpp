#include <cmath>
#include <iostream>

int main() {
  int a, b;

  bool flag = false;
  std::cin >> a >> b;
  int start = b / a + 1;
  int result = start;
  int add = start - 1;
  std::cout << "start " << start << std::endl;
  std::cout << "add " << add << std::endl;
  while (!flag) {
    result = result + add;
    if ((a * result - 1) % b == 0) {
      flag = true;
    }
  }
  std::cout << result << std::endl;
}
