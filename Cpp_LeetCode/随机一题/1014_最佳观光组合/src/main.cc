#include <iostream>
#include <set>
#include <vector>
using namespace std;

/**
 * @brief 1014_最佳观光组合
 * https://leetcode.cn/problems/best-sightseeing-pair/
 */

// int maxScoreSightseeingPair(vector<int>& values) {
//   int ans = 0;
//   int left = 0;
//   int right = 1;
//   int maxScore = 0;
//   int curScore = 0;
//   for (int right = 1; right < values.size(); ++right) {
//     curScore = values[left] + values[right] + left - right;
//     maxScore = max(maxScore, curScore);
//     if (right < values.size() - 1) {
//       while (values[right + 1] - values[right] <= 1) {
//         if (right - left == 1) {
//           break;
//         }
//         if (left < right) {
//           left++;
//         }
//         curScore = values[left] + values[right] + left - right;
//         maxScore = max(maxScore, curScore);
//       }
//     } else {
//       while (left < right) {
//         curScore = values[left] + values[right] + left - right;
//         maxScore = max(maxScore, curScore);
//         left++;
//       }
//     }
//   }
//   return maxScore;
// }

int maxScoreSightseeingPair(vector<int>& values) {
  int left = 0;
  int right = 1;
  int maxleft = 0;
  for (; right < values.size(); ++right) {
  }
}

int main(int argc, char const* argv[]) {
  int tmp;
  std::vector<int> values;
  while (std::cin >> tmp) {
    values.push_back(tmp);
  }
  std::cout << maxScoreSightseeingPair(values) << std::endl;
  return 0;
}
