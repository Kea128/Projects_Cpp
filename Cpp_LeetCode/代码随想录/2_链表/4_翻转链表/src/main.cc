#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief 206. 反转链表
 */

/*
  给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

  示例1：
  输入：head = [1,2,3,4,5]
  输出：[5,4,3,2,1]

  示例2：
  输入：head = [1,2]
  输出：[2,1]

  示例3：
  输入：head = []
  输出：[]
*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int num) : val(num), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
  ListNode* left = nullptr;
  ListNode* right = head;
  while (right != nullptr) {
    ListNode* tmp = right->next;
    right->next = left;
    left = right;
    right = tmp;
  }
  return left;
}

int main() {
  int n;
  std::vector<int> nums;
  while (true) {
    std::cin >> n;
    nums.emplace_back(n);
    char str = std::getchar();
    if (str == '\n') break;
  }

  std::cout << "输入的序列为: ";
  for (const auto& num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // 创建链表
  ListNode* head = new ListNode(nums[0]);
  ListNode* cur = head;
  for (int i = 1; i < nums.size(); i++) {
    cur->next = new ListNode(nums[i]);
    cur = cur->next;
  }

  std::cout << "创建的链表为: ";
  cur = head;
  while (cur != nullptr) {
    std::cout << cur->val << " ";
    cur = cur->next;
  }
  std::cout << std::endl;

  head = reverseList(head);

  std::cout << "翻转的链表为: ";
  cur = head;
  while (cur != nullptr) {
    std::cout << cur->val << " ";
    cur = cur->next;
  }
  std::cout << std::endl;
}
