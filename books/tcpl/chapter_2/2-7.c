/*
  Write a function invert(x,p,n) that returns x with the n bits that
  begin at position p inverted (i.e., 1 changed int 0 and vice versa),
  leaving the others unchanged.
*/

#include <stdio.h>

#define LEN 8

unsigned invert(unsigned x, int pos, int n);
unsigned getbits(unsigned x, int p, int n);

int main(void) {
  printf("%i\n", invert(0b11111111, 2, 3));
  return 0;
}

unsigned invert(unsigned x, int p, int n) {
  unsigned y = 0 << LEN;
  unsigned bits = getbits(x, p, n);
  y |= (bits << p);
  return x^y;
  // return x ^ (~(~0U << n) << p) // this uses two's complement
}


unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p+1-n)) & ~(~0 << n);
}
