#include <iostream>
#include <set>
#include <vector>
using namespace std;

/**
 * @brief 88_合并两个有序数组
 * https://leetcode.cn/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
 */

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  std::vector<int> nums1_cp(nums1.begin(), nums1.end());
  int index1 = 0, index2 = 0;
  for (int i = 0; i < nums1.size(); i++) {
    if (index1 < m && index2 < n) {
      if (nums1_cp[index1] >= nums2[index2]) {
        nums1[i] = nums2[index2];
        index2++;
      } else if (nums1_cp[index1] < nums2[index2]) {
        nums1[i] = nums1_cp[index1];
        index1++;
      }
    } else if (index1 >= m && index2 < n) {
      nums1[i] = nums2[index2];
      index2++;
    } else if (index1 < m && index2 >= n) {
      nums1[i] = nums1_cp[index1];
      index1++;
    }
  }
}
int main(int argc, char const* argv[]) {
  std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;
  std::vector<int> nums2 = {2, 5, 6};
  int n = 3;
  merge(nums1, m, nums2, n);
  for (auto& i : nums1) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
