#include <iostream>
#include <vector>

#include "stdio.h"
using namespace std;

struct node {
  int a;
  int b;
  int c;
};

int main(int argc, char const *argv[]) {
  struct node s = {3, 5, 6};
  struct node *pt = &s;
  printf("%d", *(int *)pt);
  return 0;
}
