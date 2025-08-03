#include <functional>
#include <iostream>
#include <string>

void testFunc(int x, int y, const std::function<void(int, int)> &func) {
  if (x % 2 == 0) {
    func(x, y);
  }
}

void output_add(int x, int y) {
  std::cout << "x: " << x << ", y: " << y << ", x+y: " << x + y << std::endl;
}

class Test {
 public:
  void output(int x, int y) {
    std::cout << "x: " << x << ", y: " << y << std::endl;
  }
  int m_number_ = 100;
};

int main(int argc, char *argv[]) {
  // 1.普通函数绑定
  for (int i = 0; i < 10; i++) {
    // 使用bind(绑定器函数)绑定了某个可调用对象，得到一个仿函数
    // 这个仿函数对应的是可调用对象，绑定时可以指定参数
    // std::bind绑定函数，指定了固定实参 i + 100 和 i + 200
    // 这里将仿函数保存了起来
    // 如果直接调用仿函数：std::bind(&output_add, i+100, i+200)(实参列表);
    auto f1 = std::bind(&output_add, i + 100, i + 200);
    // 这里实参(i，i)不生效，因为上面已经绑定了固定实参
    testFunc(i, i, f1);

    // std::bind绑定函数，使用两个占位符
    auto f2 =
        std::bind(&output_add, std::placeholders::_1, std::placeholders::_2);
    // 这里实参(i，i)会生效，因为上面采用占位符，没有绑定固定实参
    testFunc(i, i, f2);
  }

  // 2.类的成员函数绑定
  // 通过绑定把二元函数变成了一元函数
  // f3为仿函数
  // 以下做了自动类型推导
  Test t;
  auto f3 = std::bind(&Test::output, &t, 520, std::placeholders::_1);
  f3(1314);

  // 3.类的成员变量绑定
  // 类的成员变量绑定 省略了&t后面的函数参数(因为成员变量本身没有参数)
  // 同样的得到f4为仿函数
  // 以下做了自动类型推导
  auto f4 = std::bind(&Test::m_number_, &t);
  std::cout << f4() << std::endl;
  f4() = 567;
  std::cout << f4() << std::endl;

  // 将仿函数用包装器进行包装(对可调用对象进行包装)，得到f33和f44均为包装器类型，和上面的f3,f4不是一个类型
  // 这样就可以用可调用对象包装器对类的 成员函数 和 成员变量 进行包装
  // 就是用绑定器函数转换为可调用对象(仿函数)，间接进行包装
  // 以下做了隐式类型转换
  std::function<void(int, int)> f33 =
      std::bind(&Test::output, &t, 520, std::placeholders::_1);
  // m_number_为int型，无参数列表，且要可读可写，所以要加&（引用）
  std::function<int &(void)> f44 = std::bind(&Test::m_number_, &t);

  return 0;
}
