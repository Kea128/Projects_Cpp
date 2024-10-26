// *** 题目描述 ***
/*
已知矿场可以划分成N*M的网格图，每个网格存在地形的差异，因此通过不同网格时，成本开销存在差。
网格有以下5种类型：
1、标志为'S'的网格为起点；
2、标志为'E'的网格为终点；
3、标志为'B'的网格为阻塞点，不允许通行；
4、标志为'C'的网格为检查点，矿车在运输路径中，至少需要进入一次检查点。
5、标志为'数字'的网格，其数字表示经过该网格的成本开销。
运输矿车只能上下左右4个方向运行，不允许斜对角进入其他网格。必要时可重复进入网格。请根据输入的网格图，寻求一条从S网格到E网格，并且至少经过一次检查点C的最低成本运输路径，并输出其成本开销。

输入：
第一行：网格图的行数N（3≤N≤200），和网格图的列数M（3≤M≤200），使用空格隔开。
第2行至第N行：网格图每一行的元素，可以为'S'、'E'、'B'、'C'或者数字（0≤数字≤100），且仅有一个'S'和一个'E'，同时存在一个或多个'C'，依次使用空格隔开。

输出：
第一行，输出运输最低成本开销。如果没有可达通路，请输出-1。

样例1：
输入：
3 3
S 4 5
7 B 3
C 9 E
输出：
16
提示：S->7->C->9->E

样例2：
输入：
3 4
12 B S 13
7 C 4 7
8 3 10 E
输出：
15
提示：S->4->C->4->7->E
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;      // 使用ll来表示长整型
typedef pair<ll, ll> pii;  // 使用pii来表示优先队列中的节点和距离对
string a[4][4];  // 输入的网格图存储在二维数组中，最多支持205行列
int b[100];  // 存储网格的数值类型或状态
// 用于邻接表存储边信息
int e[100];
int h[100];
int ne[100];
int w[100];

int dist[100];  // 最短路径开销数组
int st[100];    // 记录节点是否已确定最短路径
int idx;        // 记录当前边的编号
int n, m;       // 网格的行数（n）和列数（m）

// 添加边到邻接表函数
/*
l：边的起点一维索引。
r：边的终点一维索引。
c：边的权重。
idx：全局变量，表示当前边的编号，每添加一条新边时，idx 会自增。
*/
void add(int l, int r, int c) {
  e[idx] = r;  // 将边的终点 `r` 存入 e[idx]，表示从节点 `l` 指向节点 `r` 的边
  w[idx] = c;  // 将边的权重 `c` 存入 w[idx]，表示这条边的开销

  // 数组的每个元素 ne[i] 存储了节点 l 的下一条邻接边的索引，如果 i 是节点 l
  // 的最后一条边，那么 ne[i] 将被设置为 -1，表示链表的结束。

  ne[idx] = h[l];  // ne[idx]表示第idx条边的下一条边的索引

  // 将当前边的索引 idx 赋值给 h[l]，表示节点 l 的第一条边是当前添加的这条边。
  // 将 idx 自增，为下一条边的添加做准备。
  // 节点l的第一条边的是第idx条边

  h[l] = idx++;  //  h[l]表示第l个节点的第一条边的索引
}

// 将网格坐标(x, y)映射为一维表示
int ex(int x, int y) { return (x - 1) * m + y; }

int num(string s) {
  int k = 0;
  for (int i = 0; i < s.size(); i++) {
    k = k * 10 + (s[i] - '0');
  }
  return k;
}

int dijkstra(int s, int ee) {
  memset(dist, 0x3f, sizeof dist);
  dist[s] = 0;  // 起点 s 到自己的距离是 0
  // 定义一个优先队列 heap，用于存储节点和对应的最短路径开销。
  // pii 是 pair<int, int> 的别名，表示距离和节点的对。
  // greater<pii>表示优先队列按照距离的升序排列，即距离最小的节点在队列的顶部。
  priority_queue<pii, vector<pii>, greater<pii>> heap;
  heap.push({0, s});

  // 当优先队列不为空时，循环执行
  while (heap.size()) {
    // 取出队列顶部的元素，即当前距离最小的节点
    auto t = heap.top();
    heap.pop();

    // 获取节点 ver 和对应的距离 distance
    int ver = t.second, distance = t.first;
    // 如果节点 ver 已经被访问过，则跳过
    if (st[ver]) continue;
    // 标记节点 ver 为已访问
    st[ver] = true;
    // 遍历节点 ver 的所有邻接节点（遍历ver的边）
    for (int i = h[ver]; i != -1; i = ne[i]) {
      // 获取邻接节点 j
      int j = e[i];
      // 如果节点 j 的当前已知最短路径大于通过节点 ver 到达 j 的路径，则更新
      // dist[j]
      if (dist[j] > dist[ver] + w[i]) {
        dist[j] = dist[ver] + w[i];
        heap.push({dist[j], j});  // 将节点 j 和新的最短路径放入优先队列
      }
    }
  }
  // 重置 st 数组，为第二阶段重置所有节点的访问状态
  memset(st, 0, sizeof(st));
  // 如果节点 i 是检查点
  // C，则将其和对应的最短路径放入优先队列，为第二阶段做准备。
  for (int i = 1; i <= ex(n, m); i++) {
    if (b[i] == -2) heap.push({dist[i], i});
  }
  // 将非检查点的节点的最短路径设置为无穷大，第二阶段只考虑从检查点出发的路径。
  for (int i = 1; i <= ex(n, m); i++) {
    if (b[i] != -2) dist[i] = 0x3f3f3f3f;
  }
  while (heap.size()) {
    auto t = heap.top();
    heap.pop();

    int ver = t.second, distance = t.first;

    if (st[ver]) continue;
    st[ver] = true;
    for (int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dist[ver] + w[i]) {
        dist[j] = dist[ver] + w[i];
        heap.push({dist[j], j});
      }
    }
  }
  if (dist[ee] == 0x3f3f3f3f) return -1;
  return dist[ee];
}

int main() {
  // 初始化邻接表头节点
  // 当前所有节点都没有连接到其他节点
  memset(h, -1, sizeof(h));

  cin >> n >> m;
  int s, e;  // 记录起点和终点位置(一维编号)
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      int k = ex(i, j);  // 将坐标转换为一维编号
      // b[k]存储网格的数值类型或状态
      if (a[i][j] == "S") {
        b[k] = -4;
        s = k;
      } else if (a[i][j] == "B") {
        b[k] = -1;
      } else if (a[i][j] == "E") {
        b[k] = -3;
        e = k;
      } else if (a[i][j] == "C") {
        b[k] = -2;
      } else {
        b[k] = num(a[i][j]);
      }
    }
  }
  // 建立邻接表表示网格中的边
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      // i + 1 <= n：当前行不是最后一行，所以向下移动是可能的。
      // a[i][j] != "B"：当前格子不是阻塞点。
      // a[i + 1][j] != "B"：下一个格子也不是阻塞点。
      if (i + 1 <= n && a[i][j] != "B" && a[i + 1][j] != "B") {
        // 获取下一个格子的成本，如果成本是负数，则设置为0。
        int b1 = max(0, b[ex(i + 1, j)]);
        // 获取当前格子的成本，同样如果成本是负数，则设置为0。
        int b2 = max(0, b[ex(i, j)]);
        // add(l,r,c):将边(l,r)的权重设置为c
        add(ex(i, j), ex(i + 1, j), b1);
        add(ex(i + 1, j), ex(i, j), b2);
      }
      if (j + 1 <= m && a[i][j] != "B" && a[i][j + 1] != "B") {
        int b1 = max(0, b[ex(i, j + 1)]);
        int b2 = max(0, b[ex(i, j)]);
        add(ex(i, j), ex(i, j + 1), b1);
        add(ex(i, j + 1), ex(i, j), b2);
      }
    }
  }
  cout << dijkstra(s, e);
}
