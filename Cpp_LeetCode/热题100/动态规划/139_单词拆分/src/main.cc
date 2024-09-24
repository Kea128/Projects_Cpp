#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 * @brief 139_单词拆分
 * https://leetcode.cn/problems/word-break/description/?envType=study-plan-v2&envId=top-100-liked
 */

std::string path;
std::vector<std::string> res;
bool flag = false;

void dfs(string s, vector<string>& wordDict, int start) {
  if (flag == true) return;
  if (path.size() > s.size()) {
    return;
  }
  if (path.size() == s.size()) {
    if (path == s) {
      flag = true;
      return;
    } else {
      return;
    }
  }
  for (int i = 0; i < wordDict.size(); i++) {
    int size = wordDict[i].size();
    path += wordDict[i];
    dfs(s, wordDict, i);
    while (size--) path.pop_back();
  }
}

bool wordBreak(string s, vector<string>& wordDict) {
  dfs(s, wordDict, 0);
  return flag;
}

int main(int argc, char const* argv[]) {
  std::string s;
  std::cin >> s;
  std::vector<std::string> wordDict;
  std::string word;
  while (std::cin >> word) {
    wordDict.push_back(word);
  }

  std::cout << wordBreak(s, wordDict) << std::endl;

  return 0;
}
