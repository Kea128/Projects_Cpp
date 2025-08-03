#include <iostream>
#include <memory>

class Base {
 public:
  virtual void test() { std::cout << "Base" << std::endl; }
  virtual ~Base() {}
};

// final 关键字用于防止类被继承或虚函数被重写
// 1. final可以修饰类，表示该类不能被继承
// 2. final可以修饰虚函数，表示该函数不能被重写
class Child final : public Base {
 public:
  // final作用：Child的子类不可以重写test函数
  void test() final { std::cout << "Child" << std::endl; }
  // 不能使用 "final" 修饰符声明非虚函数
  // void test2() final {}
};

// class GrandChild : public Child {
//  public:
//   void test() { std::cout << "GrandChild" << std::endl; }
// };

int main(int argc, char const *argv[]) {
  Child child;
  std::unique_ptr<Base> ptrBase = std::make_unique<Child>(child);
  ptrBase->test();
  return 0;
}
