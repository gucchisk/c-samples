#include <stdio.h>

int add(int a, int b, char* str) {
  printf("%s\n", str);
  fflush(stdout);
  return a + b;
}
