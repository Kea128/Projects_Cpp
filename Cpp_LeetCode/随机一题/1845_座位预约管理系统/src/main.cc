#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

/**
 * @brief 1845_座位预约管理系统
 * https://leetcode.cn/problems/seat-reservation-manager/
 */

class SeatManager {
  priority_queue<int, vector<int>, greater<>> available;

 public:
  SeatManager(int n) {
    for (int i = 1; i <= n; i++) {
      available.push(i);
    }
  }

  int reserve() {
    int seatNumber = available.top();
    available.pop();
    return seatNumber;
  }

  void unreserve(int seatNumber) { available.push(seatNumber); }
};

int main(int argc, char const* argv[]) {}
