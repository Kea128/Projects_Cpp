
// #include <iostream>
// #include <string>
// #include <vector>

// // 有n个数，要删除2个数，使得剩下的数的评价值和原来数相等
// // 组合问题：转化为 求 和==平均值*2 的两个数的组合有几个
// // 用回溯

// struct data {
//   int n;
//   std::vector<int> nums;
// };

// std::vector<int> path;
// float pathSum = 0;
// int result = 0;
// void dfs(int n, std::vector<int> nums, int startIndex, float target) {
//   if (path.size() == 2) {
//     if (std::abs(pathSum - target) < 0.1) {
//       result++;
//       return;
//     } else {
//       return;
//     }
//   }

//   for (int i = startIndex; i < n; ++i) {
//     path.emplace_back(nums[i]);
//     pathSum += nums[i];
//     dfs(n, nums, i + 1, target);
//     path.pop_back();
//     pathSum -= nums[i];
//   }
// }

// int solution(data d) {
//   int n = d.n;
//   std::vector<int> nums = d.nums;
//   float sum = 0;
//   for (int i = 0; i < n; ++i) {
//     sum += nums[i];
//   }
//   float target = sum * 2.0 / n;
//   path.clear();
//   pathSum = 0;
//   result = 0;
//   dfs(n, nums, 0, target);
//   return result;
// }

// int main(int argc, char const* argv[]) {
//   int t;
//   std::cin >> t;
//   int n;
//   std::vector<data> datas(t, data());
//   for (int i = 0; i < t; ++i) {
//     std::cin >> n;
//     datas[i].n = n;
//     for (int j = 0; j < n; ++j) {
//       int num;
//       std::cin >> num;
//       datas[i].nums.push_back(num);
//     }
//   }

//   for (int i = 0; i < t; i++) {
//     std::cout << solution(datas[i]) << std::endl;
//   }
//   return 0;
// }
