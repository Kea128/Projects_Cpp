#include <iostream>
#include <string>

/**
 * @brief 右值引用：延长将亡值的生命周期
 *
 */

class Test {
 public:
  Test() : m_num(new int(100)), m_name("test") {
    std::cout << "construct Test class ..." << std::endl;
    printf("m_num地址:%p\n", m_num);
  }
  Test(const Test& a) : m_num(new int(*a.m_num)), m_name(a.m_name) {
    std::cout << "copy construct" << std::endl;
  }
  Test& operator=(const Test& a) {
    std::cout << "copy assign" << std::endl;
    this->m_name = a.m_name;
    this->m_num = new int(*a.m_num);
    return *this;
  }

  ~Test() {
    std::cout << "destruct Test class ..." << std::endl;
    delete m_num;
    m_num = nullptr;
  }
  int* m_num;
  std::string m_name;
};

Test getObj() {
  Test t;
  return t;
}

int main(int argc, char* argv[]) {
#ifdef a
  // 左值
  int num = 9;

  // 左值引用
  int& a = num;

  // 右值

  // 右值引用
  int&& b = 8;

  // 常量右值引用
  const int&& d = 6;
  // const int&& e = b; //error 右值引用只能通过右值初始化
  // int&& f = b; //error

  // 常量左值引用 const或者constexpr
  const int& c = num;
  const int& g = b;  //右值引用对常量左值引用初始化
  const int& h = d;  //常量右值引用对常量左值引用初始化
  const int& i = a;  //左值引用对常量左值引用初始化
#endif

  Test t = getObj();
  // Test t2;
  return 0;
}
