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

  // 拷贝构造函数
  Test(const Test& a) : m_num(new int(*a.m_num)), m_name(a.m_name) {
    std::cout << "copy construct" << std::endl;
  }

  // 移动构造函数：有右值引用参数的构造函数
  // 作用：复用其他对象中的资源(堆内存)
  // 这个类中的堆内存资源就是m_num
  // *通过移动构造做的是浅拷贝：m_num(a.m_num)，故意不让其进行深拷贝
  // 函数体中将临时对象a的m_num指向空，转移了堆内存资源
  // *a一定是个临时对象，才会调用移动构造
  Test(Test&& a) : m_num(a.m_num), m_name(a.m_name) {
    a.m_num = nullptr;
    std::cout << "move construct" << std::endl;
  }

  // // 拷贝赋值函数
  // Test& operator=(const Test& a) {
  //   std::cout << "copy assign" << std::endl;
  //   this->m_name = a.m_name;
  //   this->m_num = new int(*a.m_num);
  //   return *this;
  // }

  ~Test() {
    std::cout << "destruct Test class ..." << std::endl;
    delete m_num;
    m_num = nullptr;
  }
  int* m_num;
  std::string m_name;
};

// 返回临时对象，但可以取地址
Test getObj() {
  Test t;
  return t;
}

// 返回临时对象，且不能取地址(即将被释放且不能取地址的对象/将亡值)
Test getObj1() { return Test(); }

Test&& getObj2() { return Test(); }

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

  // 赋值时必须是临时对象，移动构造才会被调用
  // getObj()返回的是临时对象，优先调用移动构造函数
  // 如果返回的是不是临时对象，那么就调用拷贝构造函数
  Test t1;
  std::cout << "======" << std::endl;
  Test t2(t1);
  std::cout << "======" << std::endl;
  // 移动构造，只转移堆内存资源
  Test&& t3 = getObj();
  std::cout << "======" << std::endl;

  // 如果没有移动构造函数，使用右值引用初始化要求更高一些
  // 要求右侧是一个临时的且不能取地址的对象
  // 右值引用：延长将亡值的生命周期
  Test&& t4 = getObj1();
  std::cout << t4.m_num << std::endl;

  int&& a1 = 5;    // a1为右值引用
  auto&& bb = a1;  //右值引用推导未定义引用类型，得到左值引用
  auto&& bb1 = 5;  //右值推导未定义引用类型，得到右值引用

  int a2 = 5;
  int& a3 = a2;
  auto&& cc = a3;
  auto&& cc1 = a2;  // 左值推导未定义引用类型，得到左值引用

  const int& s1 = 100;
  const int&& s2 = 100;
  auto&& dd = s1;  // 常量左值引用推导未定义引用类型，得到常量左值引用
  auto&& ee = s2;  // 常量右值引用推导未定义引用类型，得到常量左值引用

  const auto&& x =
      5;  // 右值推导未定义引用类型，得到常量右值引用(因为前面有const)

  return 0;
}
