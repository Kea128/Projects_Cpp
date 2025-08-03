#include <iostream>

double divisionMethod(int a, int b) noexcept {
  if (b == 0) {
    std::cout << "division by zero!!!" << std::endl;
    return -1;
  }
  return a / b;
}

int main() {
  try {
    throw -1;
  } catch (int e) {
    std::cout << "int exception, value: " << e << std::endl;
  }
  std::cout << "That's ok!" << std::endl;
  return 0;
}