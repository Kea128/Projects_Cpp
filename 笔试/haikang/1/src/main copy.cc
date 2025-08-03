// #include <algorithm>
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <vector>

// struct NodeList {
//   int val_;
//   NodeList *next_;
//   NodeList(int val = 0, NodeList *next = nullptr) : val_(val), next_(next) {}
// };

// NodeList *listReverse(NodeList *head) {
//   NodeList *cur = head;
//   NodeList *pre = nullptr;
//   NodeList *next = nullptr;
//   while (cur) {
//     next = cur->next_;
//     cur->next_ = pre;
//     pre = cur;
//     cur = next;
//   }
//   return pre;
// }

// int main(int argc, char const *argv[]) {
//   std::string line;
//   std::getline(std::cin, line);
//   std::stringstream ss(line);

//   int val;
//   std::vector<int> nums;
//   while (ss >> val) {
//     nums.push_back(val);
//   }

//   NodeList *head = nullptr;
//   head = new NodeList(nums[0]);
//   NodeList *cur = head;
//   for (int i = 1; i < nums.size(); i++) {
//     cur->next_ = new NodeList(nums[i]);
//     cur = cur->next_;
//   }

//   // std::sort(nums.begin(), nums.end());
//   // for(auto& i : nums){
//   //   std::cout << i << " ";
//   // }
//   // std::cout << std::endl;

//   NodeList *res = listReverse(head);

//   while (res) {
//     std::cout << res->val_ << " ";
//     res = res->next_;
//   }
//   std::cout << std::endl;

//   return 0;
// }
