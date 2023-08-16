#include <stdio.h>

#define LEN 8
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned getbits(unsigned x, int p, int n);

int main(void) {
  printf("%i\n", setbits(0b10101111, 2, 3, 0b00110101));
  return 0;
}

// TODO: don't use loops or a len
unsigned setbits(unsigned x, int p, int n, unsigned y) {
	unsigned by = getbits(y, p, n);

	unsigned mask = 0;
	for (int i = 0; i < LEN; i += 1) {
		if (!(i >= p && i < (n+p)) && CHECK_BIT(x, i)) { 
			mask |= (1 << i); 
		}
	}

	return mask | (by << p);
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p+1-n)) & ~(~0 << n);
}
