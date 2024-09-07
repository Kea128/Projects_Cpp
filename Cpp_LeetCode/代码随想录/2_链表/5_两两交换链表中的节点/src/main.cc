#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief 24 两两交换链表中的节点
 * https://leetcode.cn/problems/swap-nodes-in-pairs/description/
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int n = 0) : val(n), next(nullptr) {}
};

ListNode* swapPairs(ListNode* head) {
  ListNode* dummyHead = new ListNode(0);
  dummyHead->next = head;
  ListNode* cur = dummyHead;
  // 遍历终止条件 链表节点个数为奇数或偶数
  while (cur->next != nullptr && cur->next->next != nullptr) {
    ListNode* tmp_1 = cur->next;
    ListNode* tmp_2 = cur->next->next->next;
    cur->next = cur->next->next;
    cur->next->next = tmp_1;
    tmp_1->next = tmp_2;
    cur = cur->next->next;
  }
  return dummyHead->next;
}

int main(int argc, char* argv[]) {
  int n;
  std::vector<int> nums;
  while (std::cin >> n) {
    nums.emplace_back(n);
  }

  ListNode* head = new ListNode(nums[0]);
  ListNode* cur = head;
  for (int i = 1; i < nums.size(); i++) {
    cur->next = new ListNode(nums[i]);
    cur = cur->next;
  }

  cur = head;
  while (cur != nullptr) {
    std::cout << cur->val << " ";
    cur = cur->next;
  }
  std::cout << std::endl;

  cur = swapPairs(head);
  while (cur != nullptr) {
    std::cout << cur->val << " ";
    cur = cur->next;
  }
  std::cout << std::endl;

  return 0;
}
