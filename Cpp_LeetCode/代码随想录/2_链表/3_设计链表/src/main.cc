#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief 移除链表元素
 */

/*
  你可以选择使用单链表或者双链表，设计并实现自己的链表。

  单链表中的节点应该具备两个属性：val 和 next_ 。val 是当前节点的值，next_
  是指向下一个节点的指针/引用。

  如果是双向链表，则还需要属性 prev
  以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

  实现 MyLinkedList 类：

  MyLinkedList() 初始化 MyLinkedList 对象。
  int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1
  。 void addAtHead(int val) 将一个值为 val
  的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
  void addAtTail(int val) 将一个值为 val
  的节点追加到链表中作为链表的最后一个元素。 void addAtIndex(int index, int val)
  将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index
  等于链表的长度，那么该节点会被追加到链表的末尾。如果 index
  比长度更大，该节点将 不会插入 到链表中。 void deleteAtIndex(int index)
  如果下标有效，则删除链表中下标为 index 的节点。
*/

/*
  示例：

  输入
  ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get",
  "deleteAtIndex", "get"]
  [[], [1], [3], [1, 2], [1], [1], [1]]
  输出
  [null, null, null, null, 2, null, 3]

  解释
  MyLinkedList myLinkedList = new MyLinkedList();
  myLinkedList.addAtHead(1);
  myLinkedList.addAtTail(3);
  myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
  myLinkedList.get(1);              // 返回 2
  myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
  myLinkedList.get(1);              // 返回 3
*/

struct Nodelist {
  int val_;
  Nodelist* next_;
  Nodelist(int val, Nodelist* next_ = nullptr) : val_(val), next_(next_) {}
};

class MyLinkedList {
 public:
  MyLinkedList() {
    dummyHead_ = new Nodelist(0);
    size_ = 0;
  }

  ~MyLinkedList() {
    // 链表的析构，释放内存
    Nodelist* cur = dummyHead_;
    while (cur->next_ != nullptr) {
      Nodelist* tmp = cur->next_->next_;
      delete cur->next_;
      cur->next_ = tmp;
      size_--;
    }
    delete dummyHead_;
    dummyHead_ = nullptr;
  }

  // 获取第n个节点值，链表下标从0开始（不包括dummyHead）
  int get(int index) {
    if (index > (size_ - 1) || index < 0) return -1;
    // 这里将cur设置为首个节点而非dummyHead
    Nodelist* cur = dummyHead_->next_;
    // 移动index次cur
    while (index--) {
      cur = cur->next_;
    }
    return cur->val_;
  }

  void addAtHead(int val) {
    Nodelist* newNode = new Nodelist(val);
    newNode->next_ = dummyHead_->next_;
    dummyHead_->next_ = newNode;
    size_++;
  }

  void addAtTail(int val) {
    Nodelist* cur = dummyHead_;
    while (cur->next_ != nullptr) {
      cur = cur->next_;
    }
    cur->next_ = new Nodelist(val);
    size_++;
  }

  void addAtIndex(int index, int val) {
    if (index > size_) return;
    if (index < 0) index = 0;
    Nodelist* cur = dummyHead_;
    while (index--) {
      cur = cur->next_;
    }
    if (cur->next_ != nullptr) {
      Nodelist* tmp = cur->next_;
      cur->next_ = new Nodelist(val);
      cur->next_->next_ = tmp;
    } else {
      cur->next_ = new Nodelist(val);
    }
    size_++;
  }

  void deleteAtIndex(int index) {
    if (index >= 0 && index <= size_ - 1) {
      Nodelist* cur = dummyHead_;
      while (index--) {
        cur = cur->next_;
      }
      Nodelist* tmp = cur->next_->next_;
      delete cur->next_;
      cur->next_ = tmp;
      size_--;
    }
  }

  Nodelist* getHead() { return dummyHead_->next_; }

 public:
  Nodelist* dummyHead_;
  int size_;
};

void showNodeList(Nodelist* head) {
  Nodelist* cur = head;
  while (cur != nullptr) {
    std::cout << cur->val_ << " ->";
    cur = cur->next_;
  }
  std::cout << std::endl;
}

int main() {
  MyLinkedList myLinkedList;
  std::cout << "头插1: " << std::endl;
  myLinkedList.addAtHead(1);
  showNodeList(myLinkedList.getHead());  // 1
  std::cout << "节点数：" << myLinkedList.size_ << std::endl;
  std::cout << "=======================" << std::endl;

  std::cout << "尾插3: " << std::endl;
  myLinkedList.addAtTail(3);
  showNodeList(myLinkedList.getHead());  // 1 3
  std::cout << "节点数：" << myLinkedList.size_ << std::endl;
  std::cout << "=======================" << std::endl;

  std::cout << "index 1 前面插 2: " << std::endl;
  myLinkedList.addAtIndex(1, 2);  // 链表变为 1->2->3
  showNodeList(myLinkedList.getHead());
  std::cout << "节点数：" << myLinkedList.size_ << std::endl;
  std::cout << "=======================" << std::endl;

  std::cout << "返回：get(1) = " << myLinkedList.get(1) << std::endl;  // 返回 2
  showNodeList(myLinkedList.getHead());
  std::cout << "节点数：" << myLinkedList.size_ << std::endl;
  std::cout << "=======================" << std::endl;

  std::cout << "删除index 1: " << std::endl;
  myLinkedList.deleteAtIndex(1);  // 现在，链表变为 1->3
  showNodeList(myLinkedList.getHead());
  std::cout << "节点数：" << myLinkedList.size_ << std::endl;
  std::cout << "=======================" << std::endl;

  std::cout << "返回：get(1) = " << myLinkedList.get(1) << std::endl;  // 返回 3
  showNodeList(myLinkedList.getHead());
  std::cout << "节点数：" << myLinkedList.size_ << std::endl;
  std::cout << "=======================" << std::endl;

  std::cout << "返回：get(3) = " << myLinkedList.get(3) << std::endl;
  showNodeList(myLinkedList.getHead());
  std::cout << "节点数：" << myLinkedList.size_ << std::endl;
  std::cout << "=======================" << std::endl;

  std::cout << "删除index 3: " << std::endl;
  myLinkedList.deleteAtIndex(3);
  showNodeList(myLinkedList.getHead());
  std::cout << "节点数：" << myLinkedList.size_ << std::endl;
  std::cout << "=======================" << std::endl;

  std::cout << "删除index 0: " << std::endl;
  myLinkedList.deleteAtIndex(0);
  showNodeList(myLinkedList.getHead());
  std::cout << "节点数：" << myLinkedList.size_ << std::endl;
  std::cout << "=======================" << std::endl;

  std::cout << "返回：get(0) = " << myLinkedList.get(0) << std::endl;
  showNodeList(myLinkedList.getHead());
  std::cout << "节点数：" << myLinkedList.size_ << std::endl;
  std::cout << "=======================" << std::endl;

  std::cout << "删除index 0: " << std::endl;
  std::cout << "有问题？" << std::endl;
  std::cout << "节点数：" << myLinkedList.size_ << std::endl;
  myLinkedList.deleteAtIndex(0);
  showNodeList(myLinkedList.getHead());
  std::cout << "节点数：" << myLinkedList.size_ << std::endl;
  std::cout << "=======================" << std::endl;

  std::cout << "返回：get(0) = " << myLinkedList.get(0) << std::endl;
  showNodeList(myLinkedList.getHead());
  std::cout << "节点数：" << myLinkedList.size_ << std::endl;
  std::cout << "=======================" << std::endl;
  return 0;
}