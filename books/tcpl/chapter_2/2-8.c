#include <stdio.h>

unsigned rotr(unsigned x, unsigned n);

#define LEN 4

int main(void) {
  printf("%d\n", rotr(0b1000, 1)); // 0b0100
  return 0;
}

// rotate-right of a bitfield
unsigned rotr(unsigned x, unsigned n) {
  while (n--) {
    unsigned lsb = x & 1;
    x >>= 1;
    if (lsb) {
      x |= (1 << (LEN-1));
    }
  }
  return x;
}
