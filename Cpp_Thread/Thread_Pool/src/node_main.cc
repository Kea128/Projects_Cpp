#include <functional>
#include <iostream>
#include <thread>

#include "thread_pool.h"

void calc(int x, int y) {
  int z = x + y;
  std::cout << z << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main(int argc, char *argv[]) {
  // main函数为主线程
  // 创建线程池
  my_thread_pool::ThreadPool pool;
  for (int i = 0; i < 10; i++) {
    // task 应该是std::bind之后的仿函数
    auto task = std::bind(&calc, i, i * 2);
    pool.addTask(task);
  }
  // 这里用键盘输入阻塞主线程
  std::getchar();
  return 0;
}
