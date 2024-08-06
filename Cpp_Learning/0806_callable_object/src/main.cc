#include <iostream>
#include <string>

using namespace std;

/*
可调用对象定义
  1.是一个函数指针
  2.是一个具有operator()成员函数的类对象（仿函数）
  3.是一个可被转换为函数指针的类对象
  4.是一个类成员函数指针或者类成员指针
 */

// 1.是一个函数指针
//普通函数
int print(int a, double b) {
  cout << a << b << endl;
  return 0;
}
// 定义函数指针funcPtr1（一个变量），被初始化为print函数的地址
int (*funcPtr1)(int, double) = &print;
// 使用 using 声明定义函数指针类型
// 表示这个函数指针指向函数的类型是 int (*)(int, double)
using funcPtr2 = int (*)(int, double);
// 使用 typedef 定义函数指针类型
typedef int (*funcPtr3)(int, double);

class Test {
 public:
  // 2.是一个具有operator()成员函数的类对象（仿函数）
  // 类中重载()操作符
  void operator()(string msg) { cout << "msg: " << msg << endl; }

  // 3.是一个可被转换为函数指针的类对象
  // 将类对象转换为函数指针
  // 这个函数无返回值
  // operator后面加函数类型
  // funcPtr2是要转换的类型，应该和print2的参数类型、返回值类型一致，并且print2要static修饰
  // 因为static修饰的函数属于类，非静态成员函数属于对象
  operator funcPtr2() { return print2; }

  static int print2(int a, double b) {
    cout << "调用print函数" << endl;
    return 0;
  }
};

int main(int argc, char *argv[]) {
  std::cout << "hello" << std::endl;

  Test t;
  t("消息");
  return 0;
}
