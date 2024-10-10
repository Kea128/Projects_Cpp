#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief 3162_优质数对的总和I
 * https://leetcode.cn/problems/find-the-number-of-good-pairs-i/description/
 */

int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
  int res = 0;
  for (int i = 0; i < nums1.size(); i++) {
    for (int j = 0; j < nums2.size(); j++) {
      if (nums1[i] % (nums2[j] * k) == 0) res++;
    }
  }
  return res;
}

int main() {
  int n;
  return 0;
}