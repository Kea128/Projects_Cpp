#include <functional>
#include <iostream>

/**
 * @brief lambda表达式
 * [capture](params) opt -> ret {body;};
 */

void func(int x, int y) {
  int a = 7;
  int b = 9;

  // 匿名函数，x通过引用传递，其他参数通过值传递拷贝的方式
  // 值拷贝方式使用外部变量，则在匿名函数内部拷贝的数据是只读的
  // 在{opt}选项位置添加mutable关键字，则可以在匿名函数内部修改拷贝进来的只读参数
  // 以下匿名函数只是定义了，但没有调用,在{}后面加上参数列表()才表示调用了
  /*
  [=, &x]() mutable {
    int c = a;
    int d = x;
    // b++; //不添加mutable关键字，b只读，无法做写操作
    b++;
    std::cout << "b = " << b << std::endl;
  };
  */

  // 匿名函数没有参数，{}后面的参数列表()不需要任何实参
  // 有参数(int z)，{}后面的()需要实参
  [=, &x](int z) mutable {
    int c = a;
    int d = x;
    // b++; //不添加mutable关键字，b只读，无法做写操作
    b++;
    std::cout << "b = " << b << std::endl;
  }(88);
  std::cout << "b = " << b << std::endl;
}

void func2(int x, int y) {
  int a;
  int b;
  using ptr = void (*)(int);  // 定义一个函数指针类型

  // 1.定义一个ptr类型的指针变量并指向一个匿名函数
  // []中没有捕获任何外部变量，则lambda表达式可以看做函数指针
  ptr p1 = [](int x) { std::cout << "x = " << x << std::endl; };
  p1(11);

  // 2.以下错误，[]加了=后,即[]捕获了外部变量，匿名函数不能转换成函数指针,只能作为仿函数
  // 将仿函数保存起来有两种方式，使用std::function包装器直接包装或者std::bind进行绑定
  // ptr p2 = [=](int x) { std::cout << "x = " << x << std::endl; };
  // p2(11);

  // 2.1.用包装器把lambda表达式包装
  // 包装前后参数数量一致
  std::function<void(int)> fff = [=](int x) {
    std::cout << "x = " << x << std::endl;
  };
  fff(11);

  // 2.2.用std::bind绑定lambda表达式
  // 包装前有n个参数，包装后参数可以小于n,因为std::bind可以降元
  // 第一个参数是函数地址，这里是lambda表达式，没有函数名，就用函数体作为地址
  // 第二个参数指定绑定的这个匿名函数的参数列表
  // std::bind绑定之后得到的还是仿函数，用auto推导的是仿函数，用std::function接收的是一个包装器对象,两者类型不一致
  // 包装器类型可以包装auto推导出来的类型
  std::function<void(int)> fff2 =
      std::bind([=](int x) { std::cout << "x = " << x << std::endl; },
                std::placeholders::_1);
  fff2(11);
}

int main(int argc, char *argv[]) {
  /* code */
  func(1, 2);
  std::cout << "==========" << std::endl;
  func2(1, 2);
  return 0;
}
