// test.cpp
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Base {
 public:
  void traversal(T& t) {
    for (auto it = t.begin(); it != t.end(); ++it) {
      cout << *it << " ";
    }
    cout << endl;
  }
};

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  Base<vector<int>> b;
  b.traversal(v);

  return 0;
}
