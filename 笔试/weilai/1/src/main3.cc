// #include <iostream>
// using namespace std;

// struct NodeList {
//   int val_;
//   NodeList* next_;
//   NodeList(int val) : val_(val), next_(nullptr) {}
// };

// class NodeListOp {
//  public:
//   NodeListOp() : head_(nullptr){};
//   // 释放链表
//   ~NodeListOp() {
//     NodeList* cur = head_;
//     while (cur) {
//       NodeList* tmp = cur;
//       cur = cur->next_;
//       delete tmp;
//     }
//     head_ = nullptr;
//   };

//   void insertNode(int x, int y) {
//     // 设置dummyHead
//     if (head_ == nullptr) {
//       head_ = new NodeList(y);
//       return;
//     }
//     NodeList* dummyHead = new NodeList(0);
//     dummyHead->next_ = head_;

//     NodeList* cur = dummyHead;
//     while (cur->next_ != nullptr) {
//       if (cur->next_->val_ == x) {
//         NodeList* newNode = new NodeList(y);
//         NodeList* tmp = cur->next_;
//         cur->next_ = newNode;
//         newNode->next_ = tmp;
//         break;
//       }
//       cur = cur->next_;
//     }
//     if (cur->next_ == nullptr) {
//       NodeList* newNode = new NodeList(y);
//       cur->next_ = newNode;
//     }
//     head_ = dummyHead->next_;
//   }

//   void deleteNode(int x) {
//     NodeList* dummyHead = new NodeList(0);
//     dummyHead->next_ = head_;

//     NodeList* cur = dummyHead;
//     while (cur->next_ != nullptr) {
//       if (cur->next_->val_ == x) {
//         NodeList* tmp = cur->next_;
//         cur->next_ = cur->next_->next_;
//         delete tmp;
//         break;
//       }
//       cur = cur->next_;
//     }
//     head_ = dummyHead->next_;
//   }

//   void printList() {
//     NodeList* cur = head_;
//     while (cur) {
//       std::cout << cur->val_ << " ";
//       cur = cur->next_;
//     }
//     std::cout << std::endl;
//   }

//  private:
//   NodeList* head_ = nullptr;
// };

// int main(int argc, char const* argv[]) {
//   /* code */
//   int n;
//   std::cin >> n;

//   NodeListOp list;

//   for (int i = 0; i < n; i++) {
//     string operation;
//     std::cin >> operation;
//     if (operation == "insert") {
//       int x, y;
//       std::cin >> x >> y;
//       list.insertNode(x, y);
//     } else if (operation == "delete") {
//       int x;
//       std::cin >> x;
//       list.deleteNode(x);
//     }
//   }
//   list.printList();

//   return 0;
// }
