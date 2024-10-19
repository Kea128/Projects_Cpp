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
int backtrack(int r, int c) {
  if (r == N) return 1;  // 填满了整个3x3方格，返回一种合法填法
  if (c == N) return backtrack(r + 1, 0);  // 当前行填完，换到下一行
  if (board[r][c] != 0) return backtrack(r, c + 1);  // 已经填好的数字，跳过

  int count = 0;
  for (int num = 1; num <= SIZE; num++) {
    // 判断数字是否已在当前行、列中使用，并且放置后是否合法
    if (!row[r][num] && !col[c][num] && isValid(r, c, num)) {
      board[r][c] = num;                  // 填入数字
      row[r][num] = col[c][num] = true;   // 更新状态
      count += backtrack(r, c + 1);       // 递归尝试下一个位置
      board[r][c] = 0;                    // 回溯
      row[r][num] = col[c][num] = false;  // 撤销状态
    }
  }
  return count;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    // 初始化棋盘和状态
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> board[i][j];
      }
    }

    // 重置行、列使用的数字标记
    for (int i = 0; i < N; i++) {
      fill(row[i], row[i] + SIZE + 1, false);
      fill(col[i], col[i] + SIZE + 1, false);
    }

    // 标记已经使用的数字，并提前检查已填入数字是否合法
    bool invalid = false;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (board[i][j] != 0) {
          int num = board[i][j];
          row[i][num] = col[j][num] = true;
          if (!isValid(i, j, num)) invalid = true;  // 已填数字不合法
        }
      }
    }

    // 如果初始状态就不合法，直接输出0
    if (invalid) {
      cout << 0 << endl;
    } else {
      cout << backtrack(0, 0) << endl;  // 进行回溯搜索
    }
  }
  return 0;
}
