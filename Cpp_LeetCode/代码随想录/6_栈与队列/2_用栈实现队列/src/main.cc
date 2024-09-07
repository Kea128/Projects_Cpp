#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

/**
 * @brief 232 用栈实现队列
 * https://leetcode.cn/problems/implement-queue-using-stacks/description/
 */

class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { stIn.push(x); }

  int pop() {
    if (stOut.empty()) {
      while (!stIn.empty()) {
        stOut.push(stIn.top());
        stIn.pop();
      }
    }
    int res = stOut.top();
    stOut.pop();
    return res;
  }

  int peek() {
    int res = pop();
    stOut.push(res);
    return res;
  }

  bool empty() { return stIn.empty() && stOut.empty(); }

 private:
  std::stack<int> stIn;
  std::stack<int> stOut;
};

int main(int argc, char* argv[]) {}
