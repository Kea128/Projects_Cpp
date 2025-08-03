// #include <cassert> //这是断言的头文件，静态断言不需要
#include <iostream>

#if 0  // 断言
char* createArray(int size) {
  assert(size > 0); //
  char* array = new char[size];
  return array;
}
#endif

int main(int argc, char const* argv[]) {
  // char* buf = createArray(1);

  static_assert(sizeof(long) == 8, "当前系统不是64位");
  std::cout << "---" << std::endl;
  return 0;
}
