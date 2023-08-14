/* In a two's complement number system, x &= (x-1) deletes the rightmost
 * 1-bit in x. Explain why. Use this observation to write a faster
 * version of bitcount
*/

#include <stdio.h>

int fast_bitcount(unsigned x) {
  int result = 0;
  for (; x != 0; x &= (x-1)) {
      result += 1;
  }
  return result;
}

int main(void) {
  printf("%i\n", fast_bitcount(0b11000));
  return 0;
}
