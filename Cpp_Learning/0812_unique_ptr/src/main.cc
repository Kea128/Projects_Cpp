#include <cstring>
#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main() {
  unique_ptr<int> ptr1(new int(10));
  // 原始的 unique_ptr（ptr1）不再拥有这个对象的所有权
  // 因此它不能再被解引用或使用，因为这样做是未定义行为。
  // ptr2 接管 ptr1 的所有权
  unique_ptr<int> ptr2 = move(ptr1);
  // cout << *ptr1 << endl;
  cout << *ptr2 << endl;

  // 将 ptr1 重置为一个空的 unique_ptr
  // 但是，由于 ptr1 已经通过移动操作空了，再次重置没有实际效果
  ptr1.reset();
  ptr2.reset(new int(250));
  cout << *ptr2 << endl;
  return 0;
}
