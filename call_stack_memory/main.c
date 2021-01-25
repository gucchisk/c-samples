#include <stdio.h>
#include <limits.h>

void printstack(char* name, void* ptr, int size) {
  printf("%s >\naddr: %p\n", name, ptr);
  int mod = size % 16;
  char *chp = ptr;
  if (mod != 0) {
    chp = ptr - 16 + mod;
    size = size + 16 - mod;
  }

  for (int i = 0; i < size; i++) {
    if (i % 16 == 0) {
      printf("%p:  ", chp);
    }
    char ch = *chp++;
    printf("%02x ", ch & 0xff);
    if ((i + 1) % 16 == 0) {
      printf("\n");
    }
  }
  printf("\n");
}

long getframesize(void* ptr) {
  return (char *)__builtin_frame_address(1) - (char *)ptr;
}

void intlongint(int a, long b, int c) {
  long size = getframesize(&c);
  printf("size: %ld\n", size);
  printstack("intlonging", &c, size);
}

void intintlong(int a, int b, long c) {
  long size = getframesize(&c);
  printf("size: %ld\n", size);
  printstack("intintlong", &c, size);
}

void longintint(long a, int b, int c) {
  long size = getframesize(&c);
  printf("size: %ld\n", size);
  printstack("longintint", &c, size);
}

int main() {
  int a = 1;
  int b = 2;
  int c = 3;
  
  intlongint(a, b, c);
  intintlong(a, b, c);
  longintint(a, b, c);

  typedef void (*func)(int, int, int);
  func f = (func)&intlongint;
  f(a, b, c);
  
  return 0;
}

