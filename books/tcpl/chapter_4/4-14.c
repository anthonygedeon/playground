#include <stdio.h>

#define swap(t, x, y) \
	do {			  \
		t = x;		  \
		x = y;        \
		y = t;		  \
	} while(0);       \


int main(void) {
	int t;
	int a = 5;
	int b = 3;
	swap(t, a, b);
	printf("%d %d\n", a, b);
}
