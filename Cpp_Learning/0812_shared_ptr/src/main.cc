#include <cstring>
#include <iostream>
#include <memory>
#include <string>
using namespace std;

// 1. 通过构造函数初始化
void test_01() {
  // 使用智能指针管理一块 int 型的堆内存
  shared_ptr<int> ptr1(new int(520));
  cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;
  // 使用智能指针管理一块字符数组对应的堆内存
  shared_ptr<char> ptr2(new char[12]);
  cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;
  // 创建智能指针对象, 不管理任何内存
  shared_ptr<int> ptr3;
  cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;
  // 创建智能指针对象, 初始化为空
  shared_ptr<int> ptr4(nullptr);
  cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;

  // 不要使用一个原始指针初始化多个shared_ptr
  int* p = new int;
  shared_ptr<int> p1(p);
  // shared_ptr<int> p2(p);  // error, 编译不会报错, 运行会出错
}

// 2. 通过拷贝和移动构造函数初始化
void test_02() {
  // 使用智能指针管理一块 int 型的堆内存, 内部引用计数为 1
  shared_ptr<int> ptr1(new int(520));
  cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;
  //调用拷贝构造函数
  shared_ptr<int> ptr2(ptr1);
  cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;
  shared_ptr<int> ptr3 = ptr1;
  cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;
  //调用移动构造函数
  shared_ptr<int> ptr4(std::move(ptr1));
  cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;
  std::shared_ptr<int> ptr5 = std::move(ptr2);
  cout << "ptr5管理的内存引用计数: " << ptr5.use_count() << endl;
}

class Test {
 public:
  Test() { cout << "construct Test..." << endl; }
  Test(int x) { cout << "construct Test, x = " << x << endl; }
  Test(string str) { cout << "construct Test, str = " << str << endl; }
  ~Test() { cout << "destruct Test ..." << endl; }
};

// 3. 通过std::make_shared初始化
void test_03() {
  // 使用智能指针管理一块 int 型的堆内存, 内部引用计数为 1
  shared_ptr<int> ptr1 = make_shared<int>(520);
  cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;

  shared_ptr<Test> ptr2 = make_shared<Test>();
  cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;

  shared_ptr<Test> ptr3 = make_shared<Test>(520);
  cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;

  shared_ptr<Test> ptr4 = make_shared<Test>("我是要成为海贼王的男人!!!");
  cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;
}

// 4. 通过 reset方法初始化
void test_04() {
  // 对于一个未初始化的共享智能指针，可以通过reset方法来初始化，当智能指针中有值的时候，调用reset会使引用计数减1。
  // 使用智能指针管理一块 int 型的堆内存, 内部引用计数为 1
  shared_ptr<int> ptr1 = make_shared<int>(520);
  shared_ptr<int> ptr2 = ptr1;
  shared_ptr<int> ptr3 = ptr1;
  shared_ptr<int> ptr4 = ptr1;
  cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;
  cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;
  cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;
  cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;

  ptr4.reset();
  cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;
  cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;
  cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;
  cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;

  shared_ptr<int> ptr5;
  ptr5.reset(new int(250));
  cout << "ptr5管理的内存引用计数: " << ptr5.use_count() << endl;
}

// 5. 获取原始指针
void test_05() {
  int len = 128;
  shared_ptr<char> ptr(new char[len]);
  // 得到指针的原始地址
  char* add = ptr.get();
  // 使用 memset 函数将 add 指向的内存区域的前 len 个字节设置为0。
  // 这通常用于初始化内存，这里确保了字符数组中的每个字节都是初始值0。
  memset(add, 0, len);
  // 使用 strcpy 函数将字符串 "我是要成为海贼王的男人!!!" 复制到 add
  // 指向的内存位置。
  // 由于之前使用memset初始化了内存，这个复制操作会覆盖整个数组，包括初始化的0值。
  strcpy(add, "我是要成为海贼王的男人!!!");
  cout << "string: " << add << endl;

  shared_ptr<int> p(new int);
  *p = 100;
  // 首先通过 p.get() 获取 p 所管理的 int
  // 对象的地址，然后解引用这个地址来输出它的值（100）。接着，直接解引用 p
  // 来输出 int 对象的值（同样是100），最后输出两个值之间的空格和换行符。
  cout << *p.get() << "  " << *p << endl;
}

int main() {
  cout << "-----1. 通过构造函数初始化-----" << endl;
  test_01();
  cout << "-----2. 通过拷贝和移动构造函数初始化-----" << endl;
  test_02();
  cout << "-----3. 通过std::make_shared初始化-----" << endl;
  test_03();
  cout << "-----4. 通过 reset方法初始化-----" << endl;
  test_04();
  cout << "-----5. 获取原始指针-----" << endl;
  test_05();

  return 0;
}
