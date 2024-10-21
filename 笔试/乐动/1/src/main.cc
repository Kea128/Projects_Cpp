#include <stdio.h>
#include <string.h>

#include <iostream>

using namespace std;

#define N 1024

char* encrypt(char* str) {
  int i, len = strlen(str);
  for (i = 0; i < len; i++) {
    str[i] = (str[i] + i) % 128;
  }
  return str;
}

int main(int argc, char const* argv[]) {
  char s[N] = "I am good";
  printf("%s\n", encrypt(s));
  return 0;
}
