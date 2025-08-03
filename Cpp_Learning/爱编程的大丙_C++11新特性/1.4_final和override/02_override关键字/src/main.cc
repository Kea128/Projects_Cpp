#include <iostream>
#include <memory>

class Base {
 public:
  virtual void test() { std::cout << "Base" << std::endl; }
};

class Child : public Base {
 public:
  void test() override { std::cout << "Child" << std::endl; }
};

class GrandChild : public Child {
 public:
  void test() override { std::cout << "GrandChild" << std::endl; }
};

int main(int argc, char* argv[]) {
  Base* ptrBase = new Child();
  ptrBase->test();  // Child
  delete ptrBase;

  Child* ptrChild = new GrandChild();
  ptrChild->test();  // GrandChild
  delete ptrChild;

  Base* ptrBase2 = new GrandChild();
  ptrBase2->test();  // GrandChild
  delete ptrBase2;

  return 0;
}
