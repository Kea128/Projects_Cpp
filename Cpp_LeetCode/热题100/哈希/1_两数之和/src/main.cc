#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  std::unordered_map<int, int> mp;
  for (int i = 0; i < nums.size(); i++) {
    mp.insert({target - nums[i], i});
    auto it = mp.find(nums[i]);
    if (it != mp.end()) {
      return {it->second, i};
    }
  }
  return {};
}