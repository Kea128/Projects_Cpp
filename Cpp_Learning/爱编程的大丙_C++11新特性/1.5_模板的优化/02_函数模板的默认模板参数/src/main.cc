// test.cpp
#include <iostream>
#include <vector>
using namespace std;

template <typename T = long, typename U = int>
void mytest(T t = 'A', U u = 'B') {
  std::cout << "t = " << t << ", u = " << u << std::endl;
}

int main(int argc, char const *argv[]) {
  // 根据传递的实参类型进行匹配，mytest<char, char>
  mytest('a', 'b');
  mytest<int>('a', 'b');
  mytest<char>('a', 'b');
  mytest<int, char>('a', 'b');
  mytest<char, int>('a', 'b');
  // 无法自动推导类型，使用默认模板类型
  mytest();
  return 0;
}
