#include <iostream>
#include <thread>

void func1() { std::cout << "子线程" << std::endl; }

int main(int argc, char *argv[]) {
  // main 所在线程为主线程

  // 创建子线程，执行func1
  std::thread t1(&func1);
  t1.join();  // t1加入到主线程，即t1阻塞主线程，等待t1结束

  std::cout << "主线程" << std::endl;

  return 0;
}
