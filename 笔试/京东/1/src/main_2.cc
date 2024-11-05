// #include <algorithm>
// #include <iostream>
// #include <map>
// #include <set>
// #include <sstream>
// #include <vector>
// using namespace std;

// int main(int argc, char const* argv[]) {
//   int n, l, r;
//   std::cin >> n >> l >> r;
//   std::vector<int> nums(n, 0);
//   for (int i = 0; i < n; i++) {
//     std::cin >> nums[i];
//   }

//   int left = l, right = r;

//   if (nums.size() == 1) {
//     std::cout << right - left << std::endl;
//   } else {
//     for (int i = 0; i < n - 1; i++) {
//       if (nums[i] > nums[i + 1]) {
//         right = nums[i];
//       } else {
//         left = nums[i];
//       }
//     }
//     if (left >= right) {
//       std::cout << 0 << std::endl;
//     } else {
//       std::cout << right - left - 3 << std::endl;
//     }
//   }

//   return 0;
// }
