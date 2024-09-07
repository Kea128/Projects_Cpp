#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

/**
 * @brief 225 用队列实现栈
 * https://leetcode.cn/problems/implement-stack-using-queues/description/
 */

class MyStack {
 public:
  MyStack() {}

  void push(int x) { que.push(x); }

  int pop() {
    int n = que.size() - 1;
    while (n--) {
      int tmp = que.front();
      que.push(tmp);
      que.pop();
    }
    int res = que.front();
    que.pop();
    return res;
  }

  int top() {
    int res = pop();
    que.push(res);
    return res;
  }

  bool empty() { return que.empty(); }

 private:
  std::queue<int> que;
};

int main(int argc, char* argv[]) {
  MyStack sta = MyStack();
  sta.push(1);
  sta.push(2);
  std::cout << sta.top() << std::endl;
  std::cout << sta.pop() << std::endl;
  std::cout << sta.empty() << std::endl;
}
