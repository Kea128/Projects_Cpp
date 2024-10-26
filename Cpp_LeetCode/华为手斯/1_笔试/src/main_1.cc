// #include <algorithm>
// #include <climits>
// #include <iostream>
// #include <sstream>
// #include <vector>
// using namespace std;

// void input(std::vector<int>& nums) {
//   std::string str;
//   std::getline(std::cin, str);
//   std::stringstream ss(str);
//   int num;
//   while (ss >> num) {
//     nums.emplace_back(num);
//   }
// }

// std::vector<int> solution(std::vector<int>& nums1, std::vector<int>& nums2) {
//   std::vector<int> res;
//   //
//   dp[i][j]表示以i-1下标结尾的nums1和以j-1下标为结尾的nums2的最长子数组的长度
//   std::vector<std::vector<int>> dp(nums1.size() + 1,
//                                    std::vector<int>(nums2.size() + 1, 0));
//   int maxLength = 0;
//   int x = 0;
//   int y = 0;
//   for (int i = 1; i <= nums1.size(); i++) {
//     for (int j = 1; j <= nums2.size(); j++) {
//       if (nums1[i - 1] == nums2[j - 1]) {
//         dp[i][j] = dp[i - 1][j - 1] + 1;
//       }
//       if (dp[i][j] > maxLength) {
//         maxLength = dp[i][j];
//         x = i - 1;
//         y = j - 1;
//       }
//     }
//   }

//   // for (auto& m : dp) {
//   //   for (auto& n : m) {
//   //     std::cout << n << " ";
//   //   }
//   //   std::cout << std::endl;
//   // }

//   return maxLength == 0 ? std::vector<int>{-1}
//                         : std::vector<int>(nums1.begin() + x - maxLength + 1,
//                                            nums1.begin() + x + 1);
// }

// std::vector<int> solution2(std::vector<int>& nums1, std::vector<int>& nums2)
// {
//   int n = nums1.size();
//   int m = nums2.size();
//   int len = 0;
//   int st = 0;
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       int k = 0;
//       while (i + k < n && j + k < m && nums1[i + k] == nums2[j + k]) {
//         k++;
//       }
//       if (k > len) {
//         len = k;
//         st = i;
//       }
//     }
//   }
//   if (len == 0) {
//     return {-1};
//   } else {
//     return std::vector<int>(nums1.begin() + st, nums1.begin() + st + len);
//   }
// }

// int main(int argc, char const* argv[]) {
//   int n = 2;
//   std::vector<int> nums1;
//   std::vector<int> nums2;
//   input(nums1);
//   input(nums2);
//   //   auto res = solution(nums1, nums2);
//   auto res = solution2(nums1, nums2);

//   for (auto& i : res) {
//     std::cout << i << " ";
//   }
// }
