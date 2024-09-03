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
  ListNode* dummyHead = new ListNode(0);  // 虚拟头结点
  dummyHead->next_ = head;    // 虚拟头结点指向链表首个节点
  ListNode* cur = dummyHead;  // cur指向虚拟头结点
  // 若cur的下一个节点不为空，则循环
  while (cur->next_ != nullptr) {
    // 若cur的下一个节点的值等于val，则删除cur的下一个节点，cur指向下下个节点
    if (cur->next_->val_ == val) {
      ListNode* tmp = cur->next_->next_;
      delete cur->next_;
      cur->next_ = tmp;
    }
    // 否则，cur指向下一个节点
    else {
      cur = cur->next_;
    }
  }
  head = dummyHead->next_;
  delete dummyHead;
  return head;
}

int main() {
  std::vector<int> numbers;
  int num, delete_num;
  while (true) {
    std::cin >> num;
    numbers.push_back(num);
    if (getchar() == '\n') break;
  }
  std::cin >> delete_num;

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

  head = removeElements(head, delete_num);
  cur = head;
  while (cur != nullptr) {
    std::cout << cur->val_ << " ";
    cur = cur->next_;
  }
  std::cout << std::endl;

  return 0;
}