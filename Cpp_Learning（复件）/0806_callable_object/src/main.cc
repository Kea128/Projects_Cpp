#include <functional>
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
  cout << a << " " << b << endl;
  return a;
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
  // 2.具有operator()成员函数的类对象（仿函数），该类对象可以作为函数调用
  // 类中重载()操作符，则类对象就可以作为函数调用
  void operator()(string msg) { cout << msg << endl; }

  // 3.将类对象转换为函数指针
  // 类中的一个函数，将类对象转换为函数指针
  // 这个函数无返回值
  // operator后面加函数类型，funcPtr2是要转换的类型，return print2的函数地址
  // print2是类中的静态成员函数，funcPtr2应该和print2的参数类型、返回值类型一致，并且print2要static修饰
  // 因为static修饰的函数属于类，非静态成员函数属于对象，不能return非静态成员函数
  // 只要把当前的对象转换为函数指针类型，就调用返回地址对应的函数
  operator funcPtr2() { return print2; }

  static int print2(int a, double b) {
    cout << "调用类中的print2静态成员函数, 该函数在operator "
            "funcPtr2()中返回了其地址"
         << endl;
    cout << a << " " << b << endl;
    return a;
  }
  int print3(int a, double b) {
    cout << "调用类中的print3非静态成员函数" << endl;
    cout << a << " " << b << endl;
    return a;
  }

 public:
  int m_id_ = 520;
  double m_price_ = 2.3;
};

class A {
 public:
  // 构造函数参数是一个包装器对象
  // 可以给构造函数传递四种类型的可调用对象：
  // (1.普通函数的地址 2.类的静态成员函数的地址
  // 3.仿函数 4.可以转换为函数指针的类对象)
  A(const function<int(int, double)>& f) : callback(f) {}

  void notify(int a, double b) {
    int result = callback(a, b);  // 调用通过构造函数得到的函数指针
    cout << "类A::notify方法调用函数指针(构造函数传入的可调用对象): " << result
         << endl;
    cout << callback(a, b) << endl;
  }

 private:
  // 类中私有成员，是 可调用对象包装器类型
  function<int(int, double)> callback;
};

class B {
 public:
  int operator()(int a, double b) {
    cout << "B类中的仿函数: " << a << " " << b << endl;
    return a;
  }
};

int main(int argc, char* argv[]) {
#ifdef TEST
  // 2.调用重载()的operator()成员函数(仿函数)
  cout << "=====2.调用重载()的operator()成员函数=====" << endl;
  Test t;
  t("调用类中的operator()成员函数");

  // 3.将tt对象转换为函数指针, 并调用
  cout << "=====3.将tt对象转换为函数指针, 并调用=====" << endl;
  Test tt;
  tt(19, 2.3);

  // 4.类成员函数指针
  cout << "=====4.类的成员函数指针=====" << endl;
  // "int (Test::*)(int a, double b)" 类型的值不能用于初始化
  // "funcPtr2" (aka "int (*)(int, double)") 类型的实体
  // 不能让定义的函数指针指向非静态成员函数
  // funcPtr2 f = Test::print3;
  // 函数名就是地址，是否加取地址&都可以
  funcPtr2 f = Test::print2;  // 这样是可以的，因为print2是静态成员函数,不在类中
  // 定义指向类成员的函数指针
  using funcPtr4 = int (Test::*)(int, double);
  funcPtr4 f1 = &Test::print3;
  // f和f1是指向类成员函数的可调用对象

  // 4.类的成员指针(变量)
  // 定义ptr1为一个Test类中int类型的指针
  using ptr1 = int Test::*;
  ptr1 pt = &Test::m_id_;
  // pt是指向类成员变量的可调用对象

  // 后面可以通过Test类实例来调用f1，pt；或者直接访问f
  // f1为类成员函数指针，*f1解引用后为指向的类成员函数
  // (20, 3.14)优先级更高，需要对ttt.*f1加小括号

  // 调用print2静态成员函数
  int result1 = (*f)(10, 2.3);
  // 调用print3成员函数和修改成员对象
  Test ttt;
  int result2 = (ttt.*f1)(20, 3.14);
  ttt.*pt = 100;
  cout << "m_id_ = " << ttt.m_id_ << endl;
#endif

  // 可调用对象包装器(指向某个可调用对象)
  // 先说类成员变量以外的三种类型，如下：
  /*
    1.包装普通函数
    2.包装类的静态函数
    3.包装仿函数（一个具有operator()成员函数的类对象）
  */
  // 1.包装普通函数 int print(int a, double b)
  std::function<int(int, double)> func1 = print;
  // 2.包装类的静态函数
  std::function<int(int, double)> func2 = Test::print2;
  // 3.包装仿函数（一个具有operator()成员函数的类对象）
  Test ta;
  std::function<void(string)> func3 = ta;
  // 4.包装能够转换为函数指针的对象
  Test tb;
  std::function<int(int, double)> func4 = tb;
  // 以上func1.2.3.4就是表示对应的函数

  // 调用
  int r1 = func1(10, 2.3);
  cout << "=====" << endl;
  func2(20, 3.14);
  cout << "=====" << endl;
  func3("Hello");
  cout << "=====" << endl;
  func4(30, 4.14);

  cout << "==========" << endl;
  // 构造函数参数是一个包装器对象，可以给构造函数传递四种类型的可调用对象：
  // 1.普通函数的地址
  A aa(print);
  aa.notify(1, 3.1);
  cout << "==========" << endl;

  // 2.类的静态成员函数的地址
  A ab(Test::print2);
  ab.notify(2, 4.1);
  cout << "==========" << endl;

  // 3.仿函数
  // 原本的ta仿函数类型不对
  B b;
  A ac(b);
  ac.notify(3, 5.1);
  cout << "==========" << endl;

  // 4.可以转换为函数指针的类对象
  A ad(tb);
  ad.notify(4, 6.1);

  return 0;
}

cout << "=====" << endl;
func4(30, 4.14);

cout << "==========" << endl;
cout << "=====" << endl;
func4(30, 4.14);

cout << "==========" << endl;
cout << "=====" << endl;
func4(30, 4.14);

cout << "==========" << endl;
cout << "=====" << endl;
func4(30, 4.14);

cout << "=====" << endl;
func4(30, 4.14);

cout << "==========" << endl;
cout << "=====" << endl;
func4(30, 4.14);

cout << "==========" << endl;
cout << "==========" << endl;