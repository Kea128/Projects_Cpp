#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief 移除链表元素
 */

/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:

输入: strs = [""]
输出: [[""]]
示例 3:

输入: strs = ["a"]
输出: [["a"]]
*/

std::vector<std::vector<std::string>> groupAnagrams(
    std::vector<std::string>& strs) {
  std::map<std::string, std::vector<std::string>> mp;
  for (std::string& str : strs) {
    std::string tmp = str;
    std::sort(tmp.begin(), tmp.end());
    mp[tmp].emplace_back(str);
  }
  std::vector<std::vector<std::string>> res;
  for (const std::pair<std::string, std::vector<std::string>>& p : mp) {
    res.emplace_back(p.second);
  }
  return res;
}

std::vector<std::string> strs;

void getKeyBoard_V1() {
  std::string input;

  while (true) {
    std::cin >> input;         // 读取一个单词
    strs.emplace_back(input);  // 将单词存入 vector

    char ch = std::getchar();  // 读取下一个字符（可能是空格或换行符）
    if (ch == '\n') {
      break;  // 如果遇到换行符，结束循环
    }
  }
}
void getKeyBoard_V2() {
  std::string input;
  std::getline(std::cin, input);  // 从键盘获取一整行输入

  std::stringstream ss(input);  // 使用 stringstream 进行字符串解析
  std::string word;

  while (ss >> word) {     // 以空格为分隔符提取单词
    strs.push_back(word);  // 将单词存入 vector 中
  }
}

int main() {
  getKeyBoard_V1();

  // 打印所有存储的字符串
  for (const auto& str : strs) {
    std::cout << str << std::endl;
  }

  return 0;
}