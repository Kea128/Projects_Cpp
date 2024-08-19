#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief 移除链表元素
 */

struct ListNode {
  int val_;
  ListNode* next_;
  ListNode(int x) : val_(x), next_(nullptr) {}
};

ListNode* removeElements(ListNode* head, int val) {
  ListNode* dummyHead = new ListNode(0);
  dummyHead->next_ = head;
  ListNode* cur = head;
  while (cur != nullptr) {
    if (cur->val_ == val) {
    }
    cur = cur->next_;
  }
}

int main() {
  std::vector<int> numbers;
  int num;
  while (true) {
    std::cin >> num;
    numbers.push_back(num);
    if (getchar() == '\n') break;
  }

  // 根据输入构建链表
  ListNode* head = new ListNode(numbers[0]);
  ListNode* cur = head;
  for (auto it = numbers.begin() + 1; it != numbers.end(); it++) {
    cur->next_ = new ListNode(*it);
    cur = cur->next_;
  }
  // std::cout << std::endl;

  // 输出链表的值
  cur = head;
  while (cur != nullptr) {
    std::cout << cur->val_ << " ";
    cur = cur->next_;
  }
  std::cout << std::endl;

  head = removeElements(head, 2);

  return 0;
}