
// #include <iostream>
// #include <string>
// #include <vector>

// struct data {
//   int n;
//   std::vector<int> nums;
// };

// std::string solution(data d) {
//   int n = d.n;
//   std::vector<int> nums = d.nums;
//   if (n == 1) {
//     if (nums[0] == 0)
//       return "yes";
//     else
//       return "no";
//   }
//   for (auto& i : nums) {
//     if (i == 0) return "yes";
//   }

//   if (n == 2) {
//     if (nums[0] == nums[1]) return "yes";
//   }
//   return "no";
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
