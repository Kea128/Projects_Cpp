#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

/**
 * @brief 3 无重复字符的最长子串
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/?envType=study-plan-v2&envId=top-100-liked
 */

/*
  //外层循环扩展右边界，内层循环扩展左边界
  for (int l = 0, r = 0 ; r < n ; r++) {
    //当前考虑的元素
    while (l <= r && check()) {//区间[left,right]不符合题意
          //扩展左边界
      }
      //区间[left,right]符合题意，统计相关信息
  }
*/

int lengthOfLongestSubstring(std::string s) {
  std::unordered_set<char> window;
  int maxNum = 0;
  int left = 0;
  int right = 0;
  for (; right < s.size(); right++) {
    while (window.find(s[right]) != window.end()) {
      window.erase(s[left]);
      left++;
    }
    window.insert(s[right]);
    maxNum = std::max((int)window.size(), maxNum);
  }
  return maxNum;
}

int main() {
  std::string str;
  while (true) {
    std::cin >> str;
    if (std::getchar() == '\n') break;
  }
  std::cout << str << std::endl;

  std::cout << "最长无重复子串: " << lengthOfLongestSubstring(str) << std::endl;
}