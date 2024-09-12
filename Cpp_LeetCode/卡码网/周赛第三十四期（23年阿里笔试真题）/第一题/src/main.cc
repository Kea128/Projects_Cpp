#include <iostream>
#include <map>
#include <vector>

int solution(std::vector<int>& nums) {
  std::map<int, int> mp;
  for (int i = 0; i < nums.size(); i++) {
    mp[nums[i]]++;
  }
  int count = 0;
  int a = std::min(std::min(mp[1], mp[6]), mp[3]);
  count += a;
  mp[1] -= a;
  mp[3] -= a;
  mp[6] -= a;
  // if (mp[1] == 0 || mp[3] == 0 || mp[6] == 0) {
  //   return count;
  // }
  int b = std::min(std::min(mp[1], mp[2]), mp[4]);
  count += b;
  mp[1] -= b;
  mp[2] -= b;
  mp[4] -= b;
  // if (mp[1] == 0 || mp[2] == 0 || mp[4] == 0) {
  //   return count;
  // }
  int c = std::min(std::min(mp[1], mp[2]), mp[6]);
  count += c;
  mp[1] -= c;
  mp[2] -= c;
  mp[6] -= c;
  return count;
}

int main(int argc, char const* argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> nums;
  int tmp;
  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    nums.emplace_back(tmp);
  }

  std::cout << solution(nums) << std::endl;

  return 0;
}
