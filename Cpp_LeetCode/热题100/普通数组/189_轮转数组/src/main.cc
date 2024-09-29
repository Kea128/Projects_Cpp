#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief 189_轮转数组
 * https://leetcode.cn/problems/rotate-array/description/?envType=study-plan-v2&envId=top-100-liked
 */

void rotate(vector<int>& nums, int k) {
  k = k % nums.size();
  auto reserveNum = [&](int i, int j) {
    while (i < j) {
      swap(nums[i], nums[j]);
      i++;
      j--;
    }
  };
  reserveNum(0, nums.size() - 1);
  reserveNum(0, k - 1);
  reserveNum(k, nums.size() - 1);
}

int main() {
  int k = 2;
  vector<int> nums = {-1};
  rotate(nums, k);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}