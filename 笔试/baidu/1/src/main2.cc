// #include <algorithm>
// #include <iostream>
// #include <map>
// #include <set>
// #include <sstream>
// #include <vector>
// using namespace std;

// // 长度为n的字符串，下标1开始，执行n次操作，第i次操作将第i个字符移动到字符串末尾
// // string solution(std::string str) {
// //   int n = str.size();
// //   for (int i = 0; i < n; i++) {
// //     char c = str[i];
// //     str.erase(str.begin() + i);
// //     str.push_back(c);
// //   }
// //   return str;
// // }

// string solution(std::string str) {
//   int n = str.size();
//   std::vector<bool> strVec(2 * n, false);
//   for (int i = 0; i < 2 * n; i += 2) {
//     char c = str[i];
//     str.push_back(c);
//     strVec[i] = true;
//   }
//   string res;
//   for (int j = 0; j < 2 * n; j++) {
//     if(strVec[j] == 0) res += str[j]; 
//   }
//   return res;
// }

// int main(int argc, char const* argv[]) {
//   std::string str;
//   std::cin >> str;
//   std::cout << solution(str) << std::endl;
// }
