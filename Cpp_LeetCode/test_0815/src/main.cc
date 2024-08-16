#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 反转字符串
string reverseString(const string &s) {
  string reversed = s;
  reverse(reversed.begin(), reversed.end());
  return reversed;
}

// 逐位相乘两个大数
string multiply(const string &num1, const string &num2) {
  if (num1 == "0" || num2 == "0") return "0";

  // 反转两个数字字符串，以便从最低位开始乘
  string n1 = reverseString(num1);
  string n2 = reverseString(num2);

  vector<int> result(n1.size() + n2.size(), 0);

  // 逐位相乘
  for (size_t i = 0; i < n1.size(); ++i) {
    for (size_t j = 0; j < n2.size(); ++j) {
      result[i + j] += (n1[i] - '0') * (n2[j] - '0');
      // 进位处理
      result[i + j + 1] += result[i + j] / 10;
      result[i + j] %= 10;
    }
  }

  // 移除前导零
  size_t first_non_zero =
      find_if(result.begin(), result.end(), [](int x) { return x != 0; }) -
      result.begin();
  if (first_non_zero == result.size()) {
    return "0";  // 如果所有位都是0，则结果为0
  }

  // 转换结果为字符串
  string product;
  for (size_t i = first_non_zero; i < result.size(); ++i) {
    product += to_string(result[i]);
  }

  return product;
}

int main() {
  string num1, num2;
  cin >> num1 >> num2;

  string product = multiply(num1, num2);

  cout << product << endl;

  return 0;
}