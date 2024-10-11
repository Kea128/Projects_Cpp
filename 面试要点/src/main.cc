#include <iostream>
#include <list>

int main() {
  // 初始化一个空的list容器
  std::list<int> myList;

  // 插入元素到list的末尾
  myList.push_back(10);
  myList.push_back(20);
  myList.push_back(30);

  // 插入元素到list的开头
  myList.push_front(5);

  std::cout << "List elements: ";
  for (const auto& elem : myList) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  // 使用迭代器插入元素到指定位置
  auto it = myList.begin();
  std::cout << *it << std::endl;
  ++it;  // 移动到第二个位置
  std::cout << *it << std::endl;
  myList.insert(it, 15);  // 在第二个位置插入15

  std::cout << "List elements: ";
  for (const auto& elem : myList) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  std::cout << *it << std::endl;
  it--;
  std::cout << *it << std::endl;
  myList.insert(it, 100);  // 在第二个位置插入100

  // 遍历输出list中的元素
  std::cout << "List elements: ";
  for (const auto& elem : myList) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  // // 删除list中的第一个元素
  // myList.pop_front();

  // // 删除list中的最后一个元素
  // myList.pop_back();

  // // 使用迭代器删除指定位置的元素
  // it = myList.begin();
  // ++it;              // 移动到第二个位置
  // myList.erase(it);  // 删除第二个位置的元素

  // // 再次遍历输出list中的元素
  // std::cout << "List elements after deletion: ";
  // for (const auto& elem : myList) {
  //   std::cout << elem << " ";
  // }
  // std::cout << std::endl;

  return 0;
}