#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main_iterator() {
  vector<int> vec(5, 0);
  cout << vec.size() << " " << vec.capacity() << endl;
  vec.emplace_back(0);
  cout << vec.size() << " " << vec.capacity() << endl;
  std::vector<int>::iterator it = vec.begin();
}