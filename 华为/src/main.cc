// #include <algorithm>
// #include <iostream>
// #include <set>
// #include <sstream>
// #include <string>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>
// using namespace std;

// // struct Yilai {
// //   std::vector<int> rely;
// //   Yilai() : rely(std::vector<int>()){};
// // };
// int main() {
//   int N;
//   std::cin >> N;
//   std::vector<int> taskTime(N, 0);
//   for (int i = 0; i < N; i++) {
//     std::cin >> taskTime[i];
//   }

//   // std::vector<std::vector<int>> rely(N, std::vector<int>());
//   // int tmp;
//   // for (int i = 0; i < N; i++) {
//   //   while (std::getchar() != '\n') {
//   //     std::cin >> tmp;
//   //     rely[i].push_back(tmp);
//   //   }
//   // }

//   std::vector<std::vector<int>> rely(N, std::vector<int>());
//   std::cin.ignore();  // 忽略前一个输入后的换行符
//   std::string line;
//   for (int i = 0; i < N; i++) {
//     std::getline(std::cin, line);
//     std::istringstream iss(line);
//     int tmp;
//     while (iss >> tmp) {
//       rely[i].push_back(tmp);
//     }
//   }

//   // for (auto& i : rely) {
//   //   for (auto& j : i) {
//   //     std::cout << j << " ";
//   //   }
//   //   std::cout << std::endl;
//   // }

//   // solution

//   std::vector<int> taskState(N, 0);
//   int sumTime = 0;

//   while (std::find(taskState.begin(), taskState.end(), 0) != taskState.end())
//   {
//     int maxTime = 0;
//     for (int i = 0; i < N; i++) {
//       std::vector<int> rl = rely[i];
//       if (rl[0] == -1) {
//         taskState[i] = 1;
//         maxTime = std::max(taskTime[i], maxTime);
//       } else {
//         bool flag = true;
//         for (auto j : rl) {
//           if (taskState[j - 1] == 0) {
//             flag = false;
//             break;
//           }
//         }
//         if (flag) {
//           taskState[i] = 1;
//           maxTime = std::max(taskTime[i], maxTime);
//         }
//       }
//     }
//     sumTime += maxTime;
//   }

//   std::cout << sumTime << std::endl;
//   return 0;
// }

#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

int shortestDeployTime(int N, vector<int>& times,
                       vector<vector<int>>& dependencies) {
  vector<vector<int>> graph(N);
  vector<int> indegree(N, 0);

  for (int i = 0; i < N; ++i) {
    for (int dep : dependencies[i]) {
      graph[dep - 1].push_back(i);  // 减1是因为依赖编号从1开始
      indegree[i]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < N; ++i) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  vector<int> order;
  while (!q.empty()) {
    int step = q.front();
    q.pop();
    order.push_back(step);
    for (int next_step : graph[step]) {
      indegree[next_step]--;
      if (indegree[next_step] == 0) {
        q.push(next_step);
      }
    }
  }

  vector<int> dp(N, 0);
  for (int step : order) {
    int max_time = 0;
    for (int dep : dependencies[step]) {
      max_time = max(max_time, dp[dep - 1]);  // 同样减1
    }
    dp[step] = max_time + times[step];
  }

  return *max_element(dp.begin(), dp.end());
}

int main() {
  int N;
  cin >> N;
  vector<int> times(N);
  for (int i = 0; i < N; ++i) {
    cin >> times[i];
  }
  vector<vector<int>> dependencies(N);
  cin.ignore();  // 忽略前一个输入留下的换行符

  for (int i = 0; i < N; ++i) {
    string line;
    getline(cin, line);
    if (line == "-1") continue;  // 如果是"-1"，就说明该步骤没有依赖
    istringstream iss(line);
    int dep;
    while (iss >> dep) {
      dependencies[i].push_back(dep);
    }
  }

  int result = shortestDeployTime(N, times, dependencies);
  cout << result << endl;

  return 0;
}