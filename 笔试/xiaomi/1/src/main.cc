#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int N = 3;
const int SIZE = 9;
int board[N][N];
bool row[N][SIZE + 1], col[N][SIZE + 1];  // 标记每行每列的使用情况
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 上下左右四个方向

// 检查当前放置的数字是否合法
bool isValid(int r, int c, int num) {
  for (int i = 0; i < 4; i++) {
    int new_r = r + dir[i][0], new_c = c + dir[i][1];
    if (new_r >= 0 && new_r < N && new_c >= 0 && new_c < N &&
        board[new_r][new_c] != 0) {
      if (abs(board[new_r][new_c] - num) == 1) {
        return false;  // 相邻数字之差不能为1
      }
    }
  }
  return true;
}

// 回溯函数，返回合法的填充方案数
int backtrack(int r, int c, vector<int>& remaining) {
  if (r == N) return 1;  // 填满了整个3x3方格，返回一种合法填法
  if (c == N) return backtrack(r + 1, 0, remaining);  // 当前行填完，换到下一行
  if (board[r][c] != 0)
    return backtrack(r, c + 1, remaining);  // 已经填好的数字，跳过

  int count = 0;
  for (int i = 0; i < remaining.size(); i++) {
    int num = remaining[i];
    if (isValid(r, c, num)) {
      board[r][c] = num;                       // 填入数字
      remaining.erase(remaining.begin() + i);  // 将该数字移出待填数字
      count += backtrack(r, c + 1, remaining);  // 递归尝试下一个位置
      remaining.insert(remaining.begin() + i, num);  // 回溯
      board[r][c] = 0;                               // 撤销数字
    }
  }
  return count;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    vector<int> remaining;
    for (int i = 1; i <= SIZE; i++) remaining.push_back(i);  // 1到9的数字
    // 初始化棋盘并移除已填数字
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> board[i][j];
        if (board[i][j] != 0) {
          auto it = find(remaining.begin(), remaining.end(), board[i][j]);
          if (it != remaining.end()) {
            remaining.erase(it);  // 找到已填数字并移除
          }
        }
      }
    }

    // 检查初始状态的合法性
    bool invalid = false;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] != 0 && !isValid(i, j, board[i][j])) {
          invalid = true;  // 初始已填入数字不合法
        }
      }
    }

    // 如果初始状态不合法，直接输出0
    if (invalid) {
      cout << 0 << endl;
    } else {
      cout << backtrack(0, 0, remaining) << endl;  // 进行回溯搜索
    }
  }
  return 0;
}
