// #include <algorithm>
// #include <iostream>
// #include <map>
// #include <set>
// #include <sstream>
// #include <vector>
// using namespace std;

// struct Test {
//   int a;
//   int b;
//   int c;
//   int x;
//   int y;
//   Test(int a, int b, int c, int x, int y) : a(a), b(b), c(c), x(x), y(y) {}
// };

// int solution(Test& test) {
//   int res = 0;
//   int a = test.a;
//   int b = test.b;
//   int c = test.c;
//   int x = test.x;
//   int y = test.y;
//   int num1 = a / x;

//   for (int i = 0; i <= num1; i++) {
//     for (int j = 0; j <= (b + i) / y; j++) {
//       int aNew = a - i * x;
//       int bNew = b + i - j * y;
//       int cNew = c + j;
//       res = std::max(res, std::min({aNew, bNew, cNew}));
//     }
//   }
//   return res;
// }

// int main(int argc, char const* argv[]) {
//   int T;
//   std::cin >> T;
//   while (T--) {
//     int a, b, c, x, y;
//     std::cin >> a >> b >> c >> x >> y;
//     Test test(a, b, c, x, y);
//     std::cout << solution(test) << std::endl;
//   }
//   return 0;
// }
