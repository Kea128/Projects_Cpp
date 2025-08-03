#include <iostream>
#include <string>
using namespace std;

// // #1
// int main() {
//   string str = "D:\hello\world\test.text";
//   cout << str << endl;
//   string str1 = "D:\\hello\\world\\test.text";
//   cout << str1 << endl;
//   // 原始字面量
//   string str2 = R"(D:\hello\world\test.text)";
//   cout << str2 << endl;

//   return 0;
// }

// // #2
// int main() {
//   string str = R"(<html>
//         <head>
//         <title>
//         海贼王
//         </title>
//         </head>
//         <body>
//         <p>
//         我是要成为海贼王的男人!!!
//         </p>
//         </body>
//         </html>)";
//   cout << str << endl;
//   return 0;
// }

#include <iostream>
#include <string>
using namespace std;
int main() {
  string str1 = R"(D:\hello\world\test.text)";
  cout << str1 << endl;
  string str2 = R"luffy(D:\hello\world\test.text)luffy";
  cout << str2 << endl;
#if 0
  // 在R “xxx(raw string)xxx”
  // 中，原始字符串必须用括号（）括起来，括号的前后可以加其他字符串，所加的字符串会被忽略，并且加的字符串必须在括号两边同时出现
  // string str3 = R"luffy(D:\hello\world\test.text)robin";	//
  // 语法错误，编译不通过
  cout << str3 << endl;
#endif

  return 0;
}
