#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

/**
 * @brief 160_相交链表
 * https://leetcode.cn/problems/intersection-of-two-linked-lists/?envType=study-plan-v2&envId=top-100-liked
 */

struct ListNode {
  int val_;
  ListNode *next_;
  ListNode(int val = 0, ListNode *next = nullptr) : val_(val), next_(next) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  std::unordered_set<ListNode *> st;
  ListNode *curA = headA;
  while (curA != nullptr) {
    st.insert(curA);
    curA = curA->next_;
  }

  ListNode *curB = headB;
  while (curB != nullptr) {
    if (st.find(curB) != st.end()) {
      return curB;
    }
    curB = curB->next_;
  }
  return nullptr;
}

int main() { return 0; }