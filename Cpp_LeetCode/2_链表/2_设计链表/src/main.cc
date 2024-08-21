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
  ListNode* cur = dummyHead;
  while (cur->next_ != nullptr) {
    if (cur->next_->val_ == val) {
      ListNode* tmp = cur->next_->next_;
      delete cur->next_;
      cur->next_ = tmp;
    } else {
      cur = cur->next_;
    }
  }
  head = dummyHead->next_;
  delete dummyHead;
  return head;
}

int main() {
  std::vector<int> numbers;
  int num;
  while (true) {
    std::cin >> num;
    numbers.push_back(num);
    if (getchar() == '\n') break;
  }
  int delNum;
  std::cin >> delNum;

  // 根据输入构建链表
  ListNode* head = new ListNode(numbers[0]);
  ListNode* cur = head;
  for (auto it = numbers.begin() + 1; it != numbers.end(); it++) {
    cur->next_ = new ListNode(*it);
    cur = cur->next_;
  }
  // std::cout << std::endl;

  std::cout << "输出链表的值" << std::endl;
  cur = head;
  while (cur != nullptr) {
    std::cout << cur->val_ << " ";
    cur = cur->next_;
  }
  std::cout << std::endl;

  head = removeElements(head, 2);

  std::cout << "输出删除后链表的值" << std::endl;
  cur = head;
  while (cur != nullptr) {
    std::cout << cur->val_ << " ";
    cur = cur->next_;
  }
  std::cout << std::endl;

  return 0;
}