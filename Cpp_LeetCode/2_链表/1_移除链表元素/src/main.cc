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

int search(std::vector<int>& nums, int target) {}

int main() {
  std::vector<int> numbers;
  int num;
  while (true) {
    std::cin >> num;
    numbers.push_back(num);
    if (getchar() == '\n') break;
  }

  ListNode* head = new ListNode(numbers[0]);
  ListNode* cur = head;
  for (auto it = numbers.begin() + 1; it != numbers.end(); it++) {
    cur->next_ = new ListNode(*it);
    cur = cur->next_;
  }

  std::cout << std::endl;

  return 0;
}