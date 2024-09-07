#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * @brief 163 优秀数组
 * https://kamacoder.com/problempage.php?pid=1241
 */

int main() {
  int a, b;
  while (std::cin >> a >> b) {
    int result = a + b;
    std::cout << result << std::endl;
  }
  return 0;
}